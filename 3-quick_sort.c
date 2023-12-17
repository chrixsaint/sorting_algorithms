#include "sort.h"

void swapValues(int *a, int *b);
int intuitivePartition(int *array, size_t size, int left, int right);
void basicSort(int *array, size_t size, int left, int right);
void SwiftSort(int *array, size_t size);

/**
 * swapValues - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swapValues(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * intuitivePartition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int intuitivePartition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swapValues(array + below, array + above);
				outputArray(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swapValues(array + above, pivot);
		outputArray(array, size);
	}

	return (above);
}

/**
 * basicSort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void basicSort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = intuitivePartition(array, size, left, right);
		basicSort(array, size, left, part - 1);
		basicSort(array, size, part + 1, right);
	}
}

/**
 * SwiftSort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void SwiftSort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	basicSort(array, size, 0, size - 1);
}

