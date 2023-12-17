#include "sort.h"

void swapValues(int *a, int *b);
int SplitPartition(int *array, size_t size, int left, int right);
void SplitMergeSort(int *array, size_t size, int left, int right);
void SwiftSort_hoare(int *array, size_t size);

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
 * SplitPartition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int SplitPartition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swapValues(array + above, array + below);
			outputArray(array, size);
		}
	}

	return (above);
}

/**
 * SplitMergeSort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void SplitMergeSort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = SplitPartition(array, size, left, right);
		SplitMergeSort(array, size, left, part - 1);
		SplitMergeSort(array, size, part, right);
	}
}

/**
 * SwiftSort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void SwiftSort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	SplitMergeSort(array, size, 0, size - 1);
}
