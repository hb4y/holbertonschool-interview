#include "sort.h"

/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: arr of int
 * @size: length
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		tmp_hep(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (i != 0)
			tmp_swap(&array[0], &array[i], array, size);
		tmp_hep(array, i, 0, size);
	}

}

/**
 * tmp_hep - temporary heap
 * @array: original arr
 * @size: size
 * @i: index
 * @tmp_size: full size
 */
void tmp_hep(int *array, int size, int i, int tmp_size)
{
	int max = i;
	int left_child = (2 * i) + 1;
	int rigth_child = (2 * i) + 2;

	if (left_child < size && array[left_child] > array[max])
		max = left_child;

	if (rigth_child < size && array[rigth_child] > array[max])
		max = rigth_child;

	if (max != i)
	{
		tmp_swap(&array[i], &array[max], array, tmp_size);
		tmp_hep(array, size, max, tmp_size);
	}

}

/**
 * tmp_swap - change vals
 * @first_v: int
 * @second_v: int
 * @array: arr
 * @size: length
 */
void tmp_swap(int *first_v, int *second_v, int *array, int size)
{
	int tmp = *first_v;

	*first_v = *second_v;
	*second_v = tmp;

	print_array(array, size);
}
