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
	// TODO: insertion sort
}

void quick_sort(int *a, int n)
{
	// TODO: quick sort
}

bool linear_search(const int *a, int n, int v)
{
	return false; // TODO: linear search
}

bool binary_search(const int *a, int n, int v)
{
	return false; // TODO: binary search
}
