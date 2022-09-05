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

void print_matrix(int matrix[][N], size_t n, size_t m);
void task_swap_process(int main_matrix[][N], size_t n, size_t m);
void swap_elements(int *first, int *second);
void swap_elements_in_range(size_t start, size_t end, int *first, int *second);
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
        task_swap_process(matrix, n, m);
        print_matrix(matrix, n, m);
    }
    return status_code;
}


int read_matrix(int matrix[][N], size_t *n, size_t *m)
{
    int status_code = OK;
    if (scanf("%zu%zu", n, m) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((*n < 1 || *n > N) ||
        (*m < 1 || *m > N) ||
        (*n != *m))
        status_code = SIZE_ERROR;
    else
    {
        for (size_t i = 0; i < *n; ++i)
        {
            for (size_t j = 0; j < *m; ++j)
            {
                if (scanf("%d", *(matrix + i) + j) != 1)
                {
                    status_code = INPUT_ERROR;
                    break;
                }
            }
        }
    }
    return status_code;
}


void task_swap_process(int main_matrix[][N], size_t n, size_t m)
{
    int *first, *second;
    for (size_t i = 0; i < n / 2; ++i)
    {
        first = main_matrix[i];
        second = main_matrix[n - i - 1];

        swap_elements_in_range(i, m - i, first, second);
    }
}


void swap_elements_in_range(size_t start, size_t end, int *first, int *second)
{
    for (size_t i = start; i < end; ++i)
    {
        swap_elements(first + i, second + i);
    }
}


void swap_elements(int *first, int *second)
{
    int temp_ = *second;
    *second = *first;
    *first = temp_;
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
