#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "analyze.h"
#include "algorithm.h"

//
// Private
//

int* arrayInitializer(int* arr, int arraySize ,const complexity_t cx) {

    switch (cx) {
    case n:
        for (int i = 0; i < arraySize; i++) {
            arr[i] = i+1;
        }
    break;
    case n2:
        for (int i = 0; i < arraySize; i++) {
            arr[i] = arraySize-i;
        }
    break;
    case nlogn:
        srand(time(0));
        for (int i = 0; i < arraySize; i++) {
            arr[i] = rand() % arraySize + 1;
        }  
    default:
        break;
    }

    return arr;
}

complexity_t complexity(const algorithm_t a, const case_t c) {
    switch (a) {
        case bubble_sort_t:
        case insertion_sort_t:
            return c == best_t ? n : (c == worst_t ? n2 : nlogn);
        break;
        case quick_sort_t:
            return c == best_t ? nlogn : (c == worst_t ? n : nlogn);
        break;
        case linear_search_t:
        case binary_search_t:
        default:
            return n;
        break;
    }
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
            ptr = arrayInitializer(arr, size, complexity(a,c));
            /* for(int i=0;i !=size;i++){
                printf("%d\n",ptr[i]);} */
            clock_t t;
            switch (a)
            {
            case bubble_sort_t:
                t = clock();
                bubble_sort(ptr, size);
            break;
            case insertion_sort_t:
                t = clock();
                insertion_sort(ptr, size);
            break;
            case quick_sort_t:
                t = clock();
                quick_sort(ptr, 0, size-1);
            break;
            default:
                break;
            }
           
            
            

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
