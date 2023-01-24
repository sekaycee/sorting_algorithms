#include "sort.h"

/**
 * q_sort - helper function for the quick_sort function
 * @a: input arrray
 * @start: index for the first element
 * @end: index for the last element
 * @size: size of the array
 */
void q_sort(int *a, int start, int end, int size)
{
	ssize_t i  j;
	int tmp, p;

	if (start < end)
	{
		p = end;
		j = start;
		for (i = start; i < end; i++)
		{
			if (a[i] < a[p])
			{
				if (i != j)
				{
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
					print_array(a, size);
				}
				j++;
			}
		}
		if (j != p && a[j] != a[p])
		{
			tmp = a[j];
			a[j] = a[p];
			a[p] = tmp;
			print_array(a, size);
		}
		q_sort(a, start, j - 1, size);
		q_sort(a, j + 1, end, size);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * using the quick sort algorithm
 * @array: input arrray
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
