#include <stdio.h>
#define STANDARD_SIZE 10
#define OK 0
#define INPUT_ERROR -100

int find_product(int *arr, int n, int *product);
int read_array(int *arr, int n);


int main(void)
{
    int arr[STANDARD_SIZE];
    int status_code = OK, check_input, product = 1;
    int n;

    check_input = scanf("%d", &n);
    if (check_input != 1 || n < 1 || n > 10)
        status_code = INPUT_ERROR;

    if (status_code == OK && read_array(arr, n) == OK)
        status_code = find_product(arr, n, &product);

    if (status_code == OK)
        printf("%d", product);
    return status_code;
}

int read_array(int *arr, int n)
{
    int status_code = OK, check_input;
    for (int i = 0; i < n; ++i)
    {
        check_input = scanf("%d", arr + i);
        if (check_input != 1)
            status_code = INPUT_ERROR;
    }
    return status_code;
}

int find_product(int *arr, int n, int *product)
{
    int is_odd = 0, status_code = OK;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2 != 0)
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
