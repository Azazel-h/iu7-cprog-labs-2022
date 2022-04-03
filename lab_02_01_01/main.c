#include <stdio.h>
#define STANDARD_SIZE 10
#define OK 0
#define INPUT_ERROR -100

int find_product(int* arr);

int main(void)
{
    int status_code = OK;
    int arr[STANDARD_SIZE];
    for (int i = 0; i < STANDARD_SIZE; ++i)
    {
        int check_input = scanf("%d", arr + i);
        if (check_input != 1)
            status_code = INPUT_ERROR;
    }
    printf("%d", find_product(arr));
    return status_code;
}

int find_product(int* arr)
{
    int product = 1;
    for (int i = 0; i < STANDARD_SIZE; ++i)
    {
        if (arr[i] % 2 != 0)
            product *= arr[i];
    }
    return product;
}
