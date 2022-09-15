#ifndef LAB_05_02_00_H
#define LAB_05_02_00_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define OK 0
#define INPUT_ERROR 1
#define EMPTY_ERROR 1
#define F_NAME_POSITION 1
#define CORRECT_INPUT 1
#define ARGC_COUNTER 2
#define ARGC_ERROR 2


void get_sum(FILE *f, float *sum, size_t *len);
void closest_avg(FILE *f, float avg);

#endif //LAB_05_02_00_H
