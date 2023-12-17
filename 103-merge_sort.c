#include "sort.h"

void split(int *array, int *new, int start, int end);
int middle(int start, int end);
void merge(int *array, int *new, int start, int m, int end);
void print_array2(const int *array, size_t start, size_t end);

/**
 * print_array2 - Customized print_array
 * @array: The array to be printed
 * @start: starting index
 * @end: ending index
 * Return: always 0
 */
void print_array2(const int *array, size_t start, size_t end)
{
	size_t i;

	i = start;
	while (array && i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
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
	int *new;

	if (size < 2 || !array)
		return;

	new = malloc(sizeof(int) * size);

	split(array, new, 0, size - 1);

	free(new);
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
		middle--;
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
	int m;

	if (start < end)
	{
		m = middle(start, end);
		split(array, new, start, m);
		split(array, new, m + 1, end);

		merge(array, new, start, m, end);
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
	int l, r, i;


	printf("Merging...\n");
	printf("[left]: ");
	for (l = start, i = 0; l <= m; l++, i++)
	{
		new[i] = array[l];
	}
	print_array(new, len_left);

	printf("[right]: ");

	for (r = m + 1; r <= end; r++, i++)
	{
		new[i] = array[r];
	}

	print_array2(new, len_left, i - 1);

	l = 0;
	r = len_left;
	i = start;

	while (l < len_left && r < len_right + len_left)
	{
		if (new[l] <= new[r])
		{
			array[i] = new[l];
			l++;
		}
		else
		{
			array[i] = new[r];
			r++;
		}
		i++;
	}


	while (l < len_left)
	{
		array[i] = new[l];
		l++;
		i++;
	}

	while (r < len_right + len_left)
	{
		array[i] = new[r];
		r++;
		i++;
	}

	printf("[Done]: ");
	print_array2(array, start, end);

}
