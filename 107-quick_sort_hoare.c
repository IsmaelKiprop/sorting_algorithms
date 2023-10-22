#include "sort.h"

int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void swap_ints(int *a, int *b);


/**
 * swap_ints -swp two int in an array.
 * @a: first int to swap.
 * @b:  second int to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order subset of  array of int
 *                   according to hoare partition scheme.
 * @array: array of int
 * @size:  size of the array.
 * @left: starting index of  subset to order.
 * @right:  ending index of  subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses last element of the partition as the pivot.
 * Prints  array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement  quicksort algorithm through recursion.
 * @array: An array of int to sort.
 * @size: size of  array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - sort  array of int in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of int
 * @size: The size of the array.
 *
 * Description: Uses  Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
