#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "film.h"
#include "film_array.h"


#define MAX_ARGC_COUNTER 4
#define MIN_ARGC_COUNTER 3
#define KEY_POSITION 3
#define FIELD_POSITION 2
#define FILE_POSITION 1


int handle_args(int argc, char **argv, int (**cmp)(const void *, const void *), film_t *key_element);


int main(int argc, char **argv)
{
    int rc = OK;
    if (argc != MAX_ARGC_COUNTER && argc != MIN_ARGC_COUNTER)
        rc = ERR_INVALID_ARGC_N;
    else
    {
        FILE *f = NULL;
        if ((f = fopen(argv[FILE_POSITION], "r")) == NULL)
            rc = ERR_FILE;
        else
        {
            film_t arr[N_MAX];
            size_t len = 0;
            film_t key_element = { .title = "", .name = "", .year = -1 };
            int (*cmp)(const void *, const void *);

            if ((rc = handle_args(argc, argv, &cmp, &key_element)) == OK)
                if ((rc = fa_read(f, arr, &len, cmp)) == OK)
                {
                    if (argc == MIN_ARGC_COUNTER)
                        fa_print(arr, len);
                    else
                        fa_bin_search(arr, len, cmp, &key_element);
                }
        }
        if (rc != ERR_FILE)
            fclose(f);
    }
    return rc;
}


int handle_args(int argc, char **argv, int (**cmp)(const void *, const void *), film_t *key_element)
{
    int rc = OK;
    if (!strcmp(argv[FIELD_POSITION], "year"))
    {
        *cmp = film_cmp_year;
        if (argc == MAX_ARGC_COUNTER && sscanf(argv[KEY_POSITION], "%d", &key_element->year) != 1)
            rc = ERR_DATA;
    }
    else if (!strcmp(argv[FIELD_POSITION], "title"))
    {
        *cmp = film_cmp_title;
        if (argc == MAX_ARGC_COUNTER)
            strcpy(key_element->title, argv[KEY_POSITION]);
    }
    else if (!strcmp(argv[FIELD_POSITION], "name"))
    {
        *cmp = film_cmp_name;
        if (argc == MAX_ARGC_COUNTER)
            strcpy(key_element->name, argv[KEY_POSITION]);
    }
    else
        rc = ERR_PROCESS;
    return rc;
}
