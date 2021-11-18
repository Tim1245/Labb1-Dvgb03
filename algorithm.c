#include <stdio.h>
#include "algorithm.h"

//
// Private
//

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int* a, int c, int b) {
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
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
 
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void quick_sort(int *a,int c, int n)
{
	int k;
    if (c < n) {
        k = partition(a, c, n);
        quick_sort(a, c, k-1);
        quick_sort(a, k+1, n);}
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
  
    // Check if x is present at mid
    if (a[m] == v) 
        return m;  
  
    // If x greater, ignore left half  
    if (a[m] < v) 
        l = m + 1; 
  
    // If x is smaller, ignore right half 
    else 
         r = m - 1; 
  }
  
  // if we reach here, then element was not present
  return -1; 
 }
