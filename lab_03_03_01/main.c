#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>


#define N 10
#define OK 0
#define INPUT_ERROR -11
#define OUTPUT_ERROR -12
#define SIZE_ERROR -13
#define SIZE_INPUT_ERROR -14


int read_matrix(int matrix[][N], size_t *n, size_t *m);
int compare_two_arrays_by_max(int *first, int *second, size_t len);
int maximum(int *arr, size_t len);

void matrix_bubble_sort(int matrix[][N], size_t n, size_t m, int (*compare)(int *, int *, size_t));
void swap_rows(int matrix[][N], size_t first_index, size_t second_index, size_t m);
void print_matrix(int matrix[][N], size_t n, size_t m);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    int matrix[N][N];
    size_t n, m;

    if ((status_code = read_matrix(matrix, &n, &m)))
        get_errors(status_code);
    else
    {
        matrix_bubble_sort(matrix, n, m, compare_two_arrays_by_max);
        print_matrix(matrix, n, m);
    }
    return status_code;
}


void matrix_bubble_sort(int matrix[][N], size_t n, size_t m, int (*compare)(int *, int *, size_t))
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n - i - 1; ++j)
        {
            if (!compare(matrix[j], matrix[j + 1], m))
                swap_rows(matrix, j, j + 1, m);
        }
}


int read_matrix(int matrix[][N], size_t *n, size_t *m)
{
    int status_code = OK;
    if (scanf("%zu%zu", n, m) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((*n < 1 || *n > N) || (*m < 1 || *m > N))
        status_code = SIZE_ERROR;
    else
    {
        for (size_t i = 0; i < *n && status_code == OK; ++i)
        {
            for (size_t j = 0; j < *m && status_code == OK; ++j)
            {
                if (scanf("%d", *(matrix + i) + j) != 1)
                {
                    status_code = INPUT_ERROR;
                }
            }
        }
    }
    return status_code;
}


void print_matrix(int matrix[][N], size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void swap_rows(int matrix[][N], size_t first_index, size_t second_index, size_t m)
{
    int temp;
    for (size_t i = 0; i < m; ++i)
    {
        temp = matrix[first_index][i];
        matrix[first_index][i] = matrix[second_index][i];
        matrix[second_index][i] = temp;
    }
}


int maximum(int *arr, size_t len)
{
    int max_n = *arr, new;
    for (size_t i = 0; i < len; ++i)
    {
        new = arr[i];
        if (new > max_n)
            max_n = new;
    }
    return max_n;
}


int compare_two_arrays_by_max(int *first, int *second, size_t len)
{
    int first_max = maximum(first, len);
    int second_max = maximum(second, len);
    int is_greater = false;

    if (first_max > second_max)
        is_greater = true;
    return is_greater;
}



void get_errors(int status_code)
{
    switch (status_code)
    {
        case INPUT_ERROR:
            printf("ERROR: Bad input\n");
            break;
        case SIZE_ERROR:
            printf("ERROR: Bad matrix size\n");
            break;
        case OUTPUT_ERROR:
            printf("ERROR: Bad output size\n");
            break;
        case SIZE_INPUT_ERROR:
            printf("ERROR: Bad input size\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
