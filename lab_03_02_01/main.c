#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>


#define N 10
#define OK 0
#define INPUT_ERROR -11
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


int read_array(array_t *arr);
int read_matrix(matrix_t *matrix);
int sum_of_digits(int number);


void print_array(array_t *arr);
void print_matrix(matrix_t *matrix);
void get_errors(int status_code);
void find_first_sod_min(matrix_t *matrix, size_t *row, size_t *column);
void delete_row(matrix_t *matrix, int row_to_delete);
void delete_column(matrix_t *matrix, int column_to_delete);
void refactor_matrix(matrix_t *matrix);


int main()
{
    int status_code = OK;
    matrix_t matrix;
    if ((status_code = read_matrix(&matrix)))
        get_errors(status_code);
    else
    {
        refactor_matrix(&matrix);
        print_matrix(&matrix);
    }
    return status_code;
}


int read_matrix(matrix_t *matrix)
{
    int status_code = OK;
    if (scanf("%zu%zu", &(matrix->rows_count), &(matrix->columns_count)) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((matrix->rows_count < 1 || matrix->rows_count > N) || (matrix->columns_count < 1 || matrix->columns_count > N))
        status_code = SIZE_ERROR;
    else
    {
        for (size_t m = 0; m < matrix->rows_count; ++m)
        {
            array_t *current_row = matrix->rows + m;
            current_row->len = matrix->columns_count;
            if ((status_code = read_array(current_row)))
                break;
        }
    }
    return status_code;
}


int read_array(array_t *arr)
{
    int status_code = OK;
    for (size_t i = 0; i < arr->len; ++i)
    {
        if (scanf("%d", arr->nums + i) != 1)
        {
            status_code = INPUT_ERROR;
            break;
        }
    }
    return status_code;
}


int sum_of_digits(int number)
{
    int sum = 0;
    number = abs(number);
    while (number % 10 != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


void delete_row(matrix_t *matrix, int row_to_delete)
{
    for (size_t i = row_to_delete; i < matrix->rows_count - 1; ++i)
        *(matrix->rows + i) = *(matrix->rows + i + 1);
    matrix->rows_count--;
}


void delete_column(matrix_t *matrix, int column_to_delete)
{
    array_t *current_row_nums;
    for (size_t m = 0; m < matrix->rows_count; ++m)
    {
        for (size_t n = column_to_delete; n < matrix->columns_count - 1; ++n)
        {
            current_row_nums = matrix->rows + m;
            *(current_row_nums->nums + n) = *(current_row_nums->nums + n + 1);
        }
        (matrix->rows + m)->len--;
    }
    matrix->columns_count--;
}


void find_first_sod_min(matrix_t *matrix, size_t *row, size_t *column)
{
    int min = sum_of_digits(*((matrix->rows)->nums));
    for (size_t m = 0; m < matrix->rows_count; ++m)
        for (size_t n = 0; n < matrix->columns_count - 1; ++n)
        {
            int current_sum = sum_of_digits(*((matrix->rows + m)->nums + n));
            if (current_sum < min)
            {
                min = current_sum;
                *row = m;
                *column = n;
            }
        }
}


void refactor_matrix(matrix_t *matrix)
{
    size_t min_row = 0, min_column = 0;
    find_first_sod_min(matrix, &min_row, &min_column);
    delete_column(matrix, min_column);
    delete_row(matrix, min_row);
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
        case SIZE_INPUT_ERROR:
            printf("ERROR: Bad input size\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
