#include <stdio.h>
#include <string.h>
#include "array.h"
#include "sort.h"
#include "filter.h"
#include "errors.h"

#define MAX_ARGC_COUNTER 4
#define MIN_ARGC_COUNTER 3
#define FILE_I_POSITION 1
#define FILE_O_POSITION 2
#define F_KEY_POSITION 3


static int validate_args(int argc, char **argv, FILE **f_i, FILE **f_o);


int main(int argc, char **argv)
{
    int rc = OK;
    FILE *f_i = NULL, *f_o = NULL;
    int *pb_src = NULL, *pe_src = NULL;
    int *pb_dst = NULL, *pe_dst = NULL;

    int *pb_main = NULL, *pe_main = NULL;

    if ((rc = validate_args(argc, argv, &f_i, &f_o)) == OK)
    {
        size_t len = 0;
        if ((rc = file_count_int_array_elements(f_i, &len)) == OK)
        {
            rewind(f_i);
            if ((rc = allocate_int_array(len, &pb_src, &pe_src)) == OK &&
                (rc = file_read_int_array(f_i, pb_src, pe_src)) == OK)
            {
                rewind(f_i);
                pb_main = pb_src;
                pe_main = pe_src;
                if (argc == MAX_ARGC_COUNTER)
                {
                    if ((rc = key(pb_src, pe_src, &pb_dst, &pe_dst)) == OK)
                    {
                        pb_main = pb_dst;
                        pe_main = pe_dst;
                    }
                }
                mysort(pb_main, pe_main - pb_main, sizeof(int), int_cmp);
                file_write_int_array(f_o, pb_main, pe_main);
            }
        }

        free_int_array(&pb_src, &pe_src);
        free_int_array(&pb_dst, &pe_dst);
        fclose(f_i);
        fclose(f_o);
    }

    return rc;
}


static int validate_args(int argc, char **argv, FILE **f_i, FILE **f_o)
{
    int rc = OK;
    if (argc != MAX_ARGC_COUNTER && argc != MIN_ARGC_COUNTER)
        rc = ERR_INVALID_ARGC_N;
    else
    {
        *f_i = fopen(argv[FILE_I_POSITION], "r");
        *f_o = fopen(argv[FILE_O_POSITION], "r");

        if (*f_i == NULL || *f_o  == NULL)
            rc = ERR_FILE_PATH;
        else
        {
            fclose(*f_o);
            *f_o = fopen(argv[FILE_O_POSITION], "w");
        }

        if (argc == MAX_ARGC_COUNTER && strcmp(argv[F_KEY_POSITION], "f") != 0)
            rc = ERR_INVALID_ARGC;
    }
    return rc;
}
