#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t cycle, positn;
	int small, tmporal;

	if (size < 2)
	{
		return;
	}

	for (cycle = 0; cycle < size - 1; cycle++)
	{

		for (positn = cycle + 1, small = cycle; positn < size; positn++)
		{
			if (array[positn] < array[small])
				small = positn;

		}

		if (array[cycle] != array[small])
		{
			tmporal = array[cycle];
			array[cycle] = array[small];
			array[small] = tmporal;
			print_array(array, size);
		}
	}
}
