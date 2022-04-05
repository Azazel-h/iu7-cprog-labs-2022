#include <stdio.h>
#include <stdlib.h>

#define STANDARD_SIZE 10
#define OK 0
#define INPUT_ERROR -100

void read_array(int *arr, size_t n, int *status_code);
void find_product(int *arr, size_t n, int *product, int *status_code);

int main(void)
{
    int arr[STANDARD_SIZE], product = 1, n;
    int status_code = OK, check_input;

    check_input = scanf("%d", &n);
    if (check_input != 1 || (n < 1 || n > 10))
        status_code = INPUT_ERROR;
    else
        read_array(arr, (size_t) n, &status_code);
        if (status_code == OK)
            find_product(arr, (size_t) n, &product, &status_code);

    if (status_code == OK)
        printf("%d", product);
    return status_code;
}

void read_array(int *arr, size_t n, int *status_code)
{
    int check_input;
    for (size_t i = 0; i < n; ++i)
    {
        check_input = scanf("%d", arr + i);
        if (check_input != 1)
        {
            *status_code = INPUT_ERROR;
            break;
        }
    }
}

void find_product(int *arr, size_t n, int *product, int *status_code)
{
    int is_odd = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] % 2)
        {
            *product *= arr[i];
            if (!is_odd)
                is_odd = 1;
        }
    }
    if (!is_odd)
        *status_code = INPUT_ERROR;
}

