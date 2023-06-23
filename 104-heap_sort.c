#include "sort.h"

/**
 * swap - swap two integers
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - heapify a subtree rooted with node i
 * @array: pointer to an array of integers.
 * @size: number of elements in the heap array.
 * @i: is an index in the array.
 * @total_size: size of the input array -> required for printing
 *
 */
void heapify(int *array, size_t size, int i, size_t total_size)
{
	/* indexes for left and right children and largest among them and their root*/
	int left, right, largest;

	/*
	 * find the largest among the root, its left child and its right child.
	 */
	largest = i; /* initialise the largest as root */
	left = 2 * i + 1;
	right = 2 * i + 2;

	if ((size_t)left < size && array[left] > array[largest])
	{
		largest = left;
	}

	if ((size_t)right < size && array[right] > array[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(array + i, array + largest);

		print_array(array, total_size);

		/* Recursively heapify the affected sub-tree */
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: pointer to an array of integers.
 * @size: number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	/*
	 * to Build a max heap from the input array
	 * heapify it from the last parent at bottom to top
	 */
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		/*
		 * swap the root of the heap, which is the max of the array
		 * with the last element in the heap
		 */
		swap(array, array + i);

		print_array(array, size);

		/*
		 * Heapify root element to get largest element at root again
		 * with size decreased
		 */
		heapify(array, i, 0, size);
	}
}
