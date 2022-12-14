#include <stdio.h>
#include <stdint.h>
#define INPUT_ERROR_CODE -100
#define OK_STATUS_CODE 0

void print_binary(uint32_t n);
uint32_t bit_rol(uint32_t x, int n);

int main(void)
{
    uint32_t x;
    int n, check_input;
    int status_code = OK_STATUS_CODE;

    check_input = scanf("%u%d", &x, &n);
    if (check_input != 2 || n < 0)
    {
        printf("Error: Wrong Input");
        status_code = INPUT_ERROR_CODE;
    }

    if (status_code == OK_STATUS_CODE)
    {
        x = bit_rol(x, n);
        printf("Result: ");
        print_binary(x);
    }
    return status_code;
}

void print_binary(uint32_t n)
{
    for (int c = 31; c >= 0; --c)
    {
        if ((n >> c) & 1)
            printf("1");
        else
            printf("0");
    }
}

uint32_t bit_rol(uint32_t x, int n)
{
    return x << n | x >> (32 - n);
}
