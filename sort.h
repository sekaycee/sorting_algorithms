#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element in the list
 * @next: Pointer to the next element in the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

#endif /* _SORT_H_ */
