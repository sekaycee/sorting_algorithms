#include "sort.h"

/**
 * counting_sort - sort an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int *a, *b, i, n;

	if (!array || size < 2)
		return;

	for (n = i = 0; i < (int)size; i++)
		if (array[i] > n)
			n = array[i];

	b = malloc(sizeof(int) * (n + 1));
	if (!b)
		return;

	for (i = 0; i <= n; i++)
		b[i] = 0;
	for (i = 0; i < (int)size; i++)
		b[array[i]] += 1;
	for (i = 1; i <= n; i++)
		b[i] += b[i - 1];

	print_array(b, (n + 1));
	a = malloc(sizeof(int) * (size + 1));
	if (!a)
	{
		free(b);
		return;
	}

	for (i = 0; i < (int)size; i++)
	{
		a[b[array[i]] - 1] = array[i];
		b[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = a[i];

	free(b);
	free(a);
}
