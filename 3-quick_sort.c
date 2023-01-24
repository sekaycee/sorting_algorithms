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
	ssize_t i, j;
	int tmp, p;

	if (start < end)
	{
		p = arr[end];
		j = start - 1;
		for (i = start; i < end; i++)
		{
			if (arr[i] < p)
			{
				j++;
				if (i != j)
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
					print_array(arr, size);
				}
			}
		}
		if (arr[end] < arr[j + 1])
		{
			tmp = arr[j + 1];
			arr[j + 1] = arr[end];
			arr[end] = tmp;
			print_array(arr, size);
		}
		q_sort(arr, start, j, size);
		q_sort(arr, j + 2, end, size);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * using the quick sort algorithm and lomuto partition scheme
 * @array: input arrray
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
