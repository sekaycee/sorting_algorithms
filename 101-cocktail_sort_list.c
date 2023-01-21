#include "sort.h"

/**
 * swap - swap a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 */
void swap(listint_t **list, listint_t *node)
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
 * cocktail_sort_list - sort a DL list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	char c = 1;
	listint_t *tmp;

	if (!list || !*list)
		return;

	tmp = *list;
	while (c != 0)
	{
		c = 0;
		while (tmp->next)
		{
			if (tmp->next->n < tmp->n)
			{
				swap(list, tmp);
				c = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (c == 0)
			break;
		c = 0;
		while (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap(list, tmp->prev);
				c = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
