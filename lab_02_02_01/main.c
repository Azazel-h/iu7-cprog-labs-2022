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

typedef struct
{
    size_t len;
    int nums[N];
} array;

int read_array(array *arr);
int print_array(array *arr);
int is_prime(const int *n);
int form_new_array(array *main_arr, array *new_array, int (*check)(const int *n));

int main()
{
    int status_code = OK;
    array arr, prime_arr = {.len = 0};
    if (!((status_code = read_array(&arr)) || (status_code = form_new_array(&arr, &prime_arr, is_prime))))
        status_code = print_array(&prime_arr);
    return status_code;
}

int read_array(array *arr)
{
    int status_code = OK;
    if (scanf("%zu", &(arr->len)) != 1)
        status_code = SIZE_INPUT_ERROR;
    else if (arr->len < 1 || arr->len > N)
        status_code = SIZE_ERROR;
    else
    {
        for (size_t i = 0; i < arr->len; ++i)
        {
            if (scanf("%d", arr->nums + i) != 1)
            {
                status_code = INPUT_ERROR;
                i = arr->len;
            }
        }
    }
    return status_code;
}


int print_array(array *arr)
{
    int status_code = OK;
    for (size_t i = 0; i < arr->len; ++i)
    {
        printf("%d ", *(arr->nums + i));
    }
    return status_code;
}


int is_prime(const int *n)
{
    int is_prime = TRUE;
    int end = (int) sqrt(*n) + 1;
    for (int i = 2; i < end; ++i)
        if (*n % i == 0)
            is_prime = FALSE;
    if (*n == 1 || *n == 0)
        is_prime = FALSE;
    return is_prime;
}

int form_new_array(array *main_arr, array *new_array, int (*check)(const int *n))
{
    int status_code = OK;
    for (size_t i = 0; i < main_arr->len; ++i)
    {
        if (check((main_arr->nums + i)))
        {
            *(new_array->nums + new_array->len) = *(main_arr->nums + i);
            new_array->len++;
        }
    }
    if (new_array->len == 0)
        status_code = INPUT_ERROR;

    return status_code;
}
