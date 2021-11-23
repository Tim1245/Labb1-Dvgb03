#include <stdio.h>
#include "algorithm.h"

//
// Private
//

// Swap function for Quick Sort and Bubble Sort
void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int partition_pivot_last(int* a, int low, int high) {
	int pivot = a[high];
	int i = (low - 1);
 
	for (int j = low; j < high; j++) {
		if (a[j] < pivot) {
		swap(&a[++i], &a[j]);
		}
	}
 
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

int partition_pivot_median(int* a, int low, int high) {
	
	int pivot;
	int mid = (low + high) / 2;
	if (a[mid] < a[low]) 
		swap(&a[mid], &a[low]);
	if (a[high] < a[low])
		swap(&a[high], &a[low]);
	if (a[high] < a[mid])
		swap(&a[high], &a[mid]);
	swap(&a[mid], &a[high-1]);
	
	pivot = a[high-1];

    swap(&a[pivot], &a[low]);
 
	return partition_pivot_last(a, low, high);
}

int partition_pivot_first(int* a, int c, int b) {
    int pivot, lower, upper;
    pivot = a[c];
    lower = c + 1;
    upper = b;
    do {
        while (a[lower] <= pivot && lower <= upper) lower = lower + 1;
        while (a[upper] > pivot && lower <= upper) upper = upper - 1;
        if (lower <= upper) {
            swap(&a[lower], &a[upper]);
            lower = lower + 1;
            upper = upper - 1;}
        }
    while (lower <= upper);
        swap(&a[upper], &a[c]);
return upper;}

//
// Public
//

void bubble_sort(int *a, int n)
{	
    int i, j;
    bool swapped;
    
    for (i = 0; i < n-1; i++) {
        swapped = false;

        for (j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
                swapped = true;
            }
        }
        
        if (swapped == false)
            break;
    }
}

void insertion_sort(int *a, int n)
{
	int i, key, j;
    for (i = 0; i < n; i++) {
        key = a[i];
        j = i - 1;
 
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void quick_sort(int *a,int c, int n, int cx)
{
	int k;
    if (c < n) {
        if(cx == 0) {
            k = partition_pivot_median(a, c, n);
        } else {
            k = partition_pivot_first(a, c, n);
        }
        
        quick_sort(a, c, k-1, cx);
        quick_sort(a, k+1, n, cx);
    }
}

bool linear_search(const int *a, int n, int v)
{
    for (int i = 0; i < n; i++)
        if (a[i] == v)
            return true;
    return false;
}

bool binary_search(const int *a, int n, int v)
{
	int r = n-1;
    int l = 0;

    while (l <= r)
    {
    int m = l + (r-l)/2;
    if (a[m] == v) 
        return m;  
    if (a[m] < v) 
        l = m + 1; 
    else 
         r = m - 1; 
    }
    return -1; 
 }
