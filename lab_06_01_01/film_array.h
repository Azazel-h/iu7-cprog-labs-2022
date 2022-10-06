/** @file film_array.h
 *
 *  Описание работы с массивом объектов film_t
 *
 *  @author Булгаков Арсений
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
 * @param f - Указатель на файловую переменную
 * @param fa_pointer - Указатель на массив структурных переменных типа file_t
 * @param n - Указатель на переменную размера массива
 * @param cmp - Указатель на функцию сравнения двух переменных типа file_t
 * @return Код возврата "OK" при успешном выполнении, иначе "ERR_DATA" / "ERR_IO" / "ERR_OVERFLOW"
 */
int fa_read(FILE *f, film_t *fa_pointer, size_t *n, int (*cmp)(const void *, const void *));


/**
 * @param fa_pointer - Указатель на массив структурных переменных типа file_t
 * @param n - Указатель на переменную размера массива
 * @param item - Указатель на переменную нового объекта типа file_t
 * @param cmp - Указатель на функцию сравнения двух переменных типа file_t
 */
void fa_insert(film_t *fa_pointer, size_t *n, film_t *item, int (*cmp)(const void *, const void *));


/**
 * @param fa_pointer - Указатель на массив структурных переменных типа file_t
 * @param n - Указатель на переменную размера массива
 */
void fa_print(film_t *fa_pointer, size_t n);


/**
 * @param fa_pointer - Указатель на массив структурных переменных типа file_t
 * @param n - Указатель на переменную размера массива
 * @param cmp - Указатель на функцию сравнения двух переменных типа file_t
 * @param key - Указатель на пустую структурную переменную с ключевым значением
 */
void fa_bin_search(film_t *fa_pointer, size_t n, int (*cmp)(const void *, const void *), film_t *key);


#endif //FILM_ARRAY_H
