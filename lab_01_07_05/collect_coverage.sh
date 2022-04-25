#!/bin/bash

gcc -fprofile-arcs -ftest-coverage main.c -o main.o
cd func_tests/scripts/ || exit
./func_tests.sh
cd ../../
gcov main.c