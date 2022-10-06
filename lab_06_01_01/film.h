/** @file film.h
 *
 *  Описание объектов типа film_t
 *
 *  @author Булгаков Арсений
 */

#ifndef FILMS_H
#define FILMS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"

#define MAX_LEN 25

typedef struct
{
    char title[MAX_LEN + 1];
    char name[MAX_LEN + 1];
    int year;
} film_t;


/**
 * @param f - Указатель на файловую переменную
 * @param film_pointer - Указатель на структурную переменную типа film_t для хранения новых данных
 * @return Код возврата "OK" при успешном выполнении, иначе "ERR_DATA" / "ERR_IO"
 */
int film_read(FILE *f, film_t *film_pointer);


/**
 * @param film_pointer - Указатель на структурную переменную с данными фильма
 */
void film_print(film_t *film_pointer);


/**
 * @param l - Указатель на первую структурную переменну для сравнения
 * @param r - Указатель на вторую структурную переменную для сравнения
 * @return strcmp для двух полей title
 */
int film_cmp_title(const void *l, const void *r);


/**
 * @param l - Указатель на первую структурную переменну для сравнения
 * @param r - Указатель на вторую структурную переменную для сравнения
 * @return strcmp для двух полей names
 */
int film_cmp_name(const void *l, const void *r);


/**
 * @param l - Указатель на первую структурную переменну для сравнения
 * @param r - Указатель на вторую структурную переменную для сравнения
 * @return l.year - r.year
 */
int film_cmp_year(const void *l, const void *r);


#endif //FILMS_H
