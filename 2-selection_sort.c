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
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, index_of_min;

	/* for each unsorted subarray starting i to the end */
	for (i = 0; i < size - 1; ++i)
	{
		/* suppose that the first element is the min */
		index_of_min = i;
		/* find min */
		for (j = i + 1; j < size; ++j)
			if (array[j] < array[index_of_min])
				index_of_min = j;

		/* swap min with the first element in the unsorted subarray */
		if (index_of_min != i)
		{
			swap(array + i, array + index_of_min);
			print_array(array, size);
		}

	}
}
