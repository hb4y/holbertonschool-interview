#ifndef H_SORT_H
#define H_SORT_H

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

void tmp_hep(int *array, int size, int i, int tmp_size);
void tmp_swap(int *first_v, int *second_v, int *array, int size);

#endif
