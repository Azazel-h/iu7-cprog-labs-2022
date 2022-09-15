#include "lab_05_01_05.h"

int process(FILE *f, size_t *max_eq_len)
{
    int num, prev;
    if (fscanf(f, "%d", &prev) == CORRECT_INPUT)
    {
        size_t cur_len = 1;
        while (fscanf(f, "%d", &num) == CORRECT_INPUT)
        {
            if (num == prev)
                cur_len++;
            else
                cur_len = 1;

            if (cur_len > *max_eq_len)
                *max_eq_len = cur_len;
            prev = num;
        }
        return OK;
    }
    return INPUT_ERROR;
}
