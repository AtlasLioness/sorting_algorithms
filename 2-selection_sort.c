#include "sort.h"
/**
 * selection_sort - sorts array of ints in asc order w/ selection sort
 * @array: array to sort
 * @size: size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t n, i, j;

	if (array == NULL || size <= 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, n = size - 1; n > i; n--)
		{
			if (array[n] < array[j])
				j = n;
		}
		if (array[i] > array[j])
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
}
