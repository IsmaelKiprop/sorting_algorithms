#include "sort.h"

/**
* knuth_seq - gaps with knuth sequence
* @size: array
* Return: array holding gaps
*/
size_t knuth_seq(size_t size)
{
	size_t y, z;
	size_t largst_gap;

	for (y = 1, z = 0; y < size; y = y * 3 + 1, z++)
	{
		largst_gap = y;
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
