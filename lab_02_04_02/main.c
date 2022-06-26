#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define N 10
#define OK 0
#define FALSE 0
#define TRUE 1
#define INPUT_ERROR -11
#define OUTPUT_ERROR -12
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
int print_array(array_t *arr);
int is_prime(const int *n);
int form_new_array(array_t *main_arr, array_t *new_array_t, int (*check)(const int *n));

void selection_sort(array_t *arr);
void swap(int *const first, int *const second);

int main()
{
    int status_code = OK;
    array_t arr = { .len = 0 };
    if (((status_code = read_array(&arr)) == OK || status_code == INPUT_OVERFLOW))
    {
        selection_sort(&arr);
        print_array(&arr);
    }
    return status_code;
}


void swap(int *const first, int *const second)
{
    int temp_ = *first;
    *first = *second;
    *second = temp_;
}


int read_array(array_t *arr)
{
    int status_code = OK;
    while (arr->len < N && scanf("%d", arr->nums + arr->len) == 1)
        arr->len++;

    if (arr->len == 0)
        status_code = SIZE_ERROR;
    if (arr->len >= N)
        status_code = INPUT_OVERFLOW;

    return status_code;
}


void selection_sort(array_t *arr)
{
    for (size_t i = 0; i < arr->len - 1; ++i)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < arr->len; ++j)
            if (*(arr->nums + j) < *(arr->nums + min_index))
                min_index = j;
        if (min_index != i)
            swap(arr->nums + i, arr->nums + min_index);
    }
}


int print_array(array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        printf("%d ", *(arr->nums + i));
    }
}

