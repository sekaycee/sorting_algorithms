#include "deck.h"

/**
 * get_val - get the relative value of a card from it's string value
 * @str: string value of the card
 * Return: relative value of the card (0 through 12)
 */
int get_val(const char *str)
{
	int i;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
		if (strcmp(str, array[i]) == 0)
			return (i);
	exit(1);
}

/**
 * swap_node - swap a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 */
void swap_node(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * sort_deck - sort a linked list deck of cards
 * @deck: double pointer to the deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	char swap = 1, c, d;
	deck_node_t *curr;

	if (!deck || !*deck || !(*deck)->next)
		return;

	curr = *deck;
	while (swap != 0)
	{
		swap = 0;
		while (curr->next)
		{
			c = get_val(curr->card->value)
				+ 13 * curr->card->kind;
			d = get_val(curr->next->card->value)
				+ 13 * curr->next->card->kind;
			if (c > d)
			{
				swap_node(deck, curr);
				swap = 1;
			}
			else
				curr = curr->next;
		}
		if (swap == 0)
			break;

		swap = 0;
		while (curr->prev)
		{
			c = get_val(curr->card->value)
				+ 13 * curr->card->kind;
			d = get_val(curr->prev->card->value)
				+ 13 * curr->prev->card->kind;
			if (c < d)
			{
				swap_node(deck, curr->prev);
				swap = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
