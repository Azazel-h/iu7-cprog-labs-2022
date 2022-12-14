#include <stdio.h>
#define INPUT_ERROR_CODE -100

void print_number(int number);
int count_digits(int number);
int power(int number, int power);

int main(void)
{
    int number, rc;
    printf("Введите натуральное число: ");
    rc = scanf("%d", &number);
    if (rc != 1 || number <= 0)
        return INPUT_ERROR_CODE;
    printf("Результат: ");
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
        for (int i = 0; i < power; ++i)
            powered_number *= number;
    return number;
}

