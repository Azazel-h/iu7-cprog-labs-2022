#include "lab_05_01_05.h"


int main()
{
    int rc = OK;
    size_t max_len = 1;

    if (process(stdin, &max_len) != 0)
        rc = INPUT_ERROR;
    else
        fprintf(stdout, "%zu", max_len);

    return rc;
}
