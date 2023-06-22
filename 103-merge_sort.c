#include "sort.h"
#include <stdio.h>

/* Merges two sorted sub-arrays of array[]. */
/* First subarray is arr[begin..mid] */
/* Second subarray is arr[mid+1..end] */
void merge(int *array, int begin, int mid, int end, int *buffer)
{
	int len1, i, j, index1, index2, merged_index;

	printf("Merging...\n");

	len1 = mid - begin + 1;

	/* Copy data to temp buffer leftArray and rightArray */
	printf("[left]: ");
	i = 0;
	for (; i < len1; i++)
	{
		buffer[i] = array[begin + i];
	}
	print_array(buffer, len1);

	printf("[right]: ");
	for (j = mid + 1; j <= end; i++, j++)
	{
		buffer[i] = array[j];
	}
	print_array(buffer + len1, end - mid);

	index1 = 0,          /* Initial index of first sub-array */
	index2 = mid + 1;           /* Initial index of second sub-array */
	merged_index = begin; /* Initial index of merged array */

	/* Merge the temp arrays back into array[left..right] */
	while (index1 < len1 && index2 <= end)
	{
		if (buffer[index1] <= buffer[index2])
		{
			array[merged_index] = buffer[index1];
			index1++;
		}
		else
		{
			array[merged_index] = buffer[index2];
			index2++;
		}
		merged_index++;
	}
	/* Copy the remaining elements of arr1[], if there are any */
	while (index1 < len1)
	{
		array[merged_index] = buffer[index1];
		index1++;
		merged_index++;
	}

	/* Copy the remaining elements of arr2[], if there are any */
	while (index2 <= end)
	{
		array[merged_index] = buffer[index2];
		index2++;
		merged_index++;
	}

	printf("[Done]: ");
	print_array(array, end + 1);
}

void devide_conquer(int *array, int begin, int end, int *buffer)
{
	int mid;

	if (begin >= end)
		return; /* base case for the recursion */

	mid = begin + (end - begin) / 2;

	devide_conquer(array, begin, mid, buffer);

	devide_conquer(array, mid + 1, end, buffer);

	merge(array, begin, mid, end, buffer);
}

void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(size * sizeof(int));
	if (!buffer)
		exit(EXIT_FAILURE);

	devide_conquer(array, 0, size - 1, buffer);
}

/**
 * Analysis
 * Space: O(n)
 * Time: O(nlog(n))
 * stable and out-place
 */
