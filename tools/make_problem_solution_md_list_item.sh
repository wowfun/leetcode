#!/bin/bash

num="$1"
problem_name="$2"
solution_lang="$3"
difficulty="$4"
# tags="$5"

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
fi

problem_url=$problem_url_head`echo "$problem" | sed 's/[^[:alnum:] ]//g' | sed 's/ /-/g'`/
# echo $problem_url
solution_url=$solution_url_head`echo "$problem" | sed 's/[^[:alnum:] ]//g' | sed 's/ /_/g'`

echo "| $num | [${problem_name}](${problem_url}) | [${solution_lang}](${solution_url}) | $difficulty | "