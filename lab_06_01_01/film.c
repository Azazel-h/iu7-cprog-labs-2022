#include <string.h>
#include "film.h"


int read_buf(FILE *f, char *buf)
{
    if (!fgets(buf, sizeof(buf), f))
        return ERR_IO;

    size_t len = strlen(buf);
    if (len && buf[len - 1] == '\n')
    {
        buf[len - 1] = '\0';
        len--;
    }
    if (!len || len > TITLE_LEN)
        return ERR_DATA;

    return OK;
}


int film_read(FILE *f, film_t *film_pointer)
{
    char buf_title[TITLE_LEN + 3], buf_name[SURNAME_LEN + 3];
    char tmp[2];
    int year;

    if (read_buf(f, buf_title) != OK || read_buf(f, buf_name) != OK)
        return ERR_DATA;

    if (fscanf(f, "%d", &year) != 1)
        return ERR_IO;
    else if (year <= 0)
        return ERR_DATA;

    fgets(tmp, sizeof(tmp), f);
    strcpy(film_pointer->title, buf_title);
    strcpy(film_pointer->name, buf_name);
    film_pointer->year = year;

    return OK;
}


void film_print(film_t *film_pointer)
{
    printf("%s %s %d\n", film_pointer->title, film_pointer->name, film_pointer->year);
}


int film_cmp_title(const void *l, const void *r)
{
    film_t *film_l = (film_t *) l;
    film_t *film_r = (film_t *) r;

    return strcmp(film_l->title, film_r->title);
}


int film_cmp_name(const void *l, const void *r)
{
    film_t *film_l = (film_t *) l;
    film_t *film_r = (film_t *) r;

    return strcmp(film_l->name, film_r->name);
}


int film_cmp_year(const void *l, const void *r)
{
    film_t *film_l = (film_t *) l;
    film_t *film_r = (film_t *) r;

    return film_l->year - film_r->year;
}