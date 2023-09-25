#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list of ints in asc order
 * @list: the list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;
	int new;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while (current)
	{
		prev = current->prev;
		new = current->n;
		while (prev != NULL && prev->n > new)
		{
			swaper(prev, current, list);
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}

/**
 * swaper - swaps two nodes from doubly linked list
 * @node1: first node to swap
 * @node2: seconde node to swap with the first
 * @list: doubly linked list containing the nodes
 *
 */
void swaper(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	if (node1 == NULL || node2 == NULL)
		return;
	tmp1 = node1->prev;
	tmp2 = node2->next;

	if (tmp1 != NULL)
		tmp1->next = node2;
	if (tmp2 != NULL)
		tmp2->prev = node1;
	node1->next = tmp2;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = tmp1;

	if (tmp1 == NULL)
		*list = node2;
}
