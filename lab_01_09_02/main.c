#include <stdio.h>
#include <math.h>
#define INPUT_ERROR_CODE -100
#define OK_STATUS_CODE 0

double calculate_new(double x, int n);
double calculate_g_x(double sum, int n);

int main(void)
{
    double sum = 0, x;
    int num_of_x = 0, check_input;
    int status_code = OK_STATUS_CODE;

    printf("Введите член последовательности: ");
    check_input = scanf("%lf", &x);

    if (check_input != 1 || x < 0)
        return INPUT_ERROR_CODE;

    while (x >= 0)
    {
        num_of_x++;
        sum += calculate_new(x, num_of_x);
        printf("Введите член последовательности: ");
        check_input = scanf("%lf", &x);
        if (check_input != 1)
            status_code = INPUT_ERROR_CODE;
            break;
    }
    if (status_code == OK_STATUS_CODE)
        printf("Результат g(x): %lf", calculate_g_x(sum, num_of_x));
    return status_code;
}

double calculate_new(double x, int n)
{
    return sqrt(n + x);
}

double calculate_g_x(double sum, int n)
{
    return (1.0f / n) * sum;
}
