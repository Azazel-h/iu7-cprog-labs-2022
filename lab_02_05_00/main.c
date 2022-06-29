#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define N 10
#define OK 0
#define INPUT_ERROR -11
#define SIZE_ERROR -13
#define SIZE_INPUT_ERROR -14


typedef struct
{
    int nums[N];
    int *start;
    int *end;
} array_t;


int read_array(array_t *arr);
void calculate_result(array_t *arr, int *max);


int main()
{
    int status_code = OK, result = 0;
    array_t arr = { .start = arr.nums, .end = arr.nums };
    if ((status_code = read_array(&arr)) == OK)
    {
        calculate_result(&arr, &result);
        printf("%d\n", result);
    }
    return status_code;
}


int read_array(array_t *arr)
{
    int status_code = OK;
    size_t len_;

    if (scanf("%zd", &len_) != 1)
        status_code = SIZE_INPUT_ERROR;
    else if (len_ < 1 || len_ > N)
        status_code = SIZE_ERROR;
    else
    {
        for (size_t i = 0; i < len_; ++i)
        {
            if (scanf("%d", arr->end) != 1)
            {
                status_code = INPUT_ERROR;
                break;
            }
            arr->end++;
        }
    }
    return status_code;
}


void calculate_result(array_t *arr, int *const max)
{
    *max = *arr->start;
    for (int *temp_start_= arr->start, *temp_end_ = arr->end; temp_start_ < arr->start + (arr->end - arr->start + 1) / 2; ++temp_start_)
    {
        int sum = *temp_start_ + *--temp_end_;
        if (sum > *max)
        {
            *max = sum;
        }
    }
}

