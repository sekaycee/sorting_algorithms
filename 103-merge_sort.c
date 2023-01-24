#include "sort.h"

/**
 * print_data - Print data
 *
 * @msg: message
 * @a: array
 * @from: from
 * @to: to
 */
void print_data(char *msg, int *a, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";
	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, a[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge - Helper function for merge_sort function
 *
 * @a: array
 * @start: start index
 * @middle: middle
 * @end: end index
 * @b: buffer
 */
void merge(int *a, int start, int middle, int end, int *b)
{
	int low, lmid, i;

	low = i = start;
	lmid = middle + 1;

	printf("Merging...\n");
	print_data("left", a, start, middle);
	print_data("right", a, middle + 1, end);
	while (low <= middle && lmid <= end)
	{
		if (a[low] < a[lmid])
			b[i++] = a[low++];
		else
			b[i++] = a[lmid++];
	}

	while (low <= middle)
		b[i++] = a[low++];

	while (lmid <= end)
		b[i++] = a[lmid++];

	for (i = start; i <= end; i++)
		a[i] = b[i];

	print_data("Done", a, start, end);
}

/**
 * msort - Helper function for merge_sort function
 *
 * @array: array
 * @start: start index
 * @end: end index
 * @b: buffer
 */
void msort(int *array, int start, int end, int *b)
{
	int mid;

	if (start < end)
	{
		mid = (start + end - 1) / 2;
		msort(array, start, mid, b);
		msort(array, mid + 1, end, b);
		merge(array, start, mid, end, b);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *
 * using the Merge sort algorithm
 * @array: array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	b = malloc(sizeof(int) * size);
	if (!b)
		return;
	msort(array, 0, size - 1, b);
	free(b);
}
