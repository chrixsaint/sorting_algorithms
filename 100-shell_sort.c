#include "sort.h"

/**
 * swap - swap two elements in array
 * @x: int
 * @y: int
 * Return: always 0
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - sort array via shell method
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t j, i;

	if (!array)
		return;

	if (size < 2)
		return;

	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap >= 1)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i; j < size - gap; j += gap)
			{
				while (array[j] > array[j + gap])
				{
					swap(&array[j], &array[j + gap]);

					if (j >= gap)
						j = j - gap;
					else
						break;
				}
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
