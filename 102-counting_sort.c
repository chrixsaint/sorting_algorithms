#include "sort.h"

/**
 * largest - find largest number in array
 * @array: int *
 * @size: size_t
 * Return: always 0
 */

int largest(int *array, size_t size)
{
	size_t aii;
	int largest = array[0];

	for (aii = 1; aii < size; aii++)
	{
		if (array[aii] > largest)
			largest = array[aii];
	}
	return (largest);
}


/**
 * swap- swap two elements in array
 * @low: int
 * @high: int
 * Return: always 0
 */


void swap(int *low, int *high)
{
	int tmporal;

	tmporal = *low;
	*low = *high;
	*high = tmporal;
}

/**
 * counting_sort - sort via counting method
 * @array: int*
 * @size: size_t
 * Return: always 0
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *fresh;
	size_t i, kaii;

	if (!array || size < 2)
		return;

	kaii = largest((array), size);

	counter = malloc((kaii + 1) * sizeof(int));
	if (counter == NULL)
		return;
	fresh = malloc(size * sizeof(int));

	for (i = 0; i < kaii + 1; i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (i = 1; i < kaii + 1; i++)
		counter[i] = counter[i] + counter[i - 1];

	print_array(counter, kaii + 1);

	for (i = 0; i < size; i++)
	{
		fresh[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = fresh[i];
	}
	free(fresh);
	free(counter);
}
