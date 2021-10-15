#include "sort.h"

/**
 * aux_arr - create an aux arr
 * @array: arr
 * @new_arr: new arr
 * @size: size
 */
void aux_arr(int *array, int *new_arr, size_t size)
{
	size_t i = 0;

	i = 0;
	while (i < size)
	{
		new_arr[i] = array[i];
		i++;
	}
}

/**
 * m_sort - sort
 * @arr: arr
 * @cop: copy
 * @init: index
 * @half: index
 * @end: index
 */
void m_sort(int *arr, int init, int half, int end, int *cop)
{
	int i = 0, j = 0, k = 0;

	i = init;
	j = half;
	k = init;

	while (k < end)
	{
		if (i < half && (j >= end || arr[i] <= arr[j]))
		{
			cop[k] = arr[i];
			i++;
		}
		else
		{
			cop[k] = arr[j];
			j++;
		}
		k++;
	}
}

/**
 * div_and_con - split
 * @arr: arr
 * @cop: copy
 * @init: index
 * @end: index
 */
void div_and_con(int *cop, size_t init, size_t end, int *arr)
{
	size_t half = 0;

	if (end - init <= 1)
		return;
	half = (end + init) / 2;

	div_and_con(arr, init, half, cop);
	div_and_con(arr, half, end, cop);

	m_sort(cop, init, half, end, arr);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&(cop[init]), half - init);

	printf("[right]: ");
	print_array(&(cop[half]), end - half);

	printf("[Done]: ");
	print_array(&(arr[init]), end - init);
}

/**
 * merge_sort - sort
 * @array: arr
 * @size: arr size
 */
void merge_sort(int *array, size_t size)
{
	int *c_array = NULL;

	c_array = malloc(sizeof(int) * size);

	if (c_array == NULL)
		return;

	aux_arr(array, c_array, size);
	div_and_con(c_array, 0, size, array);

	free(c_array);
}
