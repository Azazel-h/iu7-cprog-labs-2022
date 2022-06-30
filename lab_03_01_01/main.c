#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>


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
int is_symmetrical(array_t *arr);


void form_result_array_from_matrix(array_t *result_arr, matrix_t *main_matrix, int (*check)(array_t *));
void print_array(array_t *arr);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    matrix_t matrix;
    if ((status_code = read_matrix(&matrix)))
        get_errors(status_code);
    else
    {
        array_t result_arr = { .len = matrix.rows_count };
        form_result_array_from_matrix(&result_arr, &matrix, is_symmetrical);
        print_array(&result_arr);
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
        for (size_t n = 0; n < matrix->rows_count; ++n)
        {
            array_t *current_row = matrix->rows + n;
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


int is_symmetrical(array_t *arr)
{
    int is_symmetrical = true;
    for (size_t i = 0; i < arr->len / 2 + 1; ++i)
    {
        if (*(arr->nums + i) != *(arr->nums + (arr->len - i - 1)))
        {
            is_symmetrical = false;
            break;
        }
    }
    return is_symmetrical;
}


void form_result_array_from_matrix(array_t *result_arr, matrix_t *main_matrix, int (*check)(array_t *))
{
    for (size_t i = 0; i < result_arr->len; ++i)
    {
        *(result_arr->nums + i) = check(main_matrix->rows + i);
    }
}


void print_array(array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        printf("%d ", *(arr->nums + i));
    }
    printf("\n");
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
