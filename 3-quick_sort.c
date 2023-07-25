#include "sort.h"

/**
 * swap_integers - Swaps the values of two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 *
 * Description: This function swaps the values of two integers by using
 * pointers to their memory locations. The value of the integer pointed
 * to by 'x' is exchanged with the value of the integer pointed to by 'y'.
 *
 * Return: This function does not return a value.
 */

void swap_integers(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: Pointer to the array to be partitioned.
 * @size: Size of the array.
 * @left: Index of the leftmost element of the partition.
 * @right: Index of the rightmost element of the partition.
 *
 * Description: This function partitions the input array using the Lomuto
 * partitioning scheme. It selects the pivot element from the rightmost index
 * of the partition. The function rearranges the elements such that all
 * elements less than the pivot are moved to the left of it, and all elements
 * greater than or equal to the pivot are moved to the right of it.
 * The function returns the final position of the pivot element after
 * partitioning.
 *
 * Return: The final position of the pivot element after partitioning.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot_elem, idx_above, idx_below;

	pivot_elem = array + right;
	for (idx_above = idx_below = left; idx_below < right; idx_below++)
	{
		if (array[idx_below] < *pivot_elem)
		{
			if (idx_above < idx_below)
			{
				swap_integers(array + idx_below, array + idx_above);
				print_array(array, size);
			}
			idx_above++;
		}
	}

	if (array[idx_above] > *pivot_elem)
	{
		swap_integers(array + idx_above, pivot_elem);
		print_array(array, size);
	}

	return (idx_above);
}

/**
 * lomuto_sort - Sorts an array of integers using the Lomuto partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @low: Index of the leftmost element of the current partition.
 * @high: Index of the rightmost element of the current partition.
 *
 * Description: This function sorts the input array using the quicksort
 * algorithm with the Lomuto partitioning scheme. It selects a pivot element
 * from the array using the `lomuto_partition` function and then recursively
 * partitions the array into smaller subarrays. The subarrays are sorted
 * individually, and the sorted elements are combined to obtain the final
 * sorted array. The function modifies the input array in place.
 *
 * Return: This function does not return a value.
 */

void lomuto_sort(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (high - low > 0)
	{
		partition_index = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, partition_index - 1);
		lomuto_sort(array, size, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts the input array using the quicksort
 * algorithm, which is a divide-and-conquer sorting algorithm. The function
 * checks if the array is NULL or has fewer than 2 elements(which are already
 * considered sorted), and if so, it returns without performing any further
 * operations. Otherwise, it calls the `lomuto_sort` function to sort the array
 * in place. The `lomuto_sort` function utilizes the Lomuto partitioning scheme
 * for efficient partitioning of the array during the sorting process.
 *
 * Return: This function does not return a value.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
