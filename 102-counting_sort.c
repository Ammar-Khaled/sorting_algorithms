#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int max, i, *count, *output;

	max = array[0];
	for (i = 1; i < (int)size; ++i)
		if (array[i] > max)
			max = array[i];

	count = malloc((max + 1) * sizeof(int));
	if (!count)
		exit(EXIT_FAILURE);

	for (i = 0; i <= max; i++)
		count[i] = 0; /* initialise the count array with zeros */

	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < (int)size; ++i)
		count[array[i]]++; /* compute frequencies of elements */

	for (i = 1; i <= max; ++i)
		count[i] += count[i - 1]; /* cumulate count */

	print_array(count, max + 1);

	for (i = size - 1; i >= 0; i--) /* build output array */
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; ++i)
		array[i] = output[i]; /* copy output into array */
	free(count);
	free(output);
}

/*
 * Analysis
 * Space: O(n + k)
 * Time: O(n + k)
 * where k is the range of input
 * (i.e. the max element considering that, after shifting, range start from 0)
 */
