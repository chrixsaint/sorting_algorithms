#include "sort.h"

void split(int *array, int *new, int start, int end);
int middle(int start, int end);
void merge(int *array, int *new, int start, int m, int end);
void print_array2(const int *array, size_t start, size_t end);

/**
 * print_array2 - Customized print_array function.
 * @array: The array to be printed.
 * @start: Starting index.
 * @end: Ending index.
 * Return: void
 */
void print_array2(const int *array, size_t start, size_t end)
{
	size_t aii;

	aii = start;
	while (array && aii <= end)
	{
		if (aii > start)
		{
			printf(", ");
		}
		printf("%d", array[aii]);
			++aii;
	}
	printf("\n");
}


/**
 * merge_sort - sorting via merge method
 * @array: int*
 * @size: size_t
 * Return: always 0
 */

void merge_sort(int *array, size_t size)
{
	int *fresh;

	if (size < 2 || !array)
	{
		return;
	}

	fresh = malloc(sizeof(int) * size);

	split(array, fresh, 0, size - 1);

	free(fresh);
}


/**
 * middle - find middle of merge split
 * @start: int
 * @end: int
 * Return: int
 */

int middle(int start, int end)
{
	int middle = (end - start) / 2;

	if ((end - start) % 2 == 0)
	{
		middle--;
	}
	return (middle + start);
}

/**
 * split- recursive function to split up array into single elements
 * @array: int*
 * @new: int*
 * @start: int
 * @end: int
 * Return: always 0
 */

void split(int *array, int *new, int start, int end)
{
	int em;

	if (start < end)
	{
		em = middle(start, end);
		split(array, new, start, em);
		split(array, new, em + 1, end);

		merge(array, new, start, em, end);
	}


}

/**
 * merge- merger function
 * @array: int*
 * @new: int*
 * @start: int
 * @m: int
 * @end: int
 * Return: always 0
 */

void merge(int *array, int *new, int start, int m, int end)
{
	int len_left = m - start + 1;
	int len_right = end - m;
	int l, r, aii;


	printf("Merging...\n");
	printf("[left]: ");
	for (l = start, aii = 0; l <= m; l++, aii++)
	{
		new[aii] = array[l];
	}
	print_array(new, len_left);

	printf("[right]: ");

	for (r = m + 1; r <= end; r++, aii++)
	{
		new[aii] = array[r];
	}

	print_array2(new, len_left, aii - 1);

	l = 0;
	r = len_left;
	aii = start;

	while (l < len_left && r < len_right + len_left)
	{
		if (new[l] <= new[r])
		{
			array[aii] = new[l];
			l++;
		}
		else
		{
			array[aii] = new[r];
			r++;
		}
		aii++;
	}


	while (l < len_left)
	{
		array[aii] = new[l];
		l++;
		aii++;
	}

	while (r < len_right + len_left)
	{
		array[aii] = new[r];
		r++;
		aii++;
	}

	printf("[Done]: ");
	print_array2(array, start, end);

}
