#include "sort.h"
/**
 * quick_sort - sorts array of ints using Quick sort
 * @array: array to sort
 * @size: size of int
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 0)
		return;
	lomuto(array, 0, size - 1, size);
}

/**
 * lomuto - uses Lomuto partition scheme
 * @array: array to sort
 * @lo: lowest index
 * @hi: highest index
 * @size: size of array
 *
 */
void lomuto(int *array, int lo, int hi, size_t size)
{
	int part;

	if (lo < hi)
	{
		part = partition(array, lo, hi, size);
		lomuto(array, lo, part - 1, size);
		lomuto(array, part + 1, hi, size);
	}
}

/**
 * partition - Lomuto array partition
 * @array: array to sort
 * @lo: lowest index
 * @hi: highest index
 * @size: size of array
 *
 * Return: index of the pivot
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, index;
	int i, j;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swaping(&array[i], &array[j]);
		}
	}
	index = i + 1;
	swaping(&array[index], &array[hi]);
	print_array(array, size);
	return (index);

}

/**
 * swaping - swaps two ints in array
 * @a: ptr to first int
 * @b: ptr to second int
 *
 */
void swaping(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
