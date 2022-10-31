#include "errors.h"
#include "filter.h"
#include "array.h"


bool validate_key_pointers(const int *pb_src, const int *pe_src, const int *pb_dst, const int *pe_dst)
{
    return pb_src != NULL && pe_src != NULL && pb_dst == NULL && pe_dst == NULL;
}


void get_number_of_filter_elements(const int *pb_src, const int *pe_src, size_t *result)
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


void copy_filter_elements(const int *pb_src, const int *pe_src, int *pb_dst)
{
    double avg = count_avg_array(pb_src, pe_src);
    const int *pa = pb_src;
    int *pd = pb_dst;

    while (pa < pe_src)
    {
        if (*pa > avg)
        {
            *pd = *pa;
            pd++;
        }
        pa++;
    }
}


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK;

    if (validate_key_pointers(pb_src, pe_src, *pb_dst, *pe_dst))
    {
        size_t number_of_elements = 0;
        get_number_of_filter_elements(pb_src, pe_src, &number_of_elements);

        *pb_dst = malloc(sizeof(int) * number_of_elements);
        if (*pb_dst != NULL)
        {
            *pe_dst = *pb_dst + number_of_elements;
            copy_filter_elements(pb_src, pe_src, *pb_dst);
        }
        else
            rc = ERR_ALLOCATION;
    }
    else
        rc = ERR_PROCESS;

    return rc;
}
