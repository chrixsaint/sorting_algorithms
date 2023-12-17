#include "sort.h"

/**
 * bubble_sort - sort via bubble method
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t cycle, swap, temp;
	int pass;

	if (size < 2)
		return;

	for (cycle = 0; cycle < size - 1; cycle++)
	{

		for (pass = 0, swap = 0; swap < size - cycle - 1; swap++)
		{
			if (array[swap + 1] < array[swap])
			{
				pass = 1;
				temp = array[swap];
				array[swap] = array[swap + 1];
				array[swap + 1] = temp;
				print_array(array, size);

			}
		}

		if (pass == 0)
			break;
	}
}
