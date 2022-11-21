#ifndef FILTER_H
#define FILTER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Функция фильтрации массива целых чисел по признаку "оставить числа больше среднего арифметического"
 * @param pb_src[in] - Указатель на начало изначального массива
 * @param pe_src[in] - Указатель на конец изначального массива
 * @param pb_dst[in,out] - Указатель на начало массива после фильтрации
 * @param pe_dst[in,out] - Указатель на конец массива после фильтрации
 * @return Код возврата "OK" при успешном выполнении, иначе "ERR_PROCESS"
 */
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif //FILTER_H
