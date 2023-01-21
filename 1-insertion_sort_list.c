#include "sort.h"

/**
 * swap_nodes - swap the positions (indexes) of given node and its predecessor
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
	if (!node->prev)
		return (NULL);

	if (!node->next && !node->prev->prev)
	{
		node->next = node->prev;
		node->prev = node->next->next = NULL;
		node->next->prev = node;
		return (node);
	}
	else if (!node->next)
	{
		node->prev->next = NULL;
		node->next = node->prev;
		node->prev = node->prev->prev;
		node->prev->next = node;
	}
	else if (!node->prev->prev)
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
 * insertion_sort_list - sort a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 *
 * @list: Pointer to linked list of integers to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp_node, *next_node = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	node = (*list)->next;
	while (node)
	{
		if (node->n < node->prev->n)
		{
			if (!next_node && node->next)
				next_node = node->next;

			tmp_node = swap_nodes(node);
			if (tmp_node)
			{
				*list = tmp_node, tmp_node = NULL;
				node = node->next;
			}
			print_list(*list);
		}
		else if (next_node)
			node = next_node, next_node = NULL;
		else
			node = node->next;
	}
}
