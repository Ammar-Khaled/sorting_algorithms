#include "sort.h"
#include <stdio.h>

/**
 * merge - Merges two sorted sub-arrays of array[].
 * First subarray is arr[begin..mid]
 * Second subarray is arr[mid+1..end]
 * @array: array of integers
 * @begin: the starting index
 * @mid: the mid index
 * @end: the ending index
 */
void merge(int *array, int begin, int mid, int end)
{
	int len1, i, j, *leftArr, index1, index2, merged_index;

	printf("Merging...\n");
	len1 = mid - begin + 1;
	leftArr = malloc(sizeof(int) * len1);
	if (!leftArr)
		exit(EXIT_FAILURE);
	/* Copy data to temp buffer leftArray */

	printf("[left]: ");
	for (i = 0; i < len1; i++)
		leftArr[i] = array[begin + i];
	print_array(leftArr, len1);

	printf("[right]: ");
	for (j = mid + 1; j < end; i++, j++)
		printf("%i, ", array[j]);
	printf("%i\n", array[end]);

	index1 = 0;			  /* Initial index of first sub-array */
	index2 = mid + 1;	  /* Initial index of second sub-array */
	merged_index = begin; /* Initial index of merged array */

	/* Merge the temp arrays back into array[left..right] */
	while (index1 < len1 && index2 <= end)
	{
		if (leftArr[index1] <= array[index2])
			array[merged_index++] = leftArr[index1++];
		else
			array[merged_index++] = array[index2++];
	}
	/* Copy the remaining elements of arr1[], if there are any */
	while (index1 < len1)
		array[merged_index++] = leftArr[index1++];
	/* Copy the remaining elements of arr2[], if there are any */
	while (index2 <= end)
		array[merged_index++] = array[index2++];
	printf("[Done]: ");
	print_array(array + begin, end - begin + 1);
	free(leftArr);
}

/**
 * m_sort - recursive merge sort
 * @array: array of integers
 * @begin: the starting index
 * @end: the ending index
 */
void m_sort(int *array, int begin, int end)
{
	int mid;

	if (begin >= end)
		return; /* base case for the recursion */

	mid = (begin + end - 1) / 2;

	m_sort(array, begin, mid);

	m_sort(array, mid + 1, end);

	merge(array, begin, mid, end);
}

/**
 * merge_sort - sort array of integers ascendingly using Merge sort Algorithm
 * @array: array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	m_sort(array, 0, size - 1);
}

/*
 * Analysis
 * Space: O(n)
 * Time: O(nlog(n))
 * stable and out-place
 */
