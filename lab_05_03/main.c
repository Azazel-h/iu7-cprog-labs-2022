#include "lab_05_03.h"

/*
 * int
 * bubble_sort
 * descending
 */

int main(int argc, char **argv)
{
    int rc = OK;
    time_t t;

    srand((unsigned) time(&t));

    if (argc != ARGC_COUNTER && argc != ARGC_COUNTER - 1)
        rc = INVALID_ARGC_N;

    FILE *f = NULL;
    if (!rc)
    {
        if (!strcmp(argv[MODE_POSITION], "c"))
        {
            if ((f = fopen(argv[argc - 1], "ab")) == NULL)
                rc = INPUT_ERROR;
            else if (argc == ARGC_COUNTER)
                rc = add_num(f, atol(argv[COUNT_POSITION]));
        }
        else if (!strcmp(argv[MODE_POSITION], "p"))
        {
            if ((f = fopen(argv[argc - 1], "rb")) == NULL)
                rc = INPUT_ERROR;
            else
                print_nums(f);
        }
        else if (!strcmp(argv[MODE_POSITION], "s"))
        {
            if ((f = fopen(argv[argc - 1], "rb+")) == NULL)
                rc = INPUT_ERROR;
            else
                rc = bubbles_sort(f);
        }
        else
            rc = PROCESS_ERROR;
    }

    fclose(f);
    return rc;
}

