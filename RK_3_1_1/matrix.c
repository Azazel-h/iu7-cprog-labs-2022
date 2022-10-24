#include "matrix.h"

int read_sq_matrix_file(FILE *f_i, int arr[][N], size_t *n, size_t *m)
{
    int rc = OK;
    if (fscanf(f_i, "%lu%lu", n, m) == 2)
    {
        if (n == m && (n != 0 && m != 0))
        {
            for (size_t i = 0; rc == OK && i < *n; ++i)
                for (size_t j = 0; rc == OK && j < *m; ++j)
                {
                    if (fscanf(f_i, "%d", &(arr[i][j])) != 1)
                        rc = MATRIX_INP_ERR;
                }
        }
        else
            rc = NOT_SQ_ERR;
    } 
    else
        rc = LEN_INP_ERR;

    return rc;
}


void find_min_under_maind(int arr[][N], size_t n, int *result)
{
    *result = arr[0][0];
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < i; ++j)
        {
            if (j % 2 != 0 && arr[i][j] < *result)
                *result = arr[i][j];
        }
}
