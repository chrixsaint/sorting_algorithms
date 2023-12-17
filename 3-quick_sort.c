#include "sort.h"

/**
 * quick_sort- sorting via quick sort method
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	caller(array, 0, size - 1, size);
}

/**
 * caller- using this function recursively to call partitioner
 * @array: int
 * @start: int
 * @end: int
 * @size: size_t
 * Return: always 0
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
 * partition- partition function to sort using quicksort
 * @array: int
 * @start: int
 * @end: int
 * @size: size_t
 * Return: int
 */

int partition(int *array, int start, int end, size_t size)
{
	int low = start - 1;
	int pivot = array[end];
	int check = start;

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



