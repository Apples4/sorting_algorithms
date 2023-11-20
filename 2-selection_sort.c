#include "sort.h"

/**
 * selection_sort - function  sorts an array of integers in ascending order
 * @array: pointer to the number
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = (array + j);
		}
		if ((array + i) != min)
		{
			temp = *(array + i);
			*(array + i) = *min;
			*min = temp;
			print_array(array, size);
		}
	}
}
