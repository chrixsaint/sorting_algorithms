#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	int push;
	size_t cycle, exchange, tmporal;

	if (size < 2)
	{
		return;
	}

	for (cycle = 0; cycle < size - 1; cycle++)
	{

		for (push = 0, exchange = 0; exchange < size - cycle - 1; exchange++)
		{
			if (array[exchange + 1] < array[exchange])
			{
				push = 1;
				tmporal = array[exchange];
				array[exchange] = array[exchange + 1];
				array[exchange + 1] = tmporal;
				print_array(array, size);

			}
		}

		if (push == 0)
		{
			break;
		}
	}
}
