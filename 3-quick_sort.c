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
 * partition - takes the last element as `pivot`,
 * places it at its correct position in sorted array,
 * such that all smaller elements are to the left of `pivot`
 * and all greater elements or equal are to the right of `pivot`
 * @array: array of integers
 * @low: the starting index
 * @high: the ending index
 * Return: index of the `pivot` after placing in the right place
 */
int partition(int *array, int low, int high)
{
	int j;

	/* Choosing the pivot */
	int pivot = array[high];

	/* i indicates the index of the last smaller element */
	int i = low - 1;

	/* loop from low to high - 1 and compare with the pivot */
	for (j = low; j < high; ++j)
	{
		/* if current element is smaller than the pivot */
		if (array[j] < pivot)
		{
			/* Increment index of last smaller element */
			i++;
			/* now i points to the first greater element */
			/* swap it with the current element */
			swap(array + i, array + j);
		}
	}
	/* putting pivot in right place by swapping it with the first greater element */
	swap(array + i + 1, array + high);

	return (i + 1);
}

/**
 * quick_sort - implements QuickSort Algorithm
 * @array: array of integers
 * @low: the starting index
 * @high: the ending index
 */
void quick_sort(int *array, int low, int high)
{

	if (low < high)
	{
		int pivot_index = partition(array, low, high);
		/* array[pivot_index] is now at right place */

		/* quick_sort the left subarray */
		quick_sort(array, low, pivot_index - 1);
		/* quick_sort the right subarray */
		quick_sort(array, pivot_index + 1, high);
	}
}
