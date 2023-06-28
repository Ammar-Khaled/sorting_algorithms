#include "sort.h"
#include <string.h>

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
 * bitonicMerge - bitonicMerge
 * @arr: array
 * @low: low index
 * @cnt: count
 * @dir: direction
 * @size: size
 */
void bitonicMerge(int *arr, int low, int cnt, int dir, int size)
{
	int k, i;
	char *direction;

	if (dir == 1)
	{
		direction = "UP";
	}
	else
	{
		direction = "DOWN";
	}

	if (cnt > 1)
	{
		k = cnt / 2;


		for (i = 0; i < low + k; i++)
		{
			if (dir == (arr[i] > arr[i + k]))
			{
				swap(arr + i, arr + i + k);
			}
		}

		bitonicMerge(arr, low, k, dir, size);
		bitonicMerge(arr, low + k, k, dir, size);


		printf("Result [%i/%i] (%s):\n", cnt, size, direction);
		print_array(arr, cnt);

	}
}

/**
 * bitonicSort - bitonicSort
 * @arr: array
 * @low: low index
 * @cnt: count
 * @dir: direction
 * @size: size
 */
void bitonicSort(int *arr, int low, int cnt, int dir, int size)
{
	int k;

	char *direction;

	if (dir == 1)
	{
		direction = "UP";
	}
	else
	{
		direction = "DOWN";
	}

	if (cnt > 1)
	{
		k = cnt / 2;
		printf("Merging [%i/%i] (%s):\n", cnt, size, direction);
		print_array(arr, cnt);

		bitonicSort(arr, low, k, 1, size);
		bitonicSort(arr, low + k, k, 0, size);
		bitonicMerge(arr, low, cnt, dir, size);
	}
}

/**
 * bitonic_sort - bitonic_sort
 * @array: array
 * @size: size
 */
void bitonic_sort(int *array, size_t size)
{
	bitonicSort(array, 0, size, 1, size);
}
