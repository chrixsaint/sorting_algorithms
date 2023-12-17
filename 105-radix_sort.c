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
 * digit - get digit out of num of place
 * @num: int
 * @place: place
 * Return: int
 */

int digit(int num, int place)
{

	if (place > num)
		return (0);

	place = place * 10;
	return ((num % place) / (place / 10));


}


/**
 * radix_sort - sort via radix method
 * @array: int*
 * @size: size_t
 * Return: always 0
 */

void radix_sort(int *array, size_t size)
{
	int *counter, *new;
	size_t i, large, p = 1;

	if (!array || size < 2)
		return;

	large = largest(array, size);

	counter = malloc((sizeof(int) * 10));
	if (!counter)
		return;
	new = malloc(size * sizeof(int));

	while (p <= large)
	{
		for (i = 0; i < 10; i++)
			counter[i] = 0;

		for (i = 0; i < size; i++)
		{
			counter[digit(array[i], p)]++;
		}
		for (i = 1; i < 10; i++)
			counter[i] = counter[i] + counter[i - 1];

		for (i = (size); i > 0; i--)
		{
			new[counter[digit(array[i - 1], p)] - 1] = array[i - 1];
			counter[digit(array[i - 1], p)]--;
		}
		for (i = 0; i < size; i++)
		{
			array[i] = new[i];
		}
		p = p * 10;
		print_array(array, size);
	}
	free(new);
	free(counter);
}
