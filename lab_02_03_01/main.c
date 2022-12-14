#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>


#define N 10
#define MAX_N 21
#define OK 0
#define INPUT_ERROR -11
#define SIZE_ERROR -12
#define SIZE_INPUT_ERROR -13
#define INVALID_ERROR -14
#define NO_SUITABLE_ELEMENTS_ERROR -15


typedef struct
{
    size_t len;
    int nums[MAX_N];
} array_t;


int read_array(array_t *arr);
bool can_paste_after(int *n);

void print_array(array_t *arr);
void form_fib_array(array_t *main_arr, bool (*check)(int *n));
void paste_in_array(array_t *arr, int *n, size_t index);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    array_t arr;
    if ((status_code = read_array(&arr)))
        get_errors(status_code);
    else
    {
        form_fib_array(&arr, can_paste_after);
        print_array(&arr);
    }
    return status_code;
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


bool can_paste_after(int *n)
{
    bool can_ = false;
    if (*n % 3 == 0)
        can_ = true;
    return can_;
}


void paste_in_array(array_t *arr, int *n, size_t index)
{
    arr->len++;
    for (size_t i = arr->len - 1; i > index; --i)
        arr->nums[i] = arr->nums[i - 1];
    arr->nums[index] = *n;
}


void form_fib_array(array_t *main_arr, bool (*check)(int *n))
{
    int fib_0 = 0, fib_1 = 1, fib_sum;

    size_t i = 0;
    while (i < main_arr->len)
    {
        if (check(main_arr->nums + i))
        {
            paste_in_array(main_arr, &fib_0, i + 1);
            i++;

            fib_sum = fib_0 + fib_1;
            fib_0 = fib_1;
            fib_1 = fib_sum;
        }
        i++;
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
        case NO_SUITABLE_ELEMENTS_ERROR:
            printf("ERROR: No necessary elements\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
