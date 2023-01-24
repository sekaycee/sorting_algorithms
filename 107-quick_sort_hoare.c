#include "sort.h"

/**
 * quicksort - recursive helper function for quick_sort_hoare
 * @array: array to sort
 * @start: lowest index of the partition to sort
 * @end: highest index of the partition to sort
 * @size: size of the array
 */
void qsort_h(int *arr, ssize_t start, ssize_t end, size_t size)
{
	int tmp, p;

	if (start < end)
	{
		p = arr[end];
		while (start <= end)
		{
			while (arr[start] < p)
				start++;
			while (arr[end] > p)
				end--;
			if (start <= end)
			{
				if (start != end)
				{
					tmp = arr[start];
					arr[start] = arr[end];
					arr[end] = tmp;
					print_array(arr, size);
				}
				start++;
				end--;
			}
		}
	}
	qsort_h(arr, start, p, size);
	qsort_h(arr, p + 1, end, size);
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
