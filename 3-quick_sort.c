#include "sort.h"

/**
 * split - function to sort using Lomuto
 * @array: pointer to int n
 * @size: size of the array
 * @y: divider high
 * @x: divider low
 * Return: Nothing
 */
int split(int *array, size_t size, int y, int x)
{
	int *p, x_high, y_low, temp;

	p = array + x;
	for (x_high = y_low = y; y_low < x; y_low++)
	{
		if (array[y_low] < *p)
		{
			if (x_high < y_low)
			{
				temp = array[y_low];
				array[y_low] = array[x_high];
				array[x_high] = temp;
				print_array(array, size);
			}
			x_high++;
		}
	}
	temp = array[x_high];
	array[x_high] = array[x];
	array[x] = temp;
	print_array(array, size);
	return (x_high);
}

/**
 * split_sort - recursive function
 * @array: array to be sorted
 * @size: size of the array
 * @x: divider high
 * @y: divider low
 * Return: Nothing
 */
void split_sort(int *array, size_t size, int y, int x)
{
	int part;

	if (x - y > 0)
	{
		part = split(array, size, y, x);
		split_sort(array, size, y, part - 1);
		split_sort(array, size, part + 1, x);
	}
}

/**
 * quick_sort - quick sort function for array
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	split_sort(array, size, 0, size - 1);
}
