#include "sort.h"

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);

/**
 * merge_subarr - sort  subarray of int.
 * @subarr: subarray of  array of integers to sort.
 * @buff:  buf to store the sorted subarray.
 * @front:  front index of the array.
 * @mid:  middle index of the array.
 * @back:  back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t h, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (h = front, j = mid; h < mid && j < back; k++)
		buff[k] = (subarr[h] < subarr[j]) ? subarr[h++] : subarr[j++];
	for (; h < mid; h++)
		buff[k++] = subarr[h];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (h = front, k = 0; h < back; h++)
		subarr[h] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - implement merge sort algorithm 2ough recursion.
 * @subarr:  subarray of an array of int to sort.
 * @buff:  buffer to store sorted result.
 * @front:  front index of subarray.
 * @back: back index of  subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort  array of int in ascending
 *              order using the merge sort algorithm.
 * @array: array of int
 * @size:  size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
