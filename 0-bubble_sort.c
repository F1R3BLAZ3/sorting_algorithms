#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble Sort.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 * Description: This function sorts the elements of the integer array 'array'
 * in ascending order using the Bubble Sort algorithm. It repeatedly compares
 * adjacent elements in the array and swaps them if they are in the wrong order
 * The process is repeated until the entire array is sorted in ascending order.
 * The function includes optimizations:
 *  - If the size of the array is less than 2, it is already sorted, so the
 *    function returns early without performing any unnecessary iterations.
 *  - If no swaps were made in a pass, it means the array is already sorted,
 *    and the sorting process terminates early to improve efficiency.
 * The function also prints the array after each swap using the 'print_array'
 * function to visualize the sorting process.
 *
 * Return: This function does not return a value.
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, i;
	int temp, swapped;

	for (n = 0; n < size - 1; n++)
	{
		if (size < 2)
			break;

		swapped = 0;
		/*
		 * Last i elements are already in place,
		 * so we don't need to compare them
		 */
		for (i = 0; i < size - n - 1; i++)
		{
			/*
			 * If the current element is greater than the next
			 * element, swap them
			 */
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
