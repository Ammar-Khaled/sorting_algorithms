#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

void swap(int *a, int *b);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int partition(int *array, int low, int high);
void quick_sort(int *array, int low, int high);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void devide_conquer(int *array, int begin, int end, int *buffer);

#endif
