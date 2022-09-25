/** @file film.h
 *  @brief Struct and function prototypes for the film_t object
 *
 *  This contains the prototypes for the film_t objects
 *
 *  @author Arseniy Bulgakov (yasuhiro)
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
 * @brief Reads film data from file to struct variable of film_t
 * @param f - Pointer to file
 * @param film_pointer - Pointer to struct variable of film_t to store new data
 * @return Return code OK if no errors, otherwise ERR_DATA / ERR_IO
 */
int film_read(FILE *f, film_t *film_pointer);


/**
 * @brief Prints film data to terminal
 * @param film_pointer - Pointer to struct variable of film_t with film data
 */
void film_print(film_t *film_pointer);


/**
 * @brief Compares two films by title
 * @param l - First film pointer to compare
 * @param r - Second film pointer to compare
 * @return strcmp of two titles
 */
int film_cmp_title(const void *l, const void *r);


/**
 * @brief Compares two films by name
 * @param l - First film pointer to compare
 * @param r - Second film pointer to compare
 * @return strcmp of two names
 */
int film_cmp_name(const void *l, const void *r);


/**
 * @brief Compares two films by year
 * @param l - First film pointer to compare
 * @param r - Second film pointer to compare
 * @return l.year - r.year
 */
int film_cmp_year(const void *l, const void *r);


#endif //FILMS_H
