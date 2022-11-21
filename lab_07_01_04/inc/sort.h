#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Функция сортировки вставкой с бинарным поиском
 * @param ptr[in] - Указатель на начало массива для сортировки
 * @param count[in] - Количество элементов массива для сортировки
 * @param size[in] - Размер элемента массива
 * @param comp[in] - Функция сравнения элементов массива
 */
void mysort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));

#endif //SORT_H
