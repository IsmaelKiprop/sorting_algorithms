#include "sort.h"

void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);

/**
 * get_max - get max value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum int in the array.
 */
int get_max(int *array, int size)
{
	int max, h;

	for (max = array[0], h = 1; h < size; h++)
	{
		if (array[h] > max)
			max = array[h];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort significant digits of  array of int
 *                       in ascending order using the counting sort algorithm.
 * @array:  array of int
 * @size:  size of the array.
 * @sig:  significant digit to sort on.
 * @buff:  buff to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t h;

	for (h = 0; h < size; h++)
		count[(array[h] / sig) % 10] += 1;

	for (h = 0; h < 10; h++)
		count[h] += count[h - 1];

	for (h = size - 1; (int)h >= 0; h--)
	{
		buff[count[(array[h] / sig) % 10] - 1] = array[h];
		count[(array[h] / sig) % 10] -= 1;
	}

	for (h = 0; h < size; h++)
		array[h] = buff[h];
}

/**
 * radix_sort - array of int in ascending
 *              order using the radix sort algorithm.
 * @array:  array of integers.
 * @size: size of the array.
 *
 * Description: Implements  LSD radix sort algorithm. Prints
 * array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
