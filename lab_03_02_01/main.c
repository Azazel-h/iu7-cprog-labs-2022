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
int sum_of_digits(int number);
int refactor_matrix(int matrix[][N], size_t *n, size_t *m);

void print_matrix(int matrix[][N], size_t n, size_t m);
void find_first_sod_min(int matrix[][N], size_t n, size_t m, size_t *sod_row, size_t *sod_column);
void delete_row(int matrix[][N], size_t *n, size_t m, size_t row_to_delete);
void delete_column(int matrix[][N], size_t n, size_t *m, size_t column_to_delete);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    int matrix[N][N];
    size_t n, m;

    if ((status_code = read_matrix(matrix, &n, &m)) || (status_code = refactor_matrix(matrix, &n, &m)))
        get_errors(status_code);
    else
    {
        print_matrix(matrix, n, m);
    }
    return status_code;
}


int read_matrix(int matrix[][N], size_t *n, size_t *m)
{
    int status_code = OK;
    if (scanf("%zu%zu", n, m) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((*n < 2 || *n > N) || (*m < 2 || *m > N))
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


int sum_of_digits(int number)
{
    int sum = 0;
    number = abs(number);

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


void delete_row(int matrix[][N], size_t *n, size_t m, size_t row_to_delete)
{
    for (size_t i = row_to_delete; i < *n - 1; ++i)
        for (size_t j = 0; j < m; ++j)
            matrix[i][j] = matrix[i + 1][j];
    (*n)--;
}


void delete_column(int matrix[][N], size_t n, size_t *m, size_t column_to_delete)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = column_to_delete; j < *m - 1; ++j)
        {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    (*m)--;
}


void find_first_sod_min(int matrix[][N], size_t n, size_t m, size_t *sod_row, size_t *sod_column)
{
    int min = sum_of_digits(matrix[0][0]);
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            int current_sum = sum_of_digits(matrix[i][j]);
            if (current_sum < min)
            {
                min = current_sum;
                *sod_row = i;
                *sod_column = j;
            }
        }
    }
}


int refactor_matrix(int matrix[][N], size_t *n, size_t *m)
{
    int status_code = OK;
    size_t min_row = 0, min_column = 0;
    find_first_sod_min(matrix, *n, *m, &min_row, &min_column);
    delete_column(matrix, *n, m, min_column);
    delete_row(matrix, n, *m, min_row);
    if (!(*n || *m))
        status_code = OUTPUT_ERROR;
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
