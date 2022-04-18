#include <stdio.h>
#include <stdlib.h>

#define STANDARD_SIZE 10
#define OK 0
#define INPUT_ERROR -100

int read_array(int *arr, size_t n);
int find_product(int *arr, size_t n, int *product);

int main(void)
{
    int arr[STANDARD_SIZE], product = 1, n;
    int status_code = OK, check_input;

    check_input = scanf("%d", &n);
    if (check_input != 1 || (n < 1 || n > 10))
        status_code = INPUT_ERROR;
    else
        status_code = read_array(arr, (size_t) n);
        if (status_code == OK)
            status_code = find_product(arr, (size_t) n, &product);

    if (status_code == OK)
        printf("%d", product);
    return status_code;
}

int read_array(int *arr, size_t n)
{
    int check_input, status_code = OK;
    for (size_t i = 0; i < n; ++i)
    {
        check_input = scanf("%d", arr + i);
        if (check_input != 1)
        {
            status_code = INPUT_ERROR;
            break;
        }
    }
    return status_code;
}

int find_product(int *arr, size_t n, int *product)
{
    int is_odd = 0, status_code = OK;
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
        status_code = INPUT_ERROR;
    return status_code;
}

