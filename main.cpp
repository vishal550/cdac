#include <stdio.h>
#include "array.h"

int main()
{
	int arr[] = { 55, 99, 44, 33, 77, 11, 88, 22, 66 };
	int index;
	print_arr(arr, 9);
	//sel_sort(arr, 5);
	//bubble_sort(arr, 5);
	//ins_sort(arr, 5);
	//quick_sort(arr, 0, 9 - 1);
	//merge_sort(arr, 0, 9 - 1);
	//print_arr(arr, 9);
	index = lin_search(arr, 9, 80);
	if (index == -1)
		printf("Ele Not Found.\n");
	else
		printf("Ele Found At %d.\n", index);
	return 0;
}
