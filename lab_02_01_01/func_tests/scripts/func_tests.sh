#!/bin/bash

fails=0

num=1
echo "----POSITIVE-----"
while [[ -f "../data/pos_$(printf "%02d" $num)_in.txt" ]]; do
  file_in="../data/pos_$(printf "%02d" $num)_in.txt"
  file_out="../data/pos_$(printf "%02d" $num)_out.txt"
  file_args="../data/pos_$(printf "%02d" $num)_args.txt"
  args=""

  if [[ -f $file_args ]]; then
    args=$(cat "$file_args")
  fi

  ./pos_case.sh "$file_in" "$file_out" "$args"
  status_code=$?

  if [[ $status_code == 0 ]]; then
    printf "SUCCESS | Test №%s\n" $num
  else
    printf "FAILED  | Test №%s\n" $num
    fails=$((fails + 1))
  fi

  num=$((num + 1))
done

num=1
echo "----NEGATIVE-----"
while [[ -f "../data/neg_$(printf "%02d" $num)_in.txt" ]]; do
  file_in="../data/neg_$(printf "%02d" $num)_in.txt"
  file_args="../data/neg_$(printf "%02d" $num)_args.txt"
  args=""

  if [[ -f $file_args ]]; then
    args=$(cat "$file_args")
  fi

  ./neg_case.sh "$file_in" "$args"
  status_code=$?

  if [[ $status_code != 0 ]]; then
    printf "SUCCESS | Test №%s\n" $num
  else
    printf "FAILED  | Test №%s\n" $num
    fails=$((fails + 1))
  fi

  num=$((num + 1))
done

exit $fails