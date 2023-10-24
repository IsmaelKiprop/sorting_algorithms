
#include "sort.h"
void swap_ints(int *j, int *w);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two int in array.
 * @j: first int to swap.
 * @w: second int to swap.
 */
void swap_ints(int *j, int *w)
{
	int tmp;

	tmp = *j;
	*j = *w;
	*w = tmp;
}

/**
 * bitonic_merge - Sort bitonic sequence inside array of integers.
 * @array: integers.
 * @size: array.
 * @start: index of sequence in array to sort.
 * @seq: The size sequence to sort.
 * @flow: direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t v, jump = seq / 2;

	if (seq > 1)
	{
		for (v = start; v < start + jump; v++)
		{
			if ((flow == UP && array[v] > array[v + jump]) ||
			    (flow == DOWN && array[v] < array[v + jump]))
				swap_ints(array + v, array + v + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert array of int into bitonic sequence.
 * @array: integers.
 * @size: array.
 * @start: The starting index of a block of building bitonic sequence.
 * @seq: The size of block of building bitonic sequence.
 * @flow: The direction to sort bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of int in ascending
 *                order using bitonic sort algorithm.
 * @array: integers.
 * @size: array.
 *
 * Description: Prints array after swap. works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
