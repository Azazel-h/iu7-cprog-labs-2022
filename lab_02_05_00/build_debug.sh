#!/bin/bash

gcc -std=c99 -c main.c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla

gcc -o app.exe main.o -lm