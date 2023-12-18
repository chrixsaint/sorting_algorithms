#include "sort.h"

/**
 * largest - Find the largest number in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The largest number in the array.
 */

int largest(int *array, size_t size)
{
	size_t aii;
	int largest = array[0];

	for (aii = 1; aii < size; aii++)
	{
		if (array[aii] > largest)
		{
			largest = array[aii];
		}
	}
	return (largest);
}


/**
 * digit - Get the digit at a specified place in a number.
 * @num: An integer.
 * @place: The place of the digit.
 * Return: The digit at the specified place.
 */

int digit(int num, int place)
{

	if (place > num)
	{
		return (0);
	}

	place = place * 10;
	return ((num % place) / (place / 10));


}


/**
 * radix_sort - Sort an array of integers using
 * the radix sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int *counter, *fresh;
	size_t aii, big, pi = 1;

	if (array == NULL || size < 2)
		return;

	big = largest(array, size);

	counter = malloc((sizeof(int) * 10));
	if (counter == NULL)
		return;
	fresh = malloc(size * sizeof(int));

	while (pi <= big)
	{
		for (aii = 0; aii < 10; aii++)
			counter[aii] = 0;

		for (aii = 0; aii < size; aii++)
		{
			counter[digit(array[aii], pi)]++;
		}
		for (aii = 1; aii < 10; aii++)
			counter[aii] = counter[aii] + counter[aii - 1];

		for (aii = (size); aii > 0; aii--)
		{
			fresh[counter[digit(array[aii - 1], pi)] - 1] = array[aii - 1];
			counter[digit(array[aii - 1], pi)]--;
		}
		for (aii = 0; aii < size; aii++)
		{
			array[aii] = fresh[aii];
		}
		pi = pi * 10;
		print_array(array, size);
	}
	free(fresh);
	free(counter);
}
