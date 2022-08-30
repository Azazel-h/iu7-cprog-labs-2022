#!/bin/bash

file_in=$1
_args=$3
memory_error=0

if [[ (! -f "$file_in") ]]; then
  exit 100
fi

if [[ -n "$USE_VALGRIND" ]]; then
    valgrind --log-file=../data/valgrind_pos.temp -q "../../app.exe" < "$file_in" > "real_out.txt" "$_args"
    status_code=$?
    if [[ -s "valgrind_pos.temp" ]]; then
        memory_error=1
    fi
else
    (../../app.exe "$_args" > "real_out.txt") < "$file_in"
    status_code=$?
fi


if [[ $status_code == 0 ]]; then
    if [[ $memory_error == 0 ]]; then
        exit 0
    else
        exit 1
    fi
else
    if [[ $memory_error == 0 ]]; then
        exit 2
    else
        exit 3
    fi
fi