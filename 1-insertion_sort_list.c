#include "sort.h"

void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	listint_t *node1_prev, *node2_next;

	node1_prev = (*node1)->prev;
	node2_next = node2->next;

	if (node1_prev)
		node1_prev->next = node2;
	else
		*head = node2;

	if (node2_next)
		node2_next->prev = *node1;

	node2->prev = node1_prev;
	node2->next = *node1;
	(*node1)->prev = node2;
	(*node1)->next = node2_next;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		insertion = current->prev;
		while (insertion != NULL && current->n < insertion->n)
		{
			swap_nodes(list, &insertion, current);
			print_list((const listint_t *)*list);
			insertion = current->prev;
		}
	}
}
