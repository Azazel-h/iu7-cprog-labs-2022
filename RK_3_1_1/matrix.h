#ifndef MATRIX_H
#define MATRIX_H

#include "errors.h"
#include <stdio.h>

#define N 10

int read_sq_matrix_file(FILE *f_i, int arr[][N], size_t *n, size_t *m);
void find_min_under_maind(int arr[][N], size_t n, int *result);

#endif // MATRIX_H
