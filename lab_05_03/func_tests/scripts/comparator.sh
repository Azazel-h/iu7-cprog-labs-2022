#!/bin/bash

file_in=$1
file_out=$2

if [[ (! -f "$file_in") || (! -f "$file_out") ]]; then
  exit 1
fi

output="$(sed "s|Result: ||g" "$file_in" | xargs)"
new_output="$(<"$file_out")"

if [[ "$output" == "$new_output" ]]; then
  exit 0
else
  exit 1
fi