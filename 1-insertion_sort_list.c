#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * @list: pointer to the linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (!list || !*list)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp && temp->prev && temp->prev->n > temp->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes- function used to swap nodes
 * @list: pointer to the linked list
 * @node1: pointer to node in list
 * @node2: pointer to node in list
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (!node2->prev)
		*list = node2;
}
