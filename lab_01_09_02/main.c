#include <stdio.h>
#include <math.h>

double calculate_new(double x, int n);

int main(void)
{
    double sum = 0, x;
    int num_of_x = 0, check_input;

    check_input = scanf("%lf", &x);
    if (check_input != 1)
        return -1;

    while (x >= 0)
    {
        num_of_x++;
        sum += calculate_new(x, num_of_x);
        scanf("%lf", &x);
    }

    printf("%lf", (1 / num_of_x) * sum);
    return 0;
}

double calculate_new(double x, int n)
{
    return sqrt(n + x);
}
