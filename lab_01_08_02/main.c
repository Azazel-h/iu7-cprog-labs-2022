#include <stdio.h>

void print_binary(unsigned int n);
u_int32_t bit_rol(u_int32_t x, int n);

int main(void)
{
    u_int32_t x;
    int n, check_input;
    check_input = scanf("%u %d", &x, &n);
    if (check_input != 2 || n < 0)
    {
        printf("Error: Wrong Input");
        return -100;
    }
    x = bit_rol(x, n);
    printf("Result: ");
    print_binary(x);
    return 0;
}

void print_binary(unsigned int n)
{
    if (n > 1)
        print_binary(n / 2);
    printf("%d", n % 2);
}

u_int32_t bit_rol(u_int32_t x, int n)
{
    return x << n | x >> (32 - n);
}
