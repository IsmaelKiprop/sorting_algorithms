#include "sort.h"

/**
* bubble_sort - bubble sort algorithm
* @array: array sort
* @size: array size
*/
void bubble_sort(int *array, size_t size)
{
	size_t v, w;
	int temp, sorted = 0;

	for (w = 0; w < size; w++)
	{
		for (v = 0; v < size; v++)
		{
			if (v < size - 1)
			{
				if (array[v] > array[v + 1])
				{
					temp = array[v];
					array[v] = array[v + 1];
					array[v + 1] = temp;
					sorted = 1;
					print_array(array, size);
				}
			}
		}
		if (sorted == 0)
			break;
	}
}
