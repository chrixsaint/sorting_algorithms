#include "sort.h"

void hoare_caller(int *array, int start, int end, size_t size);
int hoare_partition(int *array, int start, int end, size_t size);

/**
 * quick_sort_hoare- sorting via quick sort method
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	hoare_caller(array, 0, size - 1, size);
}

/**
 * hoare_caller- using this function recursively to call partitioner
 * @array: int
 * @start: int
 * @end: int
 * @size: size_t
 * Return: always 0
 */

void hoare_caller(int *array, int start, int end, size_t size)
{

	int pivot;

	if (start < end)
	{
		pivot = hoare_partition(array, start, end, size);
		hoare_caller(array, start, pivot - 1, size);
		hoare_caller(array, pivot, end, size);

	}


}

/**
 * hoare_partition- partition function to sort using quicksort
 * @array: int
 * @start: int
 * @end: int
 * @size: size_t
 * Return: int
 */

int hoare_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int check = start - 1;
	int other = end + 1;


	while (check < other)
	{
		do {
			check++;
		} while (array[check] < pivot);

		do {
			other--;
		} while (array[other] > pivot);

		if (other > check)
		{

			swap(&array[check], &array[other]);
			print_array(array, size);
		}


	}
	return (check);
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



