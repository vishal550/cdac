#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void print_arr(int a[], int n)
{
	int i;
	printf("ARR : ");
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
}

void sel_sort(int a[], int n)
{
	int i, j;
	for (i = 0; i<n - 1; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (a[i] > a[j])
				SWAP(a[i], a[j], int);
		}
	}
}

void bubble_sort(int a[], int n)
{
	int i, j;
	for (i = 0; i<n - 1; i++)
	{
		for (j = 0; j<n - 1; j++)
		{
			if (a[j] > a[j + 1])
				SWAP(a[j], a[j + 1], int);
		}
	}
}

void ins_sort(int a[], int n)
{
	int temp, i, j;
	for (i = 1; i<n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}

void quick_sort(int a[], int left, int right)
{
	// 0. if single ele in part or invalid part, return.
	if (left >= right)
		return;
	// 1. pivot is a[left]
	// 2. start index i from left, j from right
	int i = left, j = right;
	while (i < j)
	{
		// 3. from left find ele > pivot.
		while (i <= right && a[i] <= a[left])
			i++;
		// 4. from right find ele <= pivot
		while (a[j] > a[left])
			j--;
		// 5. if i < j, swap a[i] & a[j]
		if (i < j)
			SWAP(a[i], a[j], int);
	}// 6. repeat 3-5, while i < j
	// 7. swap a[left] with a[j]
	SWAP(a[left], a[j], int);
	// 8. apply quick sort to left part: left to j-1
	quick_sort(a, left, j - 1);
	// 9. apply quick sort to right part: j+1 to right
	quick_sort(a, j + 1, right);
}

void merge_sort(int a[], int left, int right)
{
	// 0. if single ele in part or invalid part, return.
	if (left >= right)
		return;
	//1. divide array in two equal parts.
	int mid = (left + right) / 2;
	//2. sort left part i.e. left to mid. ???
	merge_sort(a, left, mid);
	//3. sort right part i.e. mid+1 to right. ???
	merge_sort(a, mid + 1, right);
	//4. allocate temp array which can accomodate both parts.
	int n = right - left + 1;
	int *temp = (int*)malloc(n * sizeof(int));
	// ** merge both parts into that temp array **
	// 5. index i for left part, j for right part, k for temp array
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		//6. compare a[i] & a[j], whichever is smaller copy that & incr that index, also incr k
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//7. copy remaining eles of other part.
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= right)
		temp[k++] = a[j++];
	//8. overrwrite temp array back to original array at proper pos (left ele onwards)
	memcpy(a + left, temp, n*sizeof(int)); //???
	free(temp);
}

int lin_search(int a[], int n, int key)
{
	int i;
	for (i = 0; i<n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return -1;
}

int bin_search(int a[], int n, int key)
{
	int mid, left = 0, right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key == a[mid])
			return mid;
		if (key < a[mid])
			right = mid - 1;
		else //(key > a[mid])
			left = mid + 1;
	}
	return -1;
}

















