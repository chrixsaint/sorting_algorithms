#include "sort.h"

/**
 * swap_list - Swaps two elements in a doubly linked list.
 * @list: A double pointer to the head of the doubly linked list.
 * @low: The lower element to be swapped.
 * @high: The higher element to be swapped.
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
 * move - Moves the pointer in a doubly linked list.
 * @check: The current node in the list.
 * @pos: The position to move.
 * @dir: The direction to move (1 for forward, -1 for backward).
 * Return: The new position after moving.
 */

listint_t *move(listint_t *check, int pos, int dir)
{
	int aii;

	if (dir == 1)
	{
		for (aii = 0; aii < pos; aii++)
			check = check->next;
	}
	else
	{
		while (check->next)
			check = check->next;

		for (aii = 0; aii < pos; aii++)
			check = check->prev;
	}
	return (check);

}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * in ascending order using the Cocktail Sort algorithm.
 * @list: A double pointer to the head of the doubly linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	int swaps = 1;
	int cycle = 0;
	listint_t *check;

	if (list == NULL || !(*list))
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
