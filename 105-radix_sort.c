#include "sort.h"

/**
 * count_sort_for_radix - does a stable count sort for each digit
 * @array: array of non-negative integers
 * @n: size of the array
 * @placement_value: the placement value for the current digit
 */
void count_sort_for_radix(int *array, int n, int placement_value)
{
	int i, *output, *count;

	output = malloc(sizeof(int) * n);
	if (!output)
		exit(EXIT_FAILURE);

	count = malloc(sizeof(int) * 10);
	if (!count)
	{
		free(output);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	/* store number of occurrences in count[] */
	for (i = 0; i < n; ++i)
		count[(array[i] / placement_value) % 10]++;

	/* prefix sum on count */
	for (i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	/* build output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / placement_value) % 10] - 1] = array[i];
		count[(array[i] / placement_value) % 10]--;
	}

	/* copy output into array */
	for (i = 0; i < n; ++i)
		array[i] = output[i];

	free(output);
	free(count);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using Radix Sort algorithm with the Least Segnificant Digit implementation
 * @array: array
 * @size: size
 */
void radix_sort(int *array, size_t size)
{
	int max, i, placement_value;

	/* find max element to determine the max number of digits */
	max = array[0];
	for (i = 1; i < (int)size; ++i)
		if (array[i] > max)
			max = array[i];

	/* do stable count sort for each digit */
	for (placement_value = 1; max / placement_value > 0; placement_value *= 10)
	{
		count_sort_for_radix(array, size, placement_value);
		print_array(array, size);
	}
}
