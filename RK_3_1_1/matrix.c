#include "matrix.h"


bool is_matrix_sq(size_t n, size_t m)
{
    return n == m;
}


int allocate_matrix(size_t n, size_t m, int ***matrix_ptrs)
{
    int rc = OK;

    if (n > 0 && m > 0)
    {
        *matrix_ptrs = calloc(n, sizeof(int *));
        if (*matrix_ptrs != NULL)
        {
            for (size_t i = 0; rc == OK && i < n; ++i)
            {
                if (((*matrix_ptrs)[i] = malloc(m * sizeof(int))) == NULL)
                {
                    free_matrix(*matrix_ptrs, n);
                    rc = ALLOCATION_ERR;
                }
            }
        }
        else
            rc = ALLOCATION_ERR;
    }
    else
        rc = NULL_LEN_ERR;

    return rc;
}


void free_matrix(int **matrix_ptrs, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free(matrix_ptrs[i]);

    free(matrix_ptrs);
}


int read_matrix_file(FILE *f_i, int ***matrix, size_t *n, size_t *m)
{
    int rc = OK;
    if (fscanf(f_i, "%lu%lu", n, m) == 2)
    {
        if ((rc = allocate_matrix(*n, *m, matrix)) == OK)
        {
            for (size_t i = 0; rc == OK && i < *n; ++i)
                for (size_t j = 0; rc == OK && j < *m; ++j)
                {
                    if (fscanf(f_i, "%d", (*matrix)[i] + j) != 1)
                        rc = MATRIX_INP_ERR;
                }
        }
    } 
    else
        rc = LEN_INP_ERR;

    return rc;
}


int find_min_odd_under_maind_sq(int **matrix, size_t n, int *result)
{
    int rc = OK;
    bool was_odd = false;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < i; ++j)
        {
            if (matrix[i][j] % 2 != 0)
            {
                if (!was_odd)
                {
                    *result = matrix[i][j];
                    was_odd = true;
                }
                else if (matrix[i][j] < *result)
                    *result = matrix[i][j];
            }
        }

    if (!was_odd)
        rc = NOT_FOUND_ERR;

    return rc;
}
