#!/bin/bash

file_in=$1
file_out=$2

if [[ (! -f "$file_in") || (! -f "$file_out") ]]; then
  exit 1
fi

output="$(grep -Eo "(-?)([0-9]+)(\.[0-9]+)?" "$file_in")"
expected_output=$(< "$file_out")


if [[ "$output" == "$expected_output" ]]; then
  exit 0
else
  exit 1
fi