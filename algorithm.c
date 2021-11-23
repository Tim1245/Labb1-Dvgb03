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

// Setup to use partition with low or middle element
int partition(int* a, int low, int high, int cx) {

    int pivot;

    if(cx == 0) {
            pivot = a[low + (high - low)/2];
    } else {
            pivot = a[low];
    }

    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (a[j] < pivot) 
        { 
            i++;
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[high]); 
    return (i + 1); 
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
        k = partition(a, c, n, cx);
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
