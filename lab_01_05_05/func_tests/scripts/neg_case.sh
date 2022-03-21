#!/bin/bash

file_in=$1
file_out=$2
file_args=$3

if [[ (! -f "$file_in") || (! -f "$file_out") ]]; then
  exit 1
fi

(../../main.o "$file_args" > "real_out.txt") < "$file_in"

exit $?