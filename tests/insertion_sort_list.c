#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp;

	if (!list || !*list)
		return;

	ptr = (*list)->next;
	while (ptr)
	{
		tmp = ptr->next;
		while (ptr->prev && ptr->prev->n > ptr->n)
		{
			ptr->prev->next = ptr->next;
			if (ptr->next)
				ptr->next->prev = ptr->prev;

			ptr->next = ptr->prev;
			ptr->prev = ptr->next->prev;
			ptr->next->prev = ptr;
			if (!ptr->prev)
				*list = ptr;
			else
				ptr->prev->next = ptr;
			print_list(*list);
		}
		ptr = tmp;
	}
}
