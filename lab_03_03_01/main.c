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
int compare_two_arrays_by_max(array_t *first, array_t *second);

void matrix_bubble_sort(matrix_t *matrix, int (*compare)(array_t *, array_t *));
void print_array(array_t *arr);
void print_matrix(matrix_t *matrix);
void get_errors(int status_code);
void swap(array_t *first, array_t *second);


int main()
{
    int status_code = OK;
    matrix_t matrix;
    if ((status_code = read_matrix(&matrix)))
        get_errors(status_code);
    else
    {
        matrix_bubble_sort(&matrix, compare_two_arrays_by_max);
        print_matrix(&matrix);
    }
    return status_code;
}


void matrix_bubble_sort(matrix_t *matrix, int (*compare)(array_t *, array_t *))
{
    for (size_t n = 0; n < matrix->rows_count; ++n)
        for (size_t m = 0; m < matrix->rows_count - n - 1; ++m)
        {
            if (!compare(matrix->rows + m, matrix->rows + m + 1))
                swap(matrix->rows + m, matrix->rows + m + 1);
        }
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


void swap(array_t *first, array_t *second)
{
    array_t temp_ = *second;
    *second = *first;
    *first = temp_;
}


int max(array_t *arr)
{
    int max_n = *arr->nums, new;
    for (size_t i = 0; i < arr->len; ++i)
    {
        new = *(arr->nums + i);
        if (new > max_n)
            max_n = new;
    }
    return max_n;
}


int compare_two_arrays_by_max(array_t *first, array_t *second)
{
    int first_max = max(first);
    int second_max = max(second);
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
