#!/bin/bash

for file in *.exe *.o *.gcda *.gcno *.gcov real_out.txt; do
    find . -name "$file" -delete
done