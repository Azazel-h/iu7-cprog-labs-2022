#include "lab_05_02_00.h"


int main(int argc, char **argv)
{
    FILE *f;
    if (argc != ARGC_COUNTER)
        return ARGC_ERROR;
    if ((f = fopen(argv[F_NAME_POSITION], "r")) == NULL)
        return INPUT_ERROR;

    size_t len = 0;
    float sum = 0;
    get_sum(f, &sum, &len);
    if (len == 0)
        return EMPTY_ERROR;
    float avg = sum / len;
    closest_avg(f, avg);

    fclose(f);
    return OK;
}
