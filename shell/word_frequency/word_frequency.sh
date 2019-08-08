#!/bin/bash
# Read from the file words.txt and output the word frequency list to stdout.

declare -A words_count

for w in $(cat words.txt);do
  words_count[$w]=$(( ${words_count[$w]:-0} + 1 )) # like arr[key]++
done

for w in ${!words_count[*]};do  # w is key
  echo $w ${words_count[$w]}
done | sort -rnk 2
