#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

int int_cmp(const void *l, const void *r);
int allocate_int_array(size_t len, int **pb, int **pe);
void free_int_array(int **pb);

int file_count_int_array_elements(FILE *f_i, size_t *len);
int file_read_int_array(FILE *f_i, const int *pb, const int *pe);
double count_avg_array(const int *pb_src, const int *pe_src);
void file_write_int_array(FILE *f_o, const int *pb, const int *pe);

#endif //ARRAY_H
