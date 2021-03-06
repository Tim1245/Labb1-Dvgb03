/*
Tim Axelsson Säfström & Philip Fastberg
Laboration 1 - Funktionsanalyser
DVGB03
*/

#ifndef ANALYZE_H
#define ANALYZE_H

#define SIZE_START 512
#define ITERATIONS 4
#define BILLION 1000000000

// algorithm_t defines different algorithms
typedef enum {
	bubble_sort_t,
	insertion_sort_t,
	quick_sort_t,
	linear_search_t,
	binary_search_t
} algorithm_t;

typedef enum {
	oone,
	ologn,
	on,
	onlogn,
	on2,
	on3
} complexity_t;

typedef enum {
	asc,
	desc,
	unsorted
} direction_t;

// case_t defines different cases
typedef enum {
	best_t,
	worst_t,
	average_t
} case_t;

// comp_dir_t keeps track of complexity and array structure (sorted or unsorted)
typedef struct {
	complexity_t cx;
	direction_t dir;
} comp_dir_t;

// result_t defines a timed measurement for a given array size
typedef struct {
	int size;
	double time, actual, better, worse;
	comp_dir_t comp_dir;
} result_t;

// benchmark benchmarks an algorithm a for a specific case c, writing n results
// to the result buffer buf
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n);
comp_dir_t complexity(const algorithm_t a, const case_t c);

#endif
