#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in asc order w/ bubble sort
 * @array: array to sort
 * @size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, n = 0;

	if (array == NULL)
		return;
	if (size <= 0)
		return;

	while (n < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
		n++;
	}
}
