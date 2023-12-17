#include "sort.h"

/**
 * swap_list - swap 2 elements in doubly linked list
 * @list: listint_t
 * @low: listint_t
 * @high: listint_t
 * Return: void
 */

void swap_list(listint_t **list, listint_t *low, listint_t *high)
{
	low->next = high->next;
	high->prev = low->prev;
	low->prev = high;
	high->next = low;

	if (high->prev)
		high->prev->next = high;
	else
		*list = high;

	if (low->next)
		low->next->prev = low;

}

/**
 * move - move pointer in linked list
 * @check: listint_t
 * @pos: int position
 * @dir: int direction
 * Return: listint_t
 */

listint_t *move(listint_t *check, int pos, int dir)
{
	int i;

	if (dir == 1)
	{
		for (i = 0; i < pos; i++)
		{
			check = check->next;
		}
	}
	else
	{
		while (check->next)
			check = check->next;

		for (i = 0; i < pos; i++)
		{
			check = check->prev;
		}
	}
	return (check);

}

/**
 * cocktail_sort_list - sort via cocktail sort method
 * @list: listint_t *
 * Return: always 0
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *check;
	int cycle = 0;
	int swaps = 1;

	if (!list || !(*list))
		return;

	while (swaps != 0)
	{
		swaps = 0;
		check = *list;
		check = move(check, cycle, 1);
		while (check->next)
		{
			if (check->n > check->next->n)
			{
				swap_list(list, check, check->next);
				print_list(*list);
				swaps++;
				check = check->prev;
			}
			check = check->next;
		}
		if (swaps == 0)
			return;
		swaps = 0;
		check = *list;
		check = move(check, cycle, -1);
		while (check->prev)
		{
			if (check->n < check->prev->n)
			{
				swap_list(list, check->prev, check);
				print_list(*list);
				swaps++;
				check = check->next;
			}
			check = check->prev;
		}
	}
}
