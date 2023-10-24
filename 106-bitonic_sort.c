#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bitonic_merge(int *array, size_t size, size_t low, size_t cnt, int dir) {
    if (cnt > 1) {
        size_t k = cnt / 2;
        for (size_t i = low; i < low + k; i++) {
            if ((array[i] > array[i + k]) == dir) {
                swap(&array[i], &array[i + k]);
                printf("Merging [%lu/%lu] (%s):\n", cnt, size, dir == 1 ? "UP" : "DOWN");
                print_array(array, size);
            }
        }
        bitonic_merge(array, size, low, k, dir);
        bitonic_merge(array, size, low + k, k, dir);
    }
}

void bitonic_sort_recursive(int *array, size_t size, int dir) {
    if (size > 1) {
        size_t half = size / 2;
        bitonic_sort_recursive(array, half, 1);
        bitonic_sort_recursive(array + half, half, 0);
        bitonic_merge(array, size, 0, size, dir);
    }
}

void bitonic_sort(int *array, size_t size) {
    bitonic_sort_recursive(array, size, 1);
}
