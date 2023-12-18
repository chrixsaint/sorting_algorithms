#include "sort.h"

/**
 * swap- swap two elements in array
 * @low: int
 * @high: int
 * Return: always 0
 */

void swap(int *low, int *high)
{
	int tmporal;

	tmporal = *low;
	*low = *high;
	*high = tmporal;
}

/**
 * heapify - heapify tree
 * @array: int*
 * @size: int
 * @i: int
 * @size2: int
 * Return: always 0
 */

void heapify(int *array, int size, int i, int size2)
{
	int big = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[big] < array[left])
		big = left;

	if (right < size && array[big] < array[right])
		big = right;

	if (big != i)
	{
		swap(&array[i], &array[big]);
		print_array(array, size2);
		heapify(array, size, big, size2);

	}



}

/**
 * heap_sort - sort via heap method
 * @array: int*
 * @size: size_t
 * Return: always 0
 */

void heap_sort(int *array, size_t size)
{

	int i, size2 = (int)size;

	if (size < 2 || !array)
		return;

	for (i = size2 / 2 - 1; i >= 0; i--)
		heapify(array, size2, i, size2);

	for (i = size2 - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size2);
		heapify(array, i, 0, size2);
	}

}

