#include <stdio.h>

void print_binary(unsigned int n)
{
    if (n > 1)
        print_binary(n / 2);
    printf("%d", n % 2);
}

int main(void)
{
    int signed_x, n;
    int check_input;
    check_input = scanf("%d%d", &signed_x, &n);
    if (check_input != 2 || signed_x < 0)
    {
        printf("Error: Wrong Input");
        return -100;
    }
    unsigned int unsigned_x = signed_x;

    for (int i = 0; i < n; ++i)
    {
        unsigned_x <<= 1;
    }
    printf("Result: ");
    print_binary(unsigned_x);
    return 0;
}

