#include "sort.h"

/**
 * selection_sort - sorting via selection method
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void selection_sort(int *array, size_t size)
{
	size_t cycle, pos;
	int low, temp;

	if (size < 2)
		return;

	for (cycle = 0; cycle < size - 1; cycle++)
	{

		for (pos = cycle + 1, low = cycle; pos < size; pos++)
		{
			if (array[pos] < array[low])
			{
				low = pos;
			}

		}

		if (array[cycle] != array[low])
		{
			temp = array[cycle];
			array[cycle] = array[low];
			array[low] = temp;
			print_array(array, size);
		}
	}
}
