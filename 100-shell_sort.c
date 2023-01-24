#include "sort.h"

/**
 * s_sort - helper function for shell_sort function
 *
 * @a: input arrray
 * @size: size of the array
 * @n: interval
 */
void s_sort(int *a, int size, int n)
{
	int tmp, i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				tmp = a[j];
				a[j] = a[j - n];
				a[j - n] = tmp;
			}
		}
	}
	print_array(a, size);
}

/**
 * shell_sort - sort an array of integers in ascending order
 *
 * using the Shell sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	if (!array || size < 2)
		return;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		s_sort(array, size, n);
}
