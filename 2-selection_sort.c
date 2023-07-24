#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer to be swapped.
 * @b: Pointer to the second integer to be swapped.
 *
 * Description: This function swaps the values of two integers by using
 * pointers to their memory locations.
 *
 * Return: This function does not return a value.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers using the
 * Selection Sort algorithm.
 * @array: Pointer to the first element of the array to be sorted.
 * @size: Number of elements in the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Selection Sort algorithm. It starts by selecting the minimum
 * element from the unsorted part of the array and placing it at the beginning
 * of the sorted part. The function iterates through the array, finding the
 * minimum element and swapping it with the element at the current position.
 * After each swap, the current state of the array is printed using the
 * print_array function to visualize the sorting process.
 *
 * Return: This function does not return a value.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	/* One by one move boundary of unsorted subarray */
	for (i = 0; i < size - 1; i++)
	{
		/* Find the index of minimum element in unsorted array */
		min_index = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
			{
				min_index = j;
				print_array(array, size);
			}

		/* Swap the found minimum element with the first element */
		if (min_index != i)
			swap(&array[min_index], &array[i]);
	}
}
