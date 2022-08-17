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


int read_array(array_t *arr);
int read_matrix(matrix_t *matrix);


void print_array(array_t *arr);
void print_matrix(matrix_t *matrix);
void get_errors(int status_code);
void task_swap_process(matrix_t *main_matrix);
void swap_elements(int *first, int *second);
void swap_elements_in_range_btw_arrays(size_t start, size_t end, array_t *first, array_t *second);


int main()
{
    int status_code = OK;
    matrix_t matrix;
    if ((status_code = read_matrix(&matrix)))
        get_errors(status_code);
    else
    {
        task_swap_process(&matrix);
        print_matrix(&matrix);
    }
    return status_code;
}


int read_matrix(matrix_t *matrix)
{
    int status_code = OK;
    if (scanf("%zu%zu", &(matrix->rows_count), &(matrix->columns_count)) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((matrix->rows_count < 2 || matrix->rows_count > N) || (matrix->columns_count < 2 || matrix->columns_count > N))
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


void task_swap_process(matrix_t *main_matrix)
{
    for (size_t i = 0; i < main_matrix->rows_count / 2; ++i)
    {
        array_t *first = main_matrix->rows + i;
        array_t *second = main_matrix->rows + main_matrix->rows_count - i - 1;

        swap_elements_in_range_btw_arrays(i, main_matrix->columns_count - i, first, second);
    }
}


void swap_elements_in_range_btw_arrays(size_t start, size_t end, array_t *first, array_t *second)
{
    for (size_t i = start; i < end; ++i)
    {
        swap_elements(first->nums + i, second->nums + i);
    }
}


void swap_elements(int *first, int *second)
{
    int temp_ = *second;
    *second = *first;
    *first = temp_;
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
