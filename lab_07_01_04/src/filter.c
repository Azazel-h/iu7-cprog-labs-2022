#include "errors.h"
#include "filter.h"
#include "array.h"


static bool validate_key_pointers(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    return (pb_src != NULL && pe_src != NULL && pb_dst != NULL && pe_dst != NULL) && (pb_src < pe_src);
}


static void get_number_of_filter_elements(const int *pb_src, const int *pe_src, size_t *result)
{
    double avg = count_avg_array(pb_src, pe_src);
    const int *pa = pb_src;

    while (pa < pe_src)
    {
        if (*pa > avg)
        {
            (*result)++;
        }
        pa++;
    }
}


static int copy_filter_elements(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, size_t res_len)
{
    int rc = OK;
    double avg = count_avg_array(pb_src, pe_src);

    if ((rc = allocate_int_array(res_len, pb_dst, pe_dst)) == OK)
    {
        const int *pa = pb_src;
        int *pd = *pb_dst;

        while (pa < pe_src && pd < *pe_dst)
        {
            if (*pa > avg)
            {
                *pd = *pa;
                pd++;
            }
            pa++;
        }
    }
    return rc;
}


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK;

    if (validate_key_pointers(pb_src, pe_src, pb_dst, pe_dst))
    {
        size_t number_of_elements = 0;
        get_number_of_filter_elements(pb_src, pe_src, &number_of_elements);

        rc = copy_filter_elements(pb_src, pe_src, pb_dst, pe_dst, number_of_elements);
    }
    else
        rc = ERR_PROCESS;

    return rc;
}
