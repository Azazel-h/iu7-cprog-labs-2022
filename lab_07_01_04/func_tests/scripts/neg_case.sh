#!/bin/bash

file_in=$1
_args=$2
memory_error=0

if [[ (! -f "$file_in") ]]; then
  exit 100
fi

if [[ -n "$USE_VALGRIND" ]]; then
    (cd "../.." ; valgrind -q --leak-check=full --track-origins=yes --log-file="out/valgrind_neg.temp" "./app.exe" $_args > "func_tests/scripts/real_out.txt")
    main_status_code=$?

    if [[ -s "../../out/valgrind_neg.temp" ]]; then
        memory_error=1
        cat "../../out/valgrind_neg.temp"
    fi
else
    # shellcheck disable=SC2086
    (cd "../.." ; ./app.exe $_args > "func_tests/scripts/real_out.txt")
    main_status_code=$?
fi


if [[ $main_status_code == 0 ]]; then
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