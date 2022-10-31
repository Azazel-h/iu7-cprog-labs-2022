#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int bin_search(void *ptr, size_t size, void *key, int l, int r, int (*comp)(const void *, const void *));
void mysort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));

#endif //SORT_H
