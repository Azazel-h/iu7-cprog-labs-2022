#include <stdio.h>
#include <stddef.h>

#define N 10
#define OK 0
#define INPUT_ERROR -11
#define SIZE_ERROR -12
#define SIZE_INPUT_ERROR -13

typedef struct
{
    int nums[N];
    int *start;
    int *end;
} array_t;


int read_array(array_t *arr);
int calculate_result(array_t *arr);

void get_errors(int status_code);


int main()
{
    int status_code = OK;
    array_t arr;
    arr.start = arr.nums;
    arr.end = arr.nums;

    if ((status_code = read_array(&arr)))
        get_errors(status_code);
    else
    {
        printf("%d\n", calculate_result(&arr));
    }
    return status_code;
}

int read_array(array_t *arr)
{
    int status_code = OK;
    size_t len_;

    if (scanf("%zu", &len_) != 1)
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

int calculate_result(array_t *arr)
{
    int *temp_start_ = arr->start, *temp_end_ = arr->end - 1, max = *arr->start + *(arr->end - 1), sum;
    while (temp_start_ < temp_end_)
    {
        sum = *temp_start_ + *temp_end_;
        if (sum > max)
            max = sum;
        ++temp_start_;
        --temp_end_;
    }
    return max;
}

void get_errors(int status_code)
{
    switch (status_code)
    {
        case INPUT_ERROR:
            printf("ERROR: Bad input\n");
            break;
        case SIZE_ERROR:
            printf("ERROR: Bad array size\n");
            break;
        case SIZE_INPUT_ERROR:
            printf("ERROR: Bad input size\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
