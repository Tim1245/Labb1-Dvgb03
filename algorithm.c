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

// Partition function for Quick Sort,   if middlePivot == 1   then use middle pivot     else use lower element as pivot
int partition(int* a, int low, int high, int middlePivot) {

    int pivot;

    if(middlePivot == 1) {
        pivot = a[low + (high - low)/2];
    } else {
        pivot = a[low];
    }

    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  { 
        if (a[j] < pivot)  { 
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
	int high = n-1;
    int low = 0;

    while (low <= high) {
        int mid = low + (high-low)/2;
        if (a[mid] == v) 
            return mid;  
        if (a[mid] < v) 
            low = mid + 1; 
        else 
            high = mid - 1; 
    }
    return -1; 
 }
