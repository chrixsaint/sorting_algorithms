#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	caller(array, 0, size - 1, size);
}

/**
 * caller - Recursively calls the partition function
 * to perform quick sort.
 * @array: The array to be sorted.
 * @start: The starting index of the current partition.
 * @end: The ending index of the current partition.
 * @size: The size of the array.
 */

void caller(int *array, int start, int end, size_t size)
{

	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		caller(array, start, pivot - 1, size);
		caller(array, pivot + 1, end, size);

	}


}

/**
 * partition - Chooses a pivot and partitions the array
 * into two sub-arrays.
 * @array: The array to be sorted.
 * @start: The starting index of the current partition.
 * @end: The ending index of the current partition.
 * @size: The size of the array.
 * Return: The index of the pivot element after partitioning.
 */

int partition(int *array, int start, int end, size_t size)
{
	int check = start;
	int low = start - 1;
	int pivot = array[end];

	while (check < end)
	{
		if (array[check] <= pivot)
		{
			low++;
			if (check != low)
			{
				swap(&array[low], &array[check]);
				print_array(array, size);
			}
		}

		check++;
	}
	low++;
	if (end != low)
	{
		swap(&array[low], &array[end]);
		print_array(array, size);
	}
	return (low);
}

/**
 * swap - Swaps two elements in an array.
 * @low: The first element to be swapped.
 * @high: The second element to be swapped.
 */

void swap(int *low, int *high)
{
	int tmporal;

	tmporal = *low;
	*low = *high;
	*high = tmporal;
}



