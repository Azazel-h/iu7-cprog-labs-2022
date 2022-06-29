#include <stdio.h>
#include <stddef.h>


#define N 10
#define MAX_N 20
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
    int nums[MAX_N];
} array_t;


int read_array(array_t *arr);
void print_array(array_t *arr);
int can_paste_after(const int *const n);
int form_new_fib_array(array_t *main_arr, array_t*new_array, int (*check)(const int *n));


void swap(int *const first, int *const second);
void paste_in_array(array_t *arr, const int *const n);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    array_t arr, fib_arr = { .len = 0 };
    if ((status_code = read_array(&arr)) || (status_code = form_new_fib_array(&arr, &fib_arr, can_paste_after)))
        get_errors(status_code);
    else
        print_array(&fib_arr);
    return status_code;
}


void swap(int *const first, int *const second)
{
    int temp_ = *first;
    *first = *second;
    *second = temp_;
}


int read_array(array_t*arr)
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


void print_array(array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        printf("%d ", *(arr->nums + i));
    }
}


int can_paste_after(const int *const n)
{
    int can_ = FALSE;
    if (*n % 3 == 0)
        can_ = TRUE;
    return can_;
}


void paste_in_array(array_t *arr, const int *const n)
{
    *(arr->nums + arr->len) = *n;
    arr->len++;
}


int form_new_fib_array(array_t *main_arr, array_t *new_array, int (*check)(const int *n))
{
    int status_code = OK;
    int fib_0_ = 0, fib_1_ = 1, fib_sum_;

    for (size_t i = 0; i < main_arr->len; ++i)
    {
        paste_in_array(new_array, (main_arr->nums + i));
        if (check((main_arr->nums + i)))
        {
            paste_in_array(new_array, &fib_0_);
            fib_sum_ = fib_0_ + fib_1_;
            swap(&fib_0_, &fib_1_);
            fib_1_ = fib_sum_;
        }
    }
    if (new_array->len == 0)
        status_code = INPUT_ERROR;

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
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
