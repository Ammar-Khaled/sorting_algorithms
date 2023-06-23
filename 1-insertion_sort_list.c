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
		for (cur = i; cur; cur = cur->prev)
		{
			if (cur->n < cur->prev->n)
			{
				tmp = cur->n;
				cur->n = cur->prev->n;
				cur->prev->n = tmp;
				print_list(*list);
				/*
				if (cur->prev->prev)
				{
					pre_cur = cur->prev;
					pre_cur->prev->next = cur;
					pre_cur->next = cur->next;
					cur->prev = pre_cur->prev;
					pre_cur->prev = cur;
					cur->next = pre_cur;
					print_list(*list);
				}
				else
				{
					cur->prev = pre_cur->prev;
					pre_cur->next = cur->next;
					cur->next = pre_cur;
					pre_cur->prev = cur;
					*list = cur;
					print_list(*list);
				}
				*/
			}
		}
	}
}
