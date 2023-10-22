#include "sort.h"

/**
 * get_max - getmaximum value in  array of int
 * @array: array of int
 * @size:  size of the array.
 *
 * Return:  max integer in the array.
 */
int get_max(int *array, int size)
{
	int max, y;

	for (max = array[0], y = 1; y < size; y++)
	{
		if (array[y] > max)
			max = array[y];
	}

	return (max);
}

/**
 * counting_sort - sort array of int in ascending order
 *                 using the count sort algorithm.
 * @array:  array of int
 * @size:  size of the array.
 *
 * Description: prints  counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, y;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (y = 0; y < (max + 1); y++)
		count[y] = 0;
	for (y = 0; y < (int)size; y++)
		count[array[y]] += 1;
	for (y = 0; y < (max + 1); y++)
		count[y] += count[y - 1];
	print_array(count, max + 1);

	for (y = 0; y < (int)size; y++)
	{
		sorted[count[array[y]] - 1] = array[y];
		count[array[y]] -= 1;
	}

	for (y = 0; y < (int)size; y++)
		array[y] = sorted[y];

	free(sorted);
	free(count);
}
