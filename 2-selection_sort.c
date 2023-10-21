#include "sort.h"

/**
* selection_sort - Selection sort alg
* @array: array sort
* @size: size array
*/
void selection_sort(int *array, size_t size)
{
	size_t x, y, z;
	int tmp;

	x = 0;
	while (x < size)
	{
		y = x;

		z = x;
		tmp = array[y];
		while (z < size)
		{
			if (tmp > array[z])
			{
				tmp = array[z];
				y = z;
			}
			z++;
		}
		if (y != x)
		{
			array[y] = array[x];
			array[x] = tmp;
			print_array(array, size);
		}
		x++;
	}
}
