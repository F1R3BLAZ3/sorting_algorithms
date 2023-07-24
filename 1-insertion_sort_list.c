#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @head: Double pointer to the head of the list.
 * @node1: Double pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 *
 * Description: This function swaps two nodes, 'node1' and 'node2', in a doubly
 * linked list. It takes the pointers to the head of the list, 'node1',
 * and 'node2' as input parameters. The function performs the necessary
 * adjustments to the links between nodes to swap their positions in the list.
 * After the swap, 'node2' takes the position of 'node1' in the list,
 * and 'node1' takes the position of 'node2' in the list.
 * If either 'node1' or 'node2' is NULL, or if they belong to different lists,
 * the function does not perform the swap. The function assumes that the list
 * nodes are of type 'listint_t', which is a structure with 'prev' and
 * 'next' pointers for the previous and next nodes, respectively.
 *
 * Return: This function does not return a value.
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	listint_t *node2_next, *node1_prev;

	/* Ensure node1 and node2 are not NULL */
	if (*node1 == NULL || node2 == NULL)
		return;

	/* Ensure node1 and node2 belong to the same list */
	if (*head != (*node1)->prev)
		return;

	node2_next = node2->next;
	(*node1)->next = node2_next;

	if (node2_next != NULL)
		node2_next->prev = *node1;

	node1_prev = (*node1)->prev;

	node2->prev = node1_prev;
	node2->next = *node1;

	if (node1_prev != NULL)
		node1_prev->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: This function sorts a doubly linked list in ascending order
 * using the insertion sort algorithm. The function takes a double pointer to
 * the head of the list as input and rearranges the nodes of the list to sort
 * them in ascending order based on the 'n' member of the listint_t structure.
 * If the list is NULL, or if the list contains zero or one nodes, the function
 * does not perform any sorting and returns immediately. The function works by
 * traversing the list and for each node, it compares its value with the value
 * of the previous node. If the value of the current node is smaller, it swaps
 * the nodes to bring the current node to its correct sorted position. The
 * process continues until the entire list is sorted in ascending order.
 *
 * Return: This function does not return a value.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *temp;

	/* Check if the list is NULL or has less than 2 nodes */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Traverse the list starting from the second node */
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insertion = current->prev;

		/* Move the current node to its correct sorted position */
		while (insertion != NULL && current->n < insertion->n)
		{
			swap_nodes(list, &insertion, current);
			print_list((const listint_t *)*list);
		}
	}
}
