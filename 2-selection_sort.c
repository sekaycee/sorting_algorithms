#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm.
 *
 * @array: Given array to be sorted.
 * @size: Number of elements in given array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, swap;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i, swap = 0;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j, swap = array[i];

		if (swap)
		{
			array[i] = array[min], array[min] = swap;
			print_array(array, size);
		}
	}
}
