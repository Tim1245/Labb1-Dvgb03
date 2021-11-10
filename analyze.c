#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

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
            arr[i] = arraySize-i;
        }
    }

    return arr;
}



//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    int size, i, j;
    double time_taken;
    for (i = 0; i != n; i++) {
        for (j = 0; j < ITERATIONS; j++) {
            size = 512 * pow(2, i);
        int arr[size];
        int* ptr = arrayInitializer(arr, size, asc);
        clock_t t;
            t = clock();
            bubble_sort(ptr,size);
           /* for(int i=0;i !=size;i++){
            printf("%d\n",ptr[i]);
            }*/
            t = clock() - t;
            time_taken = time_taken + ((double)t)/CLOCKS_PER_SEC;
           
        }
        buf[i].size = size;
        buf[i].time = time_taken/ITERATIONS;
    }

}
