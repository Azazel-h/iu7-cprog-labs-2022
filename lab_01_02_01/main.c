//
// Created by Azazel on 28.02.2022.
//

#include <stdio.h>
#include <math.h>

float calculate_s(float a, float b, float fi);

int main(void)
{
    float a, b, fi;
    printf("Введите величины оснований A и B и угла в градусах Fi при большем основании равнобедренной трапеции: ");
    scanf("%f%f%f", &a, &b, &fi);
    printf("S: %f", calculate_s(a, b, fi));
}

float calculate_s(float a, float b, float fi)
{

    return a * b * sinf(fi);
};