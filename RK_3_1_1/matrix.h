#ifndef MATRIX_H
#define MATRIX_H

#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

bool is_matrix_sq(size_t n, size_t m);
void free_matrix(int **matrix_ptrs, size_t n);
int allocate_matrix(size_t n, size_t m, int ***matrix_ptrs);
int read_matrix_file(FILE *f_i, int ***matrix, size_t *n, size_t *m);
int find_min_odd_under_maind_sq(int **matrix, size_t n, int *result);

#endif // MATRIX_H
