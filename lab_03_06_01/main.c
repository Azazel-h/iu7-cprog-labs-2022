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


typedef struct
{
    size_t len;
    int nums[N];
} array_t;


typedef struct
{
    size_t rows_count;
    size_t columns_count;
    array_t rows[N];
} matrix_t;


int read_matrix(matrix_t *matrix);
int read_by_spiral(matrix_t *matrix);

void print_array(array_t *arr);
void print_matrix(matrix_t *matrix);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    matrix_t matrix;
    if ((status_code = read_matrix(&matrix)))
        get_errors(status_code);
    else
    {
        print_matrix(&matrix);
    }
    return status_code;
}


int read_matrix(matrix_t *matrix)
{
    int status_code = OK;
    if (scanf("%zu%zu", &(matrix->rows_count), &(matrix->columns_count)) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((matrix->rows_count < 1 || matrix->rows_count > N) ||
             (matrix->columns_count < 1 || matrix->columns_count > N) ||
             (matrix->rows_count != matrix->columns_count))
        status_code = SIZE_ERROR;

    else
    {
        for (size_t m = 0; m < matrix->rows_count; ++m)
            (matrix->rows + m)->len = matrix->columns_count;

        status_code = read_by_spiral(matrix);
    }
    return status_code;
}


int read_by_spiral(matrix_t *matrix)
{
    int status_code = OK;
    int s_row_index = 0, s_column_index = 0;
    int e_row_index = matrix->rows_count, e_column_index = matrix->columns_count;
    int value = 1;

    while (s_row_index < e_row_index && s_column_index < e_column_index)
    {
        for (int i = s_column_index; i < e_column_index; ++i)
            *((matrix->rows + s_row_index)->nums + i) = value++;
        s_row_index++;
        for (int i = s_row_index; i < e_row_index; ++i)
            *((matrix->rows + i)->nums + (e_column_index - 1)) = value++;
        e_column_index--;
        if (s_row_index < e_row_index)
        {
            for (int i = e_column_index - 1; i >= s_column_index; --i)
                *((matrix->rows + (e_row_index - 1))->nums + i) = value++;
            e_row_index--;
        }
        if (s_column_index < e_column_index)
        {
            for (int i = e_row_index - 1; i >= s_row_index; --i)
                *((matrix->rows + i)->nums + s_column_index) = value++;
            s_column_index++;
        }
    }
    return status_code;
}


void print_array(array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        printf("%d ", *(arr->nums + i));
    }
    printf("\n");
}


void print_matrix(matrix_t *matrix)
{
    for (size_t m = 0; m < matrix->rows_count; ++m)
    {
        print_array(matrix->rows + m);
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
