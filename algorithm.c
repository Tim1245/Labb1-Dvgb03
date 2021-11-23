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


// Partition for Quick Sort
int partition(int* a, int low, int high) {
    int left, right;
    int pivot;

    left = low;
    right = high;
    pivot = a[low];

    while ( left < right )
    {
        while ( a[right] > pivot )
        right--;

        while ( (left < right) && (a[left] <= pivot) )
        left++;

        if ( left < right )
        swap(&a[left], &a[right] );
    }

    a[low] = a[right];
    a[right] = pivot;

    return right;
}

// Setup to use partition with median
int median(int* a, int low, int high) {
	
    int middle = (low+high)/2;

	if ( &a[low] > &a[middle] )
		swap( &a[middle], &a[low] );
	if ( &a[low] > &a[high] )
		swap( &a[low], &a[high] );
	if ( &a[middle] > &a[high] )
		swap( &a[high], &a[middle] );

	swap(&a[middle], &a[low]);

	return partition(a, low, high);
}



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
            k = median(a, c, n);
        } else {
            k = partition(a, c, n);
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
