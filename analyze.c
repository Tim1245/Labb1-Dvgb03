#include <stdbool.h>
#include <stdio.h>

#include "analyze.h"
#include "algorithm.h"

//
// Private
//

int bestCaseArray[SIZE_START];
int worstCaseArray[SIZE_START];


void arrayInitializer(const direction_t dir) {
    if(dir == asc) {
        for (int i = 0; i < (sizeof(bestCaseArray) / sizeof(int)); i++) {
            bestCaseArray[i] = i+1;
            printf("%d\n", bestCaseArray[i]);
        }
    } else {
        for (int i = 0; i < (sizeof(bestCaseArray) / sizeof(int)); i++) {
            bestCaseArray[i] = SIZE_START-i;
            printf("%d\n", bestCaseArray[i]);
        }
    }
}


//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    
}
