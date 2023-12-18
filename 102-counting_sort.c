#include "sort.h"

/**
 * largest - find largest number in array
 * @array: int *
 * @size: size_t
 * Return: always 0
 */

int largest(int *array, size_t size)
{
	size_t i;
	int largest = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
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
	int temp;

	temp = *low;
	*low = *high;
	*high = temp;
}

/**
 * counting_sort - sort via counting method
 * @array: int*
 * @size: size_t
 * Return: always 0
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *new;
	size_t i, k;

	if (!array || size < 2)
		return;

	k = largest((array), size);

	counter = malloc((k + 1) * sizeof(int));
	if (!counter)
		return;
	new = malloc(size * sizeof(int));

	for (i = 0; i < k + 1; i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (i = 1; i < k + 1; i++)
		counter[i] = counter[i] + counter[i - 1];

	print_array(counter, k + 1);

	for (i = 0; i < size; i++)
	{
		new[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = new[i];
	}
	free(new);
	free(counter);
}
