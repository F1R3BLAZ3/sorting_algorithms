#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @node1: Pointer to a pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 *
 * Description: This function swaps two nodes in a doubly linked list given
 * their pointers. It adjusts the connections between the nodes and updates the
 * head of the list if necessary.
 *
 * Return: This function does not return a value.
 */
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

/**
 * insertion_sort_list - Sorts a doubly linked list using
 * the Insertion Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 *
 * Description: This function sorts a doubly linked list in ascending order
 * using the Insertion Sort algorithm. It traverses the list starting from the
 * second node and moves each node to its correct sorted position by comparing
 * its value with the previous nodes. The function uses the swap_nodes function
 * to perform node swaps and adjust the list connections accordingly. The
 * sorted list is updated through the head pointer. After each node swap, the
 * current state of the list is printed using the print_list function to
 * visualize the sorting process.
 *
 * Return: This function does not return a value.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion;

	/* Check if the list is NULL or has less than 2 nodes */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/* Traverse the list starting from the second node */
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		insertion = current->prev;
		/* Move the current node to its correct sorted position */
		while (insertion != NULL && current->n < insertion->n)
		{
			swap_nodes(list, &insertion, current);
			print_list((const listint_t *)*list);
			/* Update the insertion pointer */
			insertion = current->prev;
		}
	}
}
