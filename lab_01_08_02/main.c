#include <stdio.h>

void print_binary(unsigned int n);

int main(void)
{
    unsigned int x;
    int n, check_input;
    check_input = scanf("%d%d", &x, &n);
    if (check_input != 2 || n < 0)
    {
        printf("Error: Wrong Input");
        return -100;
    }

    for (int i = 0; i < n; ++i)
    {
        x <<= 1;
    }
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

