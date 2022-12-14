#include <stdio.h>
#include <math.h>
#define INPUT_ERROR_CODE -100
#define OK_STATUS_CODE 0

double calculate_relative(double f_x, double s_x);
double calculate_absolute(double f_x, double s_x);
double calculate_f_x(double x);
double calculate_s_x(double x, double eps);

int main(void)
{
    double x, eps;
    int status_code = OK_STATUS_CODE;

    printf("Введите x, eps: \n");

    int check_inp;
    check_inp = scanf("%lf%lf", &x, &eps);

    if (check_inp != 2 || fabs(x) >= 1 || fabs(eps) > 1 || eps < 0)
        status_code = INPUT_ERROR_CODE;

    if (status_code == OK_STATUS_CODE)
    {
        double s_x = calculate_s_x(x, eps), f_x = calculate_f_x(x);

        printf("Результат s(x), f(x), AbsoluteError, RelativeError: %f %f %f %f", s_x, f_x,
        calculate_absolute(f_x, s_x), calculate_relative(f_x, s_x));
    }
    return status_code;
}

double calculate_relative(double f_x, double s_x)
{
    return fabs(f_x - s_x) / fabs(f_x);
}

double calculate_absolute(double f_x, double s_x)
{
    return fabs(f_x - s_x);
}

double calculate_f_x(double x)
{
    return 1 / sqrt(1 - pow(x, 2));
}

double calculate_s_x(double x, double eps)
{
    double sum = 1;
    double numerator = 1;
    double denominator = 2;
    int power = 2;
    int counter_numerator = 1;
    int counter_denominator = 2;

    double new = (counter_numerator * pow(x, power)) / denominator;
    sum += new;

    while (fabs(new) > eps)
    {
        power += 2;

        counter_numerator += 2;
        counter_denominator += 2;

        numerator *= counter_numerator;
        denominator *= counter_denominator;
        new = (numerator * pow(x, power)) / denominator;

        sum += new;
    }

    return sum;
}

