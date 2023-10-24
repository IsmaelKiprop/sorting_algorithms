#include "sort.h"
void swap_bitonic(int *arr, int a, int b);
void recBitonicSort(int *arr, int lo, int cnt, int dir, size_t n);
void bitonicMerge(int *arr, int lo, int cnt, int dir, size_t n);


/**
 * bitonic_sort - sort bitonic sort algm
 * @array: sort
 * @size: array
 */
void bitonic_sort(int *array, size_t size)
{
	recBitonicSort(array, 0, size, 1, size);
}

/**
 * swap_bitonic - swap value of array element
 * @arr: array
 * @x: index nod array to swap data
 * @y: index nod array to swap data
 */
void swap_bitonic(int *arr, int x, int y)
{
	int w;

	w = arr[x];
	arr[x] = arr[y];
	arr[y] = w;
}

/**
 * bitonicMerge - swap merge splitted array
 * @arr: array
 * @lo: index
 * @cnt: index
 * @dir: 1 for ascending swapping 0 for descending
 */
void bitonicMerge(int *arr, int lo, int cnt, int dir, size_t n)
{
	int v, u;

	if (cnt > 1)
	{
		u = cnt / 2;
		for (v = lo; v < lo + u; v++)
		{
			if (dir == (arr[v] > arr[v + u]))
			{
				swap_bitonic(arr, v, v + u);
				print_array(arr, n);
			}
		}
		bitonicMerge(arr, lo, u, dir, n);
		bitonicMerge(arr, lo + u, u, dir, n);
	}
}

/**
 * recBitonicSort - split sort recursively
 * @arr: array
 * @lo: index
 * @cnt: index
 * @dir: 1 for ascending swapping 0 for descending
 * @n: array size
 */
void recBitonicSort(int *arr, int lo, int cnt, int dir, size_t n)
{
	int u;

	if (cnt > 1)
	{
		u = cnt / 2;
		recBitonicSort(arr, lo, u, 1, n);
		recBitonicSort(arr, lo + u, u, 0, n);
		bitonicMerge(arr, lo, cnt, dir, n);
	}
}
