#include "sort.h"

/**
 * largest - Find the biggest number in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The biggest number in the array.
 */

int largest(int *array, size_t size)
{
	size_t aii;
	int biggest = array[0];

	for (aii = 1; aii < size; aii++)
	{
		if (array[aii] > biggest)
		{
			biggest = array[aii];
		}
	}
	return (biggest);
}


/**
 * swap - Swap two elements in an array.
 * @low: The first element to swap.
 * @high: The second element to swap.
 * Return: void
 */


void swap(int *low, int *high)
{
	int tmporal;

	tmporal = *low;
	*low = *high;
	*high = tmporal;
}

/**
 * counting_sort - Sort an array of integers
 * using the counting sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *fresh;
	size_t aii, kaii;

	if (!array || size < 2)
		return;

	kaii = biggest((array), size);

	counter = malloc((kaii + 1) * sizeof(int));
	if (counter == NULL)
		return;
	fresh = malloc(size * sizeof(int));

	for (aii = 0; aii < kaii + 1; aii++)
		counter[aii] = 0;

	for (aii = 0; aii < size; aii++)
		counter[array[aii]]++;

	for (aii = 1; aii < kaii + 1; aii++)
		counter[aii] = counter[aii] + counter[aii - 1];

	print_array(counter, kaii + 1);

	for (aii = 0; aii < size; aii++)
	{
		fresh[counter[array[aii]] - 1] = array[aii];
		counter[array[aii]]--;
	}

	for (aii = 0; aii < size; aii++)
	{
		array[aii] = fresh[aii];
	}
	free(fresh);
	free(counter);
}
