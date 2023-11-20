#include "sort.h"

/**
 * bubble_sort - unction that sorts an array of integers
 * @array: int pointer for the array
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i;
	int temp;
	bool sort = false;

	i = size;

	if (array == NULL || size < 2)
	return;

	while (sort == false)
	{
		sort = true;
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				sort = false;
			}
		}
		i--;
	}
}
