#include "sort.h"

/**
 * insertion_sort_list - sort list via insertion
 * @list: listint_t
 * Return: always 0
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *one, *two, *marker = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	one = *list;
	two = one->next;

	while (two)
	{
		marker = two;
		if (two->n < one->n)
		{
			marker = one;
			while (two->n < one->n)
			{
				two->prev = one->prev;
				one->next = two->next;
				two->next = one;
				one->prev = two;
				if (one->next)
					one->next->prev = one;
				if (two->prev)
					two->prev->next = two;
				else
				{
					*list = two;
					print_list(*list);
					break;
				}
				print_list(*list);
				one = two->prev;
			}
		}
		one = marker;
		two = marker->next;

	}
}
