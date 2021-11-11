#include <stdio.h>
#include "algorithm.h"

//
// Private
//

int arraySortedOrNot(int* a, int n)
{
    if (n == 1 || n == 0)
        return 1;

    if (a[n - 1] < a[n - 2])
        return 0;
        
    return arraySortedOrNot(a, n - 1);
}

int partition(int* a, int c, int b) {
    int pivot, lower, upper, temp;
    pivot = a[c];
    lower = c + 1;
    upper = b;
    do {
        while (a[lower] <= pivot && lower <= upper) lower = lower + 1;
        while (a[upper] > pivot && lower <= upper) upper = upper - 1;
        if (lower <= upper) {
            temp = a[lower];
            a[lower] = a[upper];
            a[upper] = temp;
            lower = lower + 1;
            upper = upper - 1;}
        }
    while (lower <= upper);
    temp = a[upper];
    a[upper] = a[c];
    a[c] = temp;
return upper;}

//
// Public
//

void bubble_sort(int *a, int n)
{	
    if(arraySortedOrNot(a, n)) {
        return;
    }

    int swap, i, j;

	for(i = 0; i < n-1; i++){ 
        for(j = 0; j < n-i-1; j++)
            if(a[j]>a[j+1]){

                swap =a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
               
            }
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
	return false; // TODO: linear search
}

bool binary_search(const int *a, int n, int v)
{
	return false; // TODO: binary search
}
