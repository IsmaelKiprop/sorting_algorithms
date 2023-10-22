#include "sort.h"

/**
* quick_sort - quick sort algm
* @array: sort
* @size: array
*/

void quick_sort(int *array, size_t size)
{
	int firstIndex, lastIndex;

	firstIndex = 0;
	lastIndex = size - 1;

	if (size < 2)
		return;

	quickSort(array, firstIndex, lastIndex, size);
}

/**
* quickSort - Quicksort Algorithm
* @array: sort
* @firstIndex: array
* @lastIndex: array
* @size: array
*/
void quickSort(int *array, int firstIndex, int lastIndex, size_t size)
{
	int part;

	if (firstIndex < lastIndex)
	{
		part = partition(array, firstIndex, lastIndex, size);

		quickSort(array, firstIndex, part - 1, size);
		quickSort(array, part + 1, lastIndex, size);
	}
}

/**
* partition -  array
* @array: partition
* @firstIndex: each partition
* @lastIndex: each partition
* @size: array
* Return: lastindex of partition array
*/
int partition(int *array, int firstIndex, int lastIndex, size_t size)
{
	int m, n, pivot;

	pivot = array[lastIndex];
	m = firstIndex;

	for (n = firstIndex; n < lastIndex; n++)
	{
		if (array[n] <= pivot)
		{
			swap_arr(&array[m], &array[n]);
			if (m != n)
				print_array(array, size);
			m++;
		}
	}
	swap_arr(&array[m], &array[lastIndex]);
	if (m != n)
		print_array(array, size);
	return (m);
}

/**
* swap_arr - data
* @a: ptr to data a
* @b: ptr to data b
*/
void swap_arr(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
