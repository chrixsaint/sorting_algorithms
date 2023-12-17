#include <stdlib.h>
#include <stdio.h>

/**
 * outputArray - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void outputArray(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
