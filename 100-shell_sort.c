#include "sort.h"
#include <math.h>

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j, tmp;

	/* generate Knuth Gap Sequence */
	gap = 1;
	while (gap < ceil(size / 3))
	{
		gap = 3 * gap + 1;
	}

	/*
	* for each gap size, Do a gapped insertion sort for this gap size,
	* which is an insertion sort for every elements that are as far away as
	* gap from each other.
	*
	* The first gap elements a[0..gap-1] are already in gapped order
	* as a[0] is considered sorted and a[1...gap - 1] are in gap
	* so start from i = gap
	*
	* keep adding one more element (iterated by i),
	* comparing it with the previous gapped-size far elements (iterated by j)
	* until the entire array is gap sorted
	*/
	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			for (j = i; j >= gap; j -= gap)
			{
				if (array[j] < array[j - gap])
				{
					/* swap */
					tmp = array[j];
					array[j] = array[j - gap];
					array[j - gap] = tmp;
				}
			}
		}
		print_array(array, size);
	}
}

/*
 * Analysis:
 * the time complexity of the Shell sort (Knuth sequence) algorithm needed
 * is dependent on the size of array and gap, but in worst case it's O(n^3/2).
 *
 * Knuth Sequence for gap size:
 * typically: 1, 4, 13, 40, 121, ...
 * Gn+1 = Gn * 3 + 1
 * Gn = (Gn+1 - 1) / 3
 * Gn <= ceil(N / 3)
 */
