#include "sort.h"

/**
 * sift_down - Swap numbers
 *
 * @arr: input array
 * @root: the root of the heap
 * @end: the last index of the heap
 * @size: size of the array
 */
void sift_down(int *arr, size_t root, size_t end, size_t size)
{
	size_t left, right, swap;
	int tmp;

	while ((left = (2 * root) + 1) <= end)
	{
		swap = root;
		right = left + 1;
		if (arr[swap] < arr[left])
			swap = left;
		if (right <= end && arr[swap] < arr[right])
			swap = right;
		if (swap == root)
			return;

		tmp = arr[root];
		arr[root] = arr[swap];
		arr[swap] = tmp;
		print_array(arr, size);
		root = swap;
	}
}

/**
 * heapify - Build the max heap tree
 *
 * @arr: input array
 * @size: size of the array
 */
void heapify(int *arr, size_t size)
{
	size_t head;

	for (head = ((size - 1) - 1) / 2; 1; head--)
	{
		sift_down(arr, head, size - 1, size);
		if (head == 0)
			break;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the Heap sort algorithm
 *
 * @array: input array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (!array || size < 2)
		return;

	heapify(array, size);
	i = size - 1;
	while (i > 0)
	{
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		print_array(array, size);
		i--;
		sift_down(array, 0, i, size);
	}
}
