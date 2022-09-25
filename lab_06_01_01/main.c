#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "film.h"
#include "film_array.h"


#define ARGC_COUNTER 4
#define KEY_POSITION 3
#define FIELD_POSITION 2
#define FILE_POSITION 1


int main(int argc, char **argv)
{
    int rc = OK;

    if (argc != ARGC_COUNTER && argc != ARGC_COUNTER - 1)
        rc = ERR_INVALID_ARGC_N;

    FILE *f = NULL;

    if ((f = fopen(argv[FILE_POSITION], "r")) == NULL)
        rc = ERR_FILE;


    if (!rc)
    {
        film_t arr[N_MAX];
        size_t len = 0;
        film_t key_element = { .title = "", .name = "", .year = -1 };

        if (!strcmp(argv[FIELD_POSITION], "year"))
        {
            if (!(rc = fa_read(f, arr, &len, film_cmp_year)) && argc == ARGC_COUNTER)
            {
                key_element.year = atoi(argv[KEY_POSITION]);
                fa_bin_search(arr, len, film_cmp_year, &key_element);
            }
            else if (!rc)
                fa_print(arr, len);
        }
        else if (!strcmp(argv[FIELD_POSITION], "title"))
        {
            if (!(rc = fa_read(f, arr, &len, film_cmp_title)) && argc == ARGC_COUNTER)
            {
                strcpy(key_element.title, argv[KEY_POSITION]);
                fa_bin_search(arr, len, film_cmp_title, &key_element);
            }
            else if (!rc)
                fa_print(arr, len);
        }
        else if (!strcmp(argv[FIELD_POSITION], "name"))
        {
            if (!(rc = fa_read(f, arr, &len, film_cmp_name)) && argc == ARGC_COUNTER)
            {
                strcpy(key_element.name, argv[KEY_POSITION]);
                fa_bin_search(arr, len, film_cmp_name, &key_element);
            }
            else if (!rc)
                fa_print(arr, len);
        }
        else
            rc = ERR_PROCESS;
    }

    if (rc != ERR_FILE)
        fclose(f);
    return rc;
}
