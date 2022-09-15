#include "lab_05_02_00.h"


void get_sum(FILE *f, float *sum, size_t *len)
{
    float num;
    while (fscanf(f, "%f", &num) == CORRECT_INPUT)
    {
        *sum += num;
        (*len)++;
    }
}

void closest_avg(FILE *f, float avg)
{
    float min, num;
    fseek(f, 0, SEEK_SET);
    fscanf(f, "%f", &min);
    while (fscanf(f, "%f", &num) == CORRECT_INPUT)
        if (fabs(num - avg) < fabs(min - avg))
            min = num;
    printf("%f", min);
}
