#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @x: The first element to be swapped.
 * @y: The second element to be swapped.
 */

void swap(int *x, int *y)
{
	int tmporal;

	tmporal = *x;
	*x = *y;
	*y = tmporal;
}

/**
 * shell_sort - Sorts an array of integers in
 * ascending order using the Shell Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t jaii, aii;
	size_t gap = 1;

	if (array == NULL)
	{
		return;
	}

	if (size < 2)
	{
		return;
	}

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (aii = 0; aii < gap; aii++)
		{
			for (jaii = aii; jaii < size - gap; jaii += gap)
			{
				while (array[jaii] > array[jaii + gap])
				{
					swap(&array[jaii], &array[jaii + gap]);

					if (jaii >= gap)
						jaii = jaii - gap;
					else
					{
						break;
					}
				}
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
