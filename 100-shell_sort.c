#include "sort.h"

/**
* knuth_seq - Get gaps with knuth sequence
* @size: size of array
* Return: array holding gaps
*/
size_t knuth_seq(size_t size)
{
	size_t i, j;
	size_t largst_gap;

	for (i = 1, j = 0; i < size; i = i * 3 + 1, j++)
	{
		largst_gap = i;
	}
	return (largst_gap);
}

/**
* shell_sort - Sorts array integers
* @array: to be sorted
* @size:  array
* Return: Void
*/
void shell_sort(int *array, size_t size)
{
	size_t x, y, z, gap;
	int tmp;

	if (array == NULL || size == 0)
	{
		return;
	}

	gap = knuth_seq(size);
	for (x = gap; x > 0; x = (x - 1) / 3)
	{
		for (y = x; y < size; y++)
		{
			tmp = array[y];
			for (z = y; (z >= x) && (array[z - x] > tmp); z -= x)
				array[z] = array[z - x];
			array[z] = tmp;
		}
		print_array(array, size);
	}
}
