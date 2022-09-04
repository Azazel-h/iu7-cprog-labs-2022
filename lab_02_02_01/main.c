#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>


#define N 10
#define OK 0
#define INPUT_ERROR -11
#define SIZE_ERROR -12
#define SIZE_INPUT_ERROR -13
#define NO_SUITABLE_ELEMENTS_ERROR -14
#define INVALID_ERROR -15


typedef struct
{
    size_t len;
    int nums[N];
} array_t;


int read_array(array_t *arr);
void print_array(array_t *arr);
bool is_prime(int n);
int form_new_array(array_t *main_arr, array_t *new_array_t, bool (*check)(int n));

void get_errors(int status_code);

int main()
{
    int status_code = OK;
    array_t arr, prime_arr;
    if ((status_code = read_array(&arr)) || (status_code = form_new_array(&arr, &prime_arr, is_prime)))
        get_errors(status_code);
    else
        print_array(&prime_arr);
    return status_code;
}

int read_array(array_t *arr)
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
                break;
            }
        }
    }
    return status_code;
}


void print_array(array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        printf("%d ", arr->nums[i]);
    }
}


bool is_prime(int n)
{
    bool is_prime = true;

    if (n < 2)
        is_prime = false;
    else
    {
        int end = (int) sqrt(n) + 1;
        for (int i = 2; i < end; ++i)
            if (n % i == 0)
            {
                is_prime = false;
                break;
            }
    }
    return is_prime;
}

int form_new_array(array_t *main_arr, array_t *new_array, bool (*check)(int n))
{
    int status_code = OK;
    new_array->len = 0;

    for (size_t i = 0; i < main_arr->len; ++i)
    {
        if (check(main_arr->nums[i]))
        {
            new_array->nums[new_array->len] = main_arr->nums[i];
            new_array->len++;
        }
    }
    if (new_array->len == 0)
        status_code = NO_SUITABLE_ELEMENTS_ERROR;

    return status_code;
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
        case NO_SUITABLE_ELEMENTS_ERROR:
            printf("ERROR: No necessary elements\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
