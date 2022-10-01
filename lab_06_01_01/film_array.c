#include "film_array.h"


int fa_read(FILE *f, film_t *fa_pointer, size_t *n, int (*cmp)(const void *, const void *))
{
    film_t item;
    *n = 0;
    int rc = OK;

    while (!feof(f) && rc == OK)
    {
        rc = film_read(f, &item);
        if (rc == OK)
        {
            if (*n < N_MAX)
                fa_insert(fa_pointer, n, &item, cmp);
            else
                rc = ERR_OVERFLOW;
        }
    }
    return rc;
}


void fa_insert(film_t *fa_pointer, size_t *n, film_t *item, int (*cmp)(const void *, const void *))
{
    if (*n == 0)
    {
        fa_pointer[0] = *item;
        (*n)++;
    }
    else
    {
        int is_grater = 0;
        for (size_t i = 0; !is_grater && i < *n; i++)
        {
            if (cmp(item, fa_pointer + i) < 0)
            {
                memmove(&fa_pointer[i + 1], &fa_pointer[i], (*n - i) * sizeof(film_t));
                (*n)++;
                fa_pointer[i] = *item;
                is_grater = 1;
            }
        }
        if (!is_grater)
        {
            fa_pointer[*n] = *item;
            (*n)++;
        }
    }
}


void fa_bin_search(film_t *fa_pointer, size_t n, int (*cmp)(const void *, const void *), film_t *key)
{
    size_t l = 0, r = n - 1;
    size_t mid;
    int cmp_result;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        cmp_result = cmp(fa_pointer + mid, key);
        if (cmp_result == 0)
        {
            film_print(fa_pointer + mid);
            return;
        }
        else if (cmp_result < 0)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("Not found\n");
}


void fa_print(film_t *fa_pointer, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        film_print(fa_pointer + i);
}
