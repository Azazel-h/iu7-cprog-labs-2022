#include <stdio.h>
#include <math.h>

float calculate_s(float a, float b, float fi);
float degree_to_radian(float degree);

int main(void)
{
    float a, b, fi;
    printf("Введите величины оснований A и B и угла в градусах Fi при большем основании равнобедренной трапеции: ");
    scanf("%f%f%f", &a, &b, &fi);
    printf("S: %f", calculate_s(a, b, fi));
}

float calculate_s(float a, float b, float fi)
{
    return fabs((a * a - b * b) * tan(degree_to_radian(fi))) / 4;
}

float degree_to_radian(float degree)
{
    return degree * (M_PI / 180.0);
}