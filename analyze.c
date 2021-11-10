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
        int* ptr;
        if(c == 0){
            ptr = arrayInitializer(arr, size, asc);
        }else{
            ptr = arrayInitializer(arr, size, desc);
        }
        
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
        double timediv = time_taken/ITERATIONS;
        buf[i].time = timediv;
        buf[i].nlog = timediv/(size*log(size)); //vafan är "nlog"
        buf[i].logn = timediv/log(size);
        buf[i].nlogn = timediv/(size * log(size));
        buf[i].n = timediv/size;
        buf[i].n2 = timediv/pow(size,2);
        buf[i].n3 = timediv/pow(size,3);
    }

}
