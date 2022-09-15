#include "lab_05_03.h"


int get_number_by_pos(FILE *f, long index, int *num)
{
    int rc = OK;
    fseek(f, 0, SEEK_END);
    if (ftell(f) <= index * (long) sizeof(int))
        rc = INDEX_ERROR;

    if (!rc)
    {
        fseek(f, index * sizeof(int), SEEK_SET);
        if (fread(num, sizeof(int), 1, f) != CORRECT_INPUT)
            rc = VALUE_ERROR;
    }

    return rc;
}


int put_number_by_pos(FILE *f, long index, int *num)
{
    int rc = OK;
    fseek(f, 0, SEEK_END);
    if (ftell(f) <= index * (long) sizeof(int))
        rc = INDEX_ERROR;

    if (!rc)
    {
        fseek(f, index * sizeof(int), SEEK_SET);
        if (!fwrite(num, sizeof(int), 1, f))
            rc = VALUE_ERROR;
    }

    return rc;
}


int validate_f_size(FILE *f)
{
    int rc = OK;
    size_t size;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    if (size % sizeof(int) || size == 0)
        rc = FILE_ERROR;

    return rc;
}


int add_num(FILE *f, size_t count)
{
    int rc = OK, t;
    for (size_t i = 0; i < count && rc == OK; ++i)
    {
        t = rand() % MAX;
        if (!fwrite(&t, sizeof(int), 1, f))
            rc = WRITE_ERROR;
    }
    return rc;
}


void print_nums(FILE *f)
{
    int n;
    fseek(f, 0, SEEK_SET);
    while (fread(&n, sizeof(int), 1, f) == CORRECT_INPUT)
        printf("%d ", n);
}


int bubbles_sort(FILE *f)
{
    int rc = OK;
    if (!(rc = validate_f_size(f)))
    {
        fseek(f, 0, SEEK_END);
        long n = ftell(f) / (long) sizeof(int);
        int a, b;

        for (long i = 0; i < n - 1 && rc == OK; ++i)
            for (long j = i + 1; j < n && rc == OK; ++j)
            {
                if (get_number_by_pos(f, i, &a) != OK || get_number_by_pos(f, j, &b) != OK)
                    rc = INDEX_ERROR;
                if (a < b)
                    if (put_number_by_pos(f, i, &b) != OK || put_number_by_pos(f, j, &a) != OK)
                        rc = VALUE_ERROR;
            }
    }
    return rc;
}


