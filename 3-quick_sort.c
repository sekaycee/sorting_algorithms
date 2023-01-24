#include "sort.h"

/**
 * q_sort - helper function for the quick_sort function
 * @arr: input arrray
 * @start: index of the first element
 * @end: index of the last element
 * @size: size of the array
 */
void q_sort(int *arr, int start, int end, int size)
{
	ssize_t i  j;
	int tmp, p;

	if (start < end)
	{
		p = end;
		j = start;
		for (i = start; i < end; i++)
		{
			if (arr[i] < arr[p])
			{
				if (i != j)
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
					print_array(arr, size);
				}
				j++;
			}
		}
		if (j != p && arr[j] != arr[p])
		{
			tmp = arr[j];
			arr[j] = arr[p];
			arr[p] = tmp;
			print_array(arr, size);
		}
		q_sort(arr, start, j - 1, size);
		q_sort(arr, j + 1, end, size);
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
