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
#define NOT_A_SQUARE_MATRIX_ERROR -15

int start_reading_matrix(int matrix[][N], size_t *n, size_t *m);
int square_check(size_t n, size_t m);

void set_spiral(int matrix[][N], size_t n, size_t m);
void print_matrix(int matrix[][N], size_t n, size_t m);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    int matrix[N][N];
    size_t n, m;

    if ((status_code = start_reading_matrix(matrix, &n, &m)) || (status_code = square_check(n, m)))
        get_errors(status_code);
    else
    {
        print_matrix(matrix, n, m);
    }
    return status_code;
}


int square_check(size_t n, size_t m)
{
    int status_code = OK;
    if (n != m)
        status_code = NOT_A_SQUARE_MATRIX_ERROR;
    return status_code;
}


int start_reading_matrix(int matrix[][N], size_t *n, size_t *m)
{
    int status_code = OK;
    if (scanf("%zu%zu", n, m) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((*n < 1 || *n > N) || (*m < 1 || *m > N))
        status_code = SIZE_ERROR;
    else
    {
        set_spiral(matrix, *n, *m);
    }
    return status_code;
}


void set_spiral(int matrix[][N], size_t n, size_t m)
{
    int s_row_index = 0, s_column_index = 0;
    int e_row_index = n, e_column_index = m;
    int value = 1;

    while (s_row_index < e_row_index && s_column_index < e_column_index)
    {
        for (int i = s_column_index; i < e_column_index; ++i)
            matrix[s_row_index][i] = value++;
        s_row_index++;

        for (int i = s_row_index; i < e_row_index; ++i)
            matrix[i][e_column_index - 1] = value++;
        e_column_index--;

        if (s_row_index < e_row_index)
        {
            for (int i = e_column_index - 1; i >= s_column_index; --i)
                matrix[e_row_index - 1][i] = value++;
            e_row_index--;
        }

        if (s_column_index < e_column_index)
        {
            for (int i = e_row_index - 1; i >= s_row_index; --i)
                matrix[i][s_column_index] = value++;
            s_column_index++;
        }
    }
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
        case NOT_A_SQUARE_MATRIX_ERROR:
            printf("ERROR: Not a square matrix\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
