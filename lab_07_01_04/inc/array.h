/** @file array.h
 *
 *  Описание работы с массивом целых чисел
 *
 *  @author Булгаков Арсений
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>


/**
 * Функция сравенения целых чисел для
 * @param l[in] - Указатель на первое число
 * @param r[in] - Указатель на второе число
 * @return Разность двух чисел
 */
int int_cmp(const void *l, const void *r);

/**
 * Функция выделения памяти под целочисленный массив длинны len
 * @param len[in] - Длинна массив
 * @param pb[in,out] - Указатель на начало массива
 * @param pe[in,out] - Указатель на конец массива
 * @return Код возврата "OK" при успешном выполнении, иначе "ERR_ALLOCATION" / "ERR_ARR_LEN"
 */
int allocate_int_array(size_t len, int **pb, int **pe);

/**
 * Функция освобождения памяти
 * @param pb[in,out] - Указатель на начало массива
 * @param pe[in,out] - Указатель на конец массива
 */
void free_int_array(int **pb, int **pe);

/**
 * Функция для подсчета целочисленных элементов в массиве
 * @param f[in] - Указатель на файловую переменную
 * @param len[in, out] - Указатель на переменную для хранения количества целочисленных элементов
 * @return Код возврата "OK" при успешном выполнении, иначе "ERR_DATA"
 */
int file_count_int_array_elements(FILE *f_i, size_t *len);

/**
 * Функция для считывания целочисленных элементов из файла в массив
 * @param f[in] - Указатель на файловую переменную
 * @param pb[in] - Указатель на начало массива
 * @param pe[in] - Указатель на конец массива
 * @return Код возврата "OK" при успешном выполнении, иначе "ERR_DATA"
 */
int file_read_int_array(FILE *f_i, const int *pb, const int *pe);

/**
 * Функция для подсчета среднего арифметического массива целых числ
 * @param pb[in] - Указатель на начало массива
 * @param pe[in] - Указатель на конец массива
 * @return Значение среднего арифметического типа double
 */
double count_avg_array(const int *pb_src, const int *pe_src);

/**
 * Функция для записи целочисленного массива в файл
 * @param f[in] - Указатель на файловую переменную
 * @param pb[in] - Указатель на начало массива
 * @param pe[in] - Указатель на конец массива
 */
void file_write_int_array(FILE *f_o, const int *pb, const int *pe);

#endif //ARRAY_H
