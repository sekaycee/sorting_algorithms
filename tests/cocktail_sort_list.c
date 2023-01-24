#include "sort.h"

/**
 * swap - swap the elements of the list
 * @ptr1: first pointer
 * @ptr2: second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 */
void swap(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *aux, *tmp;

	aux = *ptr1;
	tmp = *ptr2;

	aux->next = tmp->next;
	tmp->prev = aux->prev;
	if (tmp->next)
		tmp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = tmp;

	aux->prev = tmp;
	tmp->next = aux;
	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = aux;
}

/**
 * move_big - move the bigger numbers to the end
 * @ptr: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 */
void move_big(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;
	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			swap(&aux, &(aux->next), 0);
			if (!aux->prev)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}
	*limit = aux;
	*ptr = aux;
}

/**
 * move_small - move the smaller numbers to the start
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 */
void move_small(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;
	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			swap(&(aux->prev), &aux, 1);
			if (!aux->prev->prev)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}
	*limit = aux;
	*ptr = aux;
}

/**
 * cocktail_sort_list - sort a DLL of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (!list || !*list)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;
	do {
		move_big(&ptr, &limit1, list);
		move_small(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
