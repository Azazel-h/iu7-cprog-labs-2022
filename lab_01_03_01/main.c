#include <stdio.h>
#define WATER_DENSITY 997.0

void calculate_v_t(float first_v, float second_v, float first_t, float second_t, float *result_v, float *result_t);
float mass_calculation(float v, float density);

int main(void)
{
    float first_v, second_v, first_t, second_t, result_v, result_t;
    printf("Введите V_first, T_first: ");
    scanf("%f%f", &first_v, &first_t);
    printf("Введите V_second, T_second: ");
    scanf("%f%f", &second_v, &second_t);

    calculate_v_t(first_v, second_v, first_t, second_t, &result_v, &result_t);
    printf("Итоговые значения \nV = %f \nT = %f", result_v, result_t);
}

void calculate_v_t(float first_v, float second_v, float first_t, float second_t, float *result_v, float *result_t)
{
    float first_m, second_m;
    first_m = mass_calculation(first_v, WATER_DENSITY);
    second_m = mass_calculation(second_v, WATER_DENSITY);
    *result_v = first_v + second_v;
    *result_t = (first_m * first_t + second_m * second_t) / (first_m + second_m);
}

float mass_calculation(float v, float density)
{
    return v * density;
}
