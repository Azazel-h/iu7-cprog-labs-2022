#include <stdio.h>
#include <math.h>

double calculate_new(double x, int n);
double calculate_g_x(double sum, int n);

int main(void)
{
    double sum = 0, x;
    int num_of_x = 0, check_input;

    check_input = scanf("%lf", &x);
    if (check_input != 1 || x < 0)
        return -100;

    while (x >= 0)
    {
        num_of_x++;
        sum += calculate_new(x, num_of_x);
        check_input = scanf("%lf", &x);
        if (check_input != 1)
            return -100;
    }
    printf("%lf", calculate_g_x(sum, num_of_x));
    return 0;
}

double calculate_new(double x, int n)
{
    return sqrt(n + x);
}

double calculate_g_x(double sum, int n)
{
    return (1.0f / n) * sum;
}
