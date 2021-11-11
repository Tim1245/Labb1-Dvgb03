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
    case random:
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
                comp_dir.cx = n;
                comp_dir.dir = asc;
            } else if (c == worst_t) {
                comp_dir.cx = n2;
                comp_dir.dir = desc;
            } else {
                comp_dir.cx = n2;
                comp_dir.dir = random;
            }
            return comp_dir;
        break;
        case quick_sort_t:
            if(c == best_t) {
                comp_dir.cx = nlogn;
                comp_dir.dir = random;
            } else if (c == worst_t) {
                comp_dir.cx = n2;
                comp_dir.dir = desc;
            } else {
                comp_dir.cx = nlogn;
                comp_dir.dir = random;
            }
            return comp_dir;
        break;
        case linear_search_t:
        case binary_search_t:
        default:
            comp_dir.cx = n;
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
    double time_taken;
    comp_dir_t comp_dir = complexity(a,c);

    for (i = 0; i != n; i++) {
        for (j = 0; j < ITERATIONS; j++) {
            size = 512 * pow(2, i);
            int arr[size];
            int* ptr;
            ptr = arrayInitializer(arr, size, comp_dir.dir);
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
    }

    buf[0].comp_dir = comp_dir;

}
