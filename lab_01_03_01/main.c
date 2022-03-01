#include <stdio.h>

void calculate_V_T(float first_V, float second_V, float first_T, float second_T, float* result_V, float* result_T);
float mass_calculation(float V, float density);

int main(void)
{
    float first_V, second_V, first_T, second_T, result_V, result_T;
    printf("Введите V1, T1: ");
    scanf("%f%f", &first_V, &first_T);
    printf("Введите V2, T2: ");
    scanf("%f%f", &second_V, &second_T);

    calculate_V_T(first_V, second_V, first_T, second_T, &result_V, &result_T);
    printf("Итоговые значения V = %f  T = %f", result_V, result_T);
}

void calculate_V_T(float first_V, float second_V, float first_T, float second_T, float* result_V, float* result_T)
{
    float water_density = 997, first_M, second_M;
    first_M = mass_calculation(first_V, water_density);
    second_M = mass_calculation(second_V, water_density);

    *result_V = first_V + second_V;
    *result_T = (first_M * first_T + second_M * second_T) / (first_M + second_M);
}

float mass_calculation(float V, float density)
{
    return V * density;
}