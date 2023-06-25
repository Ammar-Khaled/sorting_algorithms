#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *i, *cur;
	int tmp;

	if (!list)
		return;

	for (i = (*list)->next; i; i = i->next)
	{
		for (cur = i; cur->prev; cur = cur->prev)
		{
			if (cur->n < cur->prev->n)
			{
				tmp = cur->n;
				cur->n = cur->prev->n;
				cur->prev->n = tmp;
				print_list(*list);
			}
		}
	}
}
