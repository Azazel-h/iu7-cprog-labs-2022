#ifndef LAB_05_03_H
#define LAB_05_03_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define OK 0
#define INPUT_ERROR 1
#define CORRECT_INPUT 1
#define INVALID_ARGC_N 2
#define FILE_ERROR 3
#define INDEX_ERROR 4
#define VALUE_ERROR 5
#define WRITE_ERROR 6
#define PROCESS_ERROR 6

#define MODE_POSITION 1
#define COUNT_POSITION 2
#define MAX 10
#define ARGC_COUNTER 4


int validate_f_size(FILE *f);
void print_nums(FILE *f);
int add_num(FILE *f, size_t count);
int put_number_by_pos(FILE *f, long index, int *num);
int get_number_by_pos(FILE *f, long index, int *num);
int bubbles_sort(FILE *f);

#endif //LAB_05_03_H
