#!/bin/bash

num="$1"
problem_name="$2"
solution_lang="$3"
difficulty="$4"
# tags

if [[ "$solution_lang" = "j" ]];then
  solution_lang="Java"
elif [[ "$solution_lang" = "c" ]];then
  solution_lang="C++"
elif [[ "$solution_lang" = "p" ]];then
  solution_lang="Python"
elif [[ "$solution_lang" = "s" ]];then
  solution_lang="Shell"
fi

problem=`echo "$problem_name" | sed 's/[A-Z]/\l&/g' | sed 's/[^[:alnum:] ]//g' | sed 's/ /_/g'`
lang=`echo "$solution_lang" | sed 's/[A-Z]/\l&/g'`

problem_url_head="https://leetcode.com/problems/"
problem_url=$problem_url_head`echo "$problem" | sed 's/-/_/g'`/

make_flag=1
solution_url_head="algorithms/$lang/"
if [[ "$lang" = "java" ]];then
  solution_url_head="algorithms/java/src/"
  solution_src_file="Solution.java"
  test_src_file="Test.java"
elif [[ "$lang" = "c++" ]];then
  solution_src_file="solution.cpp"
  test_src_file="test.cpp"
elif [[ "$lang" = "python" ]];then
  solution_src_file="solution.py"
  test_src_file="test.py"
elif [[ "$lang" = "shell" ]];then
  solution_url_head="shell/"
  solution_src_file=$problem.sh
else
  make_flag=0
  echo 'ERROR: no surported src type to make file'
fi

solution_url=${solution_url_head}"${problem}"

# make solution dir and src
if [[ $make_flag -eq 1 ]];then
  cd `dirname $0`
  mkdir -p ../${solution_url}
  touch ../${solution_url}/${solution_src_file}
  touch ../${solution_url}/${test_src_file}
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

echo "| $num | [${problem_name}](${problem_url}) | [${solution_lang}](${solution_url}) | $difficulty | "