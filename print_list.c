#include <stdio.h>
#include "sort.h"

/**
 * outputList - Prints a list of integers
 *
 * @list: The list to be printed
 */
void outputList(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

