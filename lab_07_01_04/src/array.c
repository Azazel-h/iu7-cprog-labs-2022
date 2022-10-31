#include "errors.h"
#include "array.h"


int int_cmp(const void *l, const void *r)
{
    int *l_a = (int *) l;
    int *r_b = (int *) r;
    return *l_a - *r_b;
}


double count_avg_array(const int *pb_src, const int *pe_src)
{
    double sum = 0;
    size_t len = 0;
    while (pb_src < pe_src)
    {
        sum += *(pb_src++);
        len++;
    }
    return sum / (double) len;
}


int allocate_int_array(const size_t len, int **pb, int **pe)
{
    int rc = OK;
    if (len > 0)
    {
        *pb = malloc(len * sizeof(int));
        if (*pb == NULL)
            rc = ERR_ALLOCATION;
        else
            *pe = *pb + len;
    }
    else
        rc = ERR_ARR_LEN;

    return rc;
}


void free_int_array(int **pb)
{
    free(*pb);
    *pb = NULL;
}


int file_count_int_array_elements(FILE *f_i, size_t *len)
{
    int rc = OK;

    int tmp;
    while (fscanf(f_i, "%d", &tmp) == 1)
        (*len)++;

    if (!feof(f_i))
        rc = ERR_DATA;

    return rc;
}


int file_read_int_array(FILE *f_i, const int *pb, const int *pe)
{
    int rc = OK;

    int *pa = (int *) pb;
    while (!rc && pa < pe)
    {
        if (fscanf(f_i, "%d", pa) != 1)
            rc = ERR_DATA;
        pa++;
    }

    return rc;
}


void file_write_int_array(FILE *f_o, const int *pb, const int *pe)
{
    while (pb < pe - 1)
        fprintf(f_o, "%d ", *(pb++));
    fprintf(f_o, "%d\n", *pb);
}
