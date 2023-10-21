#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct listint_s - Doubly link list node
 *
 * @n: Int stored in node
 * @prev: Pointer to previous element of list
 * @next: Pointer to next element of list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void swap(listint_t **);
void swap_back(listint_t **);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_arr(int *a, int *b);
int partition(int *array, int firstIndex, int lastIndex, size_t size);
void quickSort(int *array, int firstIndex, int lastIndex, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void cocktailSort(listint_t **list, int direction);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif /*SORT_H*/
