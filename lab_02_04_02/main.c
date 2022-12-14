#include <stdio.h>
#include <stddef.h>


#define N 10
#define OK 0
#define INPUT_ERROR -11
#define SIZE_ERROR -13
#define SIZE_INPUT_ERROR -14
#define INVALID_ERROR -15
#define INPUT_OVERFLOW 100


typedef struct
{
    size_t len;
    int nums[N];
} array_t;


int read_array(array_t *arr);

void print_array(array_t *arr);
void selection_sort(array_t *arr);
void swap(int *first, int *second);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    array_t arr;
    if (((status_code = read_array(&arr)) == OK || status_code == INPUT_OVERFLOW))
    {
        selection_sort(&arr);
        print_array(&arr);
    }
    else
        get_errors(status_code);
    return status_code;
}


void swap(int *first, int *second)
{
    int temp_ = *first;
    *first = *second;
    *second = temp_;
}


int read_array(array_t *arr)
{
    int status_code = OK;
    arr->len = 0;

    while (arr->len <= N && scanf("%d", arr->nums + arr->len) == 1)
        arr->len++;

    if (arr->len == 0)
        status_code = SIZE_ERROR;
    if (arr->len > N)
    {
        status_code = INPUT_OVERFLOW;
        arr->len = N;
    }

    return status_code;
}


void selection_sort(array_t *arr)
{
    for (size_t i = 0; i < arr->len - 1; ++i)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < arr->len; ++j)
            if (arr->nums[j] < arr->nums[min_index])
                min_index = j;
        if (min_index != i)
            swap(arr->nums + i, arr->nums + min_index);
    }
}


void print_array(array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        printf("%d ", arr->nums[i]);
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
            printf("ERROR: Bad array size\n");
            break;
        case SIZE_INPUT_ERROR:
            printf("ERROR: Bad input size\n");
            break;
        case INVALID_ERROR:
            printf("ERROR: No one valid element\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
