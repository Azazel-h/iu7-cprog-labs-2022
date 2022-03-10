#include <stdio.h>

void print_number(int number);
int count_digits(int number);
int power(int number, int power);

int main(void)
{
    int number, rc;
    rc = scanf("%d", &number);
    if (number <= 0 || rc != 1)
        return -100;
    print_number(number);
}

void print_number(int number)
{
    int digits_num = count_digits(number);
    int rank = power(10, digits_num - 1);

    while (rank > 0)
    {
        printf("%d", number / rank);
        number %= rank;
        rank /= 10;
    }
}

int count_digits(int number)
{
    int digits_counter = 0;
    while (number > 0)
    {
        digits_counter++;
        number /= 10;
    }
    return digits_counter;
}

int power(int number, int power)
{
    int powered_number = number;
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

