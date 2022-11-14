#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void mysort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));

#endif //SORT_H
