#include <stdio.h>
#define STANDARD_SIZE 10
#define OK 0
#define INPUT_ERROR -100

int find_product(int *arr, int n);

int main(void)
{
    int arr[STANDARD_SIZE];
    int status_code = OK, check_input, n;

    check_input = scanf("%d", &n);
    if (check_input != 1 || n < 1 || n > 10)
        status_code = INPUT_ERROR;

    for (int i = 0; i < n; ++i)
    {
        check_input = scanf("%d", arr + i);
        if (check_input != 1)
            status_code = INPUT_ERROR;
    }
    if (status_code == OK)
        printf("%d", find_product(arr, n));
    return status_code;
}

int find_product(int *arr, int n)
{
    int product = 1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2 != 0)
            product *= arr[i];
    }
    return product;
}
