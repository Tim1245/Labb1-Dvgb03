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

int* arrayInitializer(int* arr, int arraySize ,const direction_t dir) {

    switch (dir) {
    case asc:
        for (int i = 0; i < arraySize; i++) {
            arr[i] = i+1;
        }
    break;
    case desc:
        for (int i = 0; i < arraySize; i++) {
            arr[i] = arraySize-i;
        }
    break;
    case unsorted:
        srand(time(0));
        for (int i = 0; i < arraySize; i++) {
            arr[i] = rand() % arraySize + 1;
        }  
    default:
        break;
    }

    return arr;
}


comp_dir_t complexity(const algorithm_t a, const case_t c) {
    comp_dir_t comp_dir;
    switch (a) {
        case bubble_sort_t:
        case insertion_sort_t:
            if(c == best_t) {
                comp_dir.cx = on;
                comp_dir.dir = asc;
            } else if (c == worst_t) {
                comp_dir.cx = on2;
                comp_dir.dir = desc;
            } else {
                comp_dir.cx = on2;
                comp_dir.dir = unsorted;
            }
            return comp_dir;
        break;
        case quick_sort_t:
            if(c == best_t) {
                comp_dir.cx = onlogn;
                comp_dir.dir = asc;
            } else if (c == worst_t) {
                comp_dir.cx = on2;
                comp_dir.dir = asc;
            } else {
                comp_dir.cx = onlogn;
                comp_dir.dir = unsorted;
            }
            return comp_dir;
        break;
        case linear_search_t:
            if(c == best_t) {
                comp_dir.cx = oone;
                comp_dir.dir = asc;
            } else if (c == worst_t) {
                comp_dir.cx = on;
                comp_dir.dir = asc;
            } else {
                comp_dir.cx = on;
                comp_dir.dir = asc;
            }
            return comp_dir;
        break;
        case binary_search_t:
             if(c == best_t) {
                comp_dir.cx = oone;
                comp_dir.dir = asc;
            } else if (c == worst_t) {
                comp_dir.cx = ologn;
                comp_dir.dir = asc;
            } else {
                comp_dir.cx = ologn;
                comp_dir.dir = asc;
            }
            return comp_dir;
        break;
        default:
            comp_dir.cx = on;
            comp_dir.dir = asc;
            return comp_dir;
        break;
    }
}



//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    int size, i, j;
    double time_taken = 0;
    comp_dir_t comp_dir = complexity(a,c);

    for (i = 0; i < n; i++) {
        for (j = 0; j < ITERATIONS; j++) {
            size = 512 * pow(2, i);
            int arr[size];
            int* ptr;
            ptr = arrayInitializer(arr, size, comp_dir.dir);
           

            struct timespec start, stop;
            switch (a)
            {
            case bubble_sort_t:
                clock_gettime(CLOCK_MONOTONIC, &start);
                bubble_sort(ptr, size);
            break;
            case insertion_sort_t:
                clock_gettime(CLOCK_MONOTONIC, &start);
                insertion_sort(ptr, size);
            break;
            case quick_sort_t:
                clock_gettime(CLOCK_MONOTONIC, &start);
                quick_sort(ptr, (c == best_t ? size/2 : 0), size-1);
            case linear_search_t:
                clock_gettime(CLOCK_MONOTONIC, &start);
                linear_search(ptr, size, (c == best_t ? 1 : (c == worst_t ? size : size/2)));   // SIZE/2 ??? hur funkar average case här
            break;
            case binary_search_t:
                clock_gettime(CLOCK_MONOTONIC, &start);
                binary_search(ptr,size,(c == best_t ? size/2 : (c == worst_t ? size + 1 : 1)));
            break;
            default:
                break;
            }
            clock_gettime(CLOCK_MONOTONIC, &stop);
            
            time_taken += BILLION * (stop.tv_sec - start.tv_sec) + stop.tv_nsec - start.tv_nsec;
        }


        buf[i].size = size;
        time_taken = (time_taken/BILLION)/ITERATIONS;
        buf[i].time = time_taken;
        switch(comp_dir.cx){
            case on:
                buf[i].actual = (time_taken)/size;
                buf[i].better = time_taken/log2(size);
                buf[i].worse = time_taken/(size*log2(size));
            break;
            case on2:
                buf[i].actual = time_taken/pow(size, 2);
                buf[i].better = time_taken/(size*log2(size));
                buf[i].worse = time_taken/pow(size,3);
            break;
            case ologn:
                buf[i].actual = time_taken/log2(size);
                buf[i].better = time_taken;
                buf[i].worse = (time_taken)/size;
            break;
            case onlogn:
                buf[i].actual = time_taken/(size*log2(size));
                buf[i].better = (time_taken)/size;
                buf[i].worse = time_taken/pow(size, 2);
            break;
            case oone:
                buf[i].actual = time_taken;
                buf[i].better = time_taken;
                buf[i].worse = time_taken/log2(size);
            break;
            default:
            break;
        }
        
    }

    buf[0].comp_dir = comp_dir;

}
