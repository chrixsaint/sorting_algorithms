#include "deck.h"

int compare(deck_node_t *card_a, deck_node_t *card_b);


/**
 * sort_deck - sort deck list via insertion
 * @deck: deck_node_t
 * Return: always 0
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *one, *two, *marker = NULL;

	if (!deck || !(*deck) || !(*deck)->next)
		return;

	one = *deck;
	two = one->next;

	while (two)
	{
		marker = two;
		if (compare(one, two) == 1)
		{
			marker = one;
			while (compare(one, two) == 1)
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
					*deck = two;
					break;
				}
				one = two->prev;
			}
		}
		one = marker;
		two = marker->next;

	}
}

/**
 * compare - compare 2 cards in the deck
 * @card_a: first card
 * @card_b: second card
 * Return: 1 if a > b, -1 if b > a, 0 if a == b
 */


int compare(deck_node_t *card_a, deck_node_t *card_b)
{
	int i;
	int a_val;
	int b_val;

	if (card_a->card->kind < card_b->card->kind)
		return (-1);

	else if (card_a->card->kind > card_b->card->kind)
		return (1);

	else
	{
		char v[13] = {'K', 'Q', 'J', '1', '9', '8', '7',
			'6', '5', '4', '3', '2', 'A'};


		for (i = 0; i < 13; i++)
		{
			if (card_a->card->value[0] == v[i])
				a_val = i;

			if (card_b->card->value[0] == v[i])
				b_val = i;
		}

		if (a_val > b_val)
			return (-1);

		else if (a_val < b_val)
			return (1);

		else
			return (0);
	}


}


