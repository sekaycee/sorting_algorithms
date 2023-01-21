#include "sort.h"

/**
 * swap_nodes - Swaps the positions (indexes) of given node and its predecessor
 *              node in a doubly linked list by changing the prev/next values
 *              of the current, previous and next nodes as needed.
 *
 * @node: Pointer to node in linked list to be swapped with its previous node.
 *
 * Return: Pointer to new head node if head/first node of list has changed.
 *         NULL otherwise or if nothing is swapped.
 */

listint_t *swap_nodes(listint_t *node)
{
	if (node->prev == NULL)
		return (NULL);

	if (node->next == NULL && node->prev->prev == NULL)
	{
		node->next = node->prev;
		node->prev = node->next->next = NULL;
		node->next->prev = node;
		return (node);
	}
	else if (node->next == NULL)
	{
		node->prev->next = NULL;
		node->next = node->prev;
		node->prev = node->prev->prev;
		node->prev->next = node;
	}
	else if (node->prev->prev == NULL)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		node->next = node->prev;
		node->prev->prev = node;
		node->prev = NULL;
		return (node);
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		node->next = node->prev;
		node->prev = node->prev->prev;
		node->next->prev = node;
		node->prev->next = node;
	}

	return (NULL);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 *
 * @list: Pointer to linked list of integers to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp_node, *next_node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;

	while (node != NULL)
	{
		if ((node->n) < (node->prev->n))
		{
			if (next_node == NULL && node->next != NULL)
				next_node = node->next;

			tmp_node = swap_nodes(node);
			if (tmp_node != NULL)
			{
				*list = tmp_node, tmp_node = NULL;
				node = node->next;
			}

			print_list(*list);
		}
		else if (next_node != NULL)
			node = next_node, next_node = NULL;
		else
			node = node->next;
	}
}
