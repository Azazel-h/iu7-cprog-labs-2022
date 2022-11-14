#include "sort.h"


static int bin_search(void *ptr, size_t size, void *key, int l, int r, int (*cmp)(const void *, const void *))
{
    int mid = r / 2, cmp_result;

    while (l <= r)
    {
        cmp_result = cmp(key, (char *) ptr + (mid * size));
        if (cmp_result > 0)
            l = mid + 1;
        else if (cmp_result < 0)
            r = mid - 1;
        else
            break;

        mid = l + (r - l) / 2;
    }

    return mid;
}


void mysort(void *pbase, size_t total_elems, size_t size, int (*cmp)(const void *, const void *))
{
    int ins;
    char *pb = pbase;
    char tmp[size];

    for (size_t i = 0; i < total_elems; ++i)
    {
        ins = bin_search(pb, size, pb + i * size, 0, (int) i, cmp);
        memmove(tmp, pb + i * size, size);
        memmove(pb + (ins + 1) * size, pb + ins * size, (i - ins) * size);
        memmove(pb + ins * size, tmp, size);
    }
}
