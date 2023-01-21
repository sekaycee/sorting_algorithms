#include "sort.h"

/**
 * swap_nums - swap numbers
 * @arr: input array
 * @a: first index
 * @b: second index
 */
void swap_nums(int *arr, int a, int b)
{
	arr[a] = arr[a] + arr[b];
	arr[b] = arr[a] - arr[b];
	arr[a] = arr[a] - arr[b];
}

/**
 * make_heap - build the max heap tree recursively
 * @arr: input array
 * @i: index number
 * @size: size of the array
 * @end: end of the array
 */
void make_heap(int *arr, int i, size_t size, int end)
{
	int big;
	int j;

	j = i * 2;
	if (j + 2 < end)
	{
		make_heap(arr, j + 1, size, end);
		make_heap(arr, j + 2, size, end);
	}

	if (j + 1 >= end)
		return;

	if (j + 2 < end)
		big = (arr[j + 1] > arr[j + 2]) ? (j + 1) : (j + 2);
	else
		big = j + 1;

	if (arr[i] < arr[big])
	{
		swap_nums(arr, i, big);
		print_array(arr, size);
		make_heap(arr, big, size, end);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: input array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t end;

	if (!array || size == 0)
		return;

	i = 0;
	end = size;
	while (end > 1)
	{
		make_heap(array, i, size, end);
		if (array[i] >= array[end - 1])
		{
			swap_nums(array, i, end - 1);
			print_array(array, size);
		}
		end--;
	}
}
