#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>


#define N 101
#define MAX_MATRIX_SIZE 10
#define ROTL_STEP 3
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
int count_num_sum(int num);
int get_task_nums(matrix_t *main_matrix, array_t *res_nums);

void print_array(array_t *arr);
void print_matrix(matrix_t *matrix);
void get_errors(int status_code);
void rotl(array_t *arr, size_t k);
void set_task_nums(matrix_t *main_matrix, array_t *res_nums);


int main()
{
    int status_code = OK;
    matrix_t matrix;
    array_t result_nums = { .len = 0 };
    if ((status_code = read_matrix(&matrix)) || (status_code = get_task_nums(&matrix, &result_nums)))
        get_errors(status_code);
    else
    {
        rotl(&result_nums, ROTL_STEP);
        set_task_nums(&matrix, &result_nums);
        print_matrix(&matrix);
    }
    return status_code;
}


int read_matrix(matrix_t *matrix)
{
    int status_code = OK;
    if (scanf("%zu%zu", &(matrix->rows_count), &(matrix->columns_count)) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((matrix->rows_count < 1 || matrix->rows_count > MAX_MATRIX_SIZE) || (matrix->columns_count < 1 || matrix->columns_count > MAX_MATRIX_SIZE))
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


int count_num_sum(int num)
{
    int sum = 0;
    num = abs(num);
    while (num > 0)
    {
        sum += abs(num) % 10;
        num /= 10;
    }
    return sum;
}


int get_task_nums(matrix_t *main_matrix, array_t *res_nums)
{
    int status_code = INPUT_ERROR;
    for (size_t m = 0; m < main_matrix->rows_count; ++m)
    {
        for (size_t n = 0; n < main_matrix->columns_count; ++n)
        {
            int new = *((main_matrix->rows + m)->nums + n);
            if (count_num_sum(new) > 10)
            {
                *(res_nums->nums + res_nums->len) = new;
                res_nums->len++;
                status_code = OK;
            }
        }
    }
    return status_code;
}


void set_task_nums(matrix_t *main_matrix, array_t *res_nums)
{
    size_t counter = 0;
    for (size_t m = 0; m < main_matrix->rows_count; ++m)
    {
        for (size_t n = 0; n < main_matrix->columns_count; ++n)
        {
            int new = *((main_matrix->rows + m)->nums + n);
            if (count_num_sum(new) > 10)
            {
                *((main_matrix->rows + m)->nums + n) = *(res_nums->nums + counter);
                counter++;
            }
        }
    }
}

void reverse_arr(array_t *arr, size_t start, size_t end)
{
    int tmp;
    while (start < end)
    {
        tmp = *(arr->nums + start);
        *(arr->nums + start) = *(arr->nums + end);
        *(arr->nums + end) = tmp;
        start++;
        end--;
    }
}


void rotl(array_t *arr, size_t k)
{
    if (arr->len >= k)
    {
        reverse_arr(arr, 0, arr->len - 1);
        reverse_arr(arr, 0, arr->len - k - 1);
        reverse_arr(arr, arr->len - k, arr->len - 1);
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
