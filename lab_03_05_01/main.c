#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 10
#define ROTL_STEP 3
#define OK 0
#define INPUT_ERROR -11
#define OUTPUT_ERROR -12
#define SIZE_ERROR -13
#define SIZE_INPUT_ERROR -14


int read_matrix(int matrix[][N], size_t *n, size_t *m);
int count_num_sum(int num);
int get_task_nums(int main_matrix[][N], size_t n, size_t m, int *res_nums, size_t *res_len);

void print_matrix(int matrix[][N], size_t n, size_t m);
void reverse_arr(int *arr, size_t start, size_t end);
void rotl(int *arr, size_t len, size_t k);
void set_task_nums(int main_matrix[][N], size_t n, size_t m, int *res_nums);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    int matrix[N][N];
    size_t n, m;

    int result_nums[N * N];
    size_t result_len = 0;

    if ((status_code = read_matrix(matrix, &n, &m)) || (status_code = get_task_nums(matrix, n, m, result_nums, &result_len)))
        get_errors(status_code);
    else
    {
        rotl(result_nums, result_len, ROTL_STEP);
        set_task_nums(matrix, n, m, result_nums);
        print_matrix(matrix, n, m);
    }
    return status_code;
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
        for (size_t i = 0; i < *n; ++i)
        {
            for (size_t j = 0; j < *m; ++j)
            {
                if (scanf("%d", &matrix[i][j]) != 1)
                {
                    status_code = INPUT_ERROR;
                    break;
                }
            }
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
        sum += num % 10;
        num /= 10;
    }
    return sum;
}


int get_task_nums(int main_matrix[][N], size_t n, size_t m, int *res_nums, size_t *res_len)
{
    int status_code = INPUT_ERROR;
    int new;

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            new = main_matrix[i][j];
            if (count_num_sum(new) > 10)
            {
                res_nums[*res_len] = new;
                (*res_len)++;
                status_code = OK;
            }
        }
    }

    return status_code;
}


void set_task_nums(int main_matrix[][N], size_t n, size_t m, int *res_nums)
{
    size_t counter = 0;
    int new;

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            new = main_matrix[i][j];
            if (count_num_sum(new) > 10)
            {
                main_matrix[i][j] = res_nums[counter];
                counter++;
            }
        }
    }
}


void reverse_arr(int *arr, size_t start, size_t end)
{
    int tmp;
    while (start < end)
    {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}


void rotl(int *arr, size_t len, size_t k)
{
    if (len > k)
    {
        reverse_arr(arr, 0, len - 1);
        reverse_arr(arr, 0, len - k - 1);
        reverse_arr(arr, len - k, len - 1);
    }
    else if (len == 2)
    {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
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
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
