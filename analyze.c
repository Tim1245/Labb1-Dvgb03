#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "analyze.h"
#include "algorithm.h"

//
// Private
//

int* arrayInitializer(int* arr, int arraySize ,const direction_t dir) {

    if(dir == asc) {
        for (int i = 0; i < arraySize; i++) {
            arr[i] = i+1;
        }
    } else {
        for (int i = 0; i < arraySize; i++) {
            arr[i] = SIZE_START-i;
        }
    }

    return arr;
}


//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    int size;
    for (int i = 0; i != n; i++) {
        size = 512 * pow(2, i);
        int arr[size];
        int* ptr = arrayInitializer(arr, size, asc);
        for(int i = 0; i != size; i++) {
            if(i == size-1) {
                printf("%d\n", ptr[i]);
            }
        }
    }

}
