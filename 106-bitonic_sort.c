#include "sort.h"

/**
 * b_compare - sort the values in a sub-array with respect to
 * the Bitonic sort algorithm
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 */
void b_compare(char up, int *array, size_t size)
{
	size_t i, n;
	int tmp;

	n = size / 2;
	for (i = 0; i < n; i++)
	{
		if ((array[i] > array[i + n]) == up)
		{
			tmp = array[i];
			array[i] = array[i + n];
			array[i + n] = tmp;
		}
	}
}

/**
 * b_merge - merge recursively two sub-arrays
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 */
void b_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	b_compare(up, array, size);
	b_merge(up, array, size / 2);
	b_merge(up, array + (size / 2), size / 2);
}

/**
 * b_sort - recursive helper function for the Bitonic sort algorithm
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 * @t: total size of the original array
 */
void b_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	b_sort(1, array, size / 2, t);
	b_sort(0, array + (size / 2), size / 2, t);
	b_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - sort an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	b_sort(1, array, size, size);
}
