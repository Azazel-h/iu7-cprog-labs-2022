#!/bin/bash

file_in=$1
file_out=$2
_args=$3
memory_error=0

if [[ (! -f "$file_in") || (! -f "$file_out") ]]; then
  exit 100
fi

if [[ -n "$USE_VALGRIND" ]]; then

    (cd "../.." ; valgrind -q --leak-check=full --track-origins=yes --log-file="out/valgrind_pos.temp" "./app.exe" $_args > "func_tests/scripts/real_out.txt")
    main_status_code=$?

    if [[ -s "../../out/valgrind_pos.temp" ]]; then
        cat "../../out/valgrind_pos.temp"
        memory_error=1
    fi
else
    # shellcheck disable=SC2086
    (cd "../.." ; ./app.exe $_args > "func_tests/scripts/real_out.txt")
    main_status_code=$?
fi

./comparator.sh "real_out.txt" "$file_out"
compare_status_code=$?

if [[ $main_status_code == 0 ]]; then
  if [[ $compare_status_code == 0 ]]; then
      if [[ $memory_error == 0 ]]; then
          exit 0
      else
          exit 101
      fi
  else
      if [[ $memory_error == 0 ]]; then
          exit 102
      else
          exit 103
      fi
  fi
else
  exit $main_status_code
fi
