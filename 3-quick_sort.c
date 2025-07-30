#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	if (a != b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * lomuto_partition - Partitions an array using Lomuto scheme
 * @array: The array
 * @low: Starting index of the partition
 * @high: Ending index (pivot)
 * @size: Size of the full array (for printing)
 *
 * Return: Index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	if (array[high] < array[i + 1])
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_rec - Recursively sorts subarrays
 * @array: The array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the full array
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = lomuto_partition(array, low, high, size);

		quicksort_rec(array, low, p - 1, size);
		quicksort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick Sort (Lomuto)
 * @array: The array to sort
 * @size: Number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_rec(array, 0, size - 1, size);
}
