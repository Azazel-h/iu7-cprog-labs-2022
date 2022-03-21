#include <stdio.h>
#include <math.h>

float calculate_relative(float f_x, float s_x);
float calculate_absolute(float f_x, float s_x);
float calculate_f_x(float x);
float calculate_s_x(float x, float eps);

int main(void)
{
    float x, eps;
    printf("Введите x, eps");
    check_first_inp = scanf("%f%f", &x, &eps);
    if (check_first_inp != 2 || fabsf(x) >= 1)
    {
        return -1;
    }
    float s_x = calculate_s_x(), f_x = calculate_f_x();
    printf("%f%f%f%f", s_x, f_x, calculate_absolute(), calculate_relative();
    return 0;
}

float calculate_relative(float f_x, float s_x)
{
    return fabsf(f_x - s_x) / fabsf(f_x);
}

float calculate_absolute(float f_x, float s_x)
{
    return fabsf(f_x - s_x);
}

float calculate_f_x(float x)
{
    return 1 / sqrtf(1 - pow(x, 2));
}

float calculate_s_x(float x, float eps)
{
    float sum = 1;

    int numerator = 1;
    int denominator = 2;
    int power = 2;

    int counter_numerator = 1;
    int counter_denominator = 2;

    while (fabsf(new) > eps)
    {
        new = numerator * pow(x, power) / denominator;
        sum += new;

        power += 2;
        numerator *= (counter_numerator + 2);
        denominator *= (counter_denominator + 2);
    }

    return sum;
}

