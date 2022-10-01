/** @file film_array.h
 *  @brief Function prototypes for the film_t ARRAY
 *
 *  This contains the prototypes for the film_t ARRAY
 *
 *  @author Arseniy Bulgakov (yasuhiro)
 */

#ifndef FILM_ARRAY_H
#define FILM_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"
#include "errors.h"

#define N_MAX 15


/**
 * @brief Reads all films from file to array of film_t structs
 * @param f - Pointer to file
 * @param fa_pointer - Pointer to array of structs
 * @param n - Pointer to len variable for an array
 * @param cmp - Function pointer which describe "how to compare films"
 * @return Return code OK if no errors, otherwise ERR_DATA / ERR_IO / ERR_OVERFLOW
 */
int fa_read(FILE *f, film_t *fa_pointer, size_t *n, int (*cmp)(const void *, const void *));


/**
 * @brief Inserts film to an array. It will be always sorted, every element is inserted by cmp check.
 * @param fa_pointer - Pointer to array of structs
 * @param n - Pointer to len variable for array
 * @param item - Pointer to new item which should be inserted
 * @param cmp - Function pointer which describe "how to compare films"
 */
void fa_insert(film_t *fa_pointer, size_t *n, film_t *item, int (*cmp)(const void *, const void *));


/**
 * @brief Prints full film array to terminal
 * @param fa_pointer - Pointer to array of structs
 * @param n - Len variable of array
 */
void fa_print(film_t *fa_pointer, size_t n);


/**
 * @brief Finds key in film array
 * @param fa_pointer - Pointer to array of structs
 * @param n - Len variable of array
 * @param cmp - Function pointer which describe "how to compare films"
 * @param key - Pointer to an empty struct with key values
 */
void fa_bin_search(film_t *fa_pointer, size_t n, int (*cmp)(const void *, const void *), film_t *key);


#endif //FILM_ARRAY_H
