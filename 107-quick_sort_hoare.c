#include "sort.h"

/**
 * qsort_h - recursive helper function for quick_sort_hoare
 * @array: array to sort
 * @start: lowest index of the partition to sort
 * @end: highest index of the partition to sort
 * @size: size of the array
 */
void qsort_h(int *arr, ssize_t start, ssize_t end, size_t size)
{
	int tmp, p;
	ssize_t i, j;

	if (start < end)
	{
		i = start;
		j = end;
		p = arr[j];
		while (i <= j)
		{
			while (arr[i] < p)
				i++;
			while (arr[j] > p)
				j--;
			if (i <= j)
			{
				if (i != j)
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
					print_array(arr, size);
				}
				i++;
				j--;
			}
		}
		qsort_h(arr, start, j, size);
		qsort_h(arr, j + 1, end, size);
	}
}

/**
 * quick_sort_hoare - sort an array of integers in ascending order
 * using the Quick sort hoare algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qsort_h(array, 0, size - 1, size);
}
