#include <stdio.h>

void print_number(long long number);
int count_digits(long long number);
long long power(long long number, int power);

int main(void)
{
    long long number, rc;
    rc = scanf("%lld", &number);
    if (rc != 1 || number <= 0)
        return -100;
    print_number(number);
}

void print_number(long long number)
{
    int digits_num = count_digits(number);
    long long rank = power(10, digits_num - 1);

    while (rank > 0)
    {
        printf("%d", number / rank);
        number %= rank;
        rank /= 10;
    }
}

int count_digits(long long number)
{
    int digits_counter = 0;
    while (number > 0)
    {
        digits_counter++;
        number /= 10;
    }
    return digits_counter;
}

long long power(long long number, int power)
{
    long long powered_number = number;
    if (power > 0)
    {
        for (int i = 0; i < power; ++i) {
            powered_number *= number;
        }
    }
    else
    {
        return 1;
    }
    return number;
}

