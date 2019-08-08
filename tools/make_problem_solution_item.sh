#!/bin/bash

num="$1"
problem_name="$2"
solution_lang="$3"
difficulty="$4"
# tags="$5"

if [[ "$solution_lang" = "j" ]];then
  solution_lang="Java"
elif [[ "$solution_lang" = "c" ]];then
  solution_lang="C++"
elif [[ "$solution_lang" = "p" ]];then
  solution_lang="Python"
fi

problem=`echo "$problem_name" | sed 's/[A-Z]/\l&/g'`
lang=`echo "$solution_lang" | sed 's/[A-Z]/\l&/g'`

problem_url_head="https://leetcode.com/problems/"
if [[ "$lang" = "java" ]];then
  solution_url_head="algorithms/java/src/"
elif [[ "$lang" = "c++" ]];then
  solution_url_head="algorithms/cpp/"
else
  solution_url_head="algorithms/$lang/"
fi

if [[ "$difficulty" = "e" || "$difficulty" = "E" ]];then
  difficulty="Easy"
elif [[ "$difficulty" = "m" || "$difficulty" = "M" ]];then
  difficulty="Medium"
elif [[ "$difficulty" = "h" || "$difficulty" = "H" ]];then
  difficulty="Hard"
else 
  echo ERROR: no surported difficulty
fi

problem_url=$problem_url_head`echo "$problem" | sed 's/[^[:alnum:] ]//g' | sed 's/ /-/g'`/
# echo $problem_url
solution_url=$solution_url_head`echo "$problem" | sed 's/[^[:alnum:] ]//g' | sed 's/ /_/g'`

# make solution dir and src
make_flag=1
if [[ "$lang" = "java" ]];then
  solution_src_file="Solution.java"
  test_src_file="Test.java"
elif [[ "$lang" = "c++" ]];then
  solution_src_file="solution.cpp"
  test_src_file="test.cpp"
elif [[ "$lang" = "python" ]];then
  solution_src_file="solution.py"
  test_src_file="test.py"
else
  echo no surported src type
  make_flag=0
fi

if [[ $make_flag -eq 1 ]];then
  cd `dirname $0`
  mkdir -p ../${solution_url}
  touch ../${solution_url}/${solution_src_file}
  touch ../${solution_url}/${test_src_file}
fi

echo "| $num | [${problem_name}](${problem_url}) | [${solution_lang}](${solution_url}) | $difficulty | "