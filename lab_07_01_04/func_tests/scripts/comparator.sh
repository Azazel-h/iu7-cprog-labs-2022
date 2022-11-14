#!/bin/bash

file_in=$1
file_out=$2

if [[ (! -f "$file_in") || (! -f "$file_out") ]]; then
  exit 1
fi

output="$(<"$file_in")"
new_output="$(<"$file_out")"

if [ -z "$(diff "$file_in" "$file_out")" ]; then
  exit 0
else
  printf "\e[0;33m---YOURS/CORRECT----\e[0;0m\n"
  diff -y "$file_in" "$file_out"
  printf "\e[0;33m--------------------\e[0;0m\n"
  exit 1
fi