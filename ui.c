#include "ui.h"
#include "io.h"
#include "analyze.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//
// Private
//

static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		"Bubble sort worst case",
		"Bubble sort average case\n",
		"Insertion sort best case",
		"Insertion sort worst case",
		"Insertion sort average case\n",
		"Quick sort best case",
		"Quick sort worst case",
		"Quick sort average case\n",
		"Linear search best case",
		"Linear search worst case",
		"Linear search average case\n",
		"Binary search best case",
		"Binary search worst case",
		"Binary search average case\n",
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

static const char * const algorithm_str[] = {
	[bubble_sort_t] = "Bubble Sort",
	[insertion_sort_t] = "Insertion Sort",
	[quick_sort_t] = "Quick Sort",
	[linear_search_t] = "Linear Search",
	[binary_search_t] = "Binary Search"
};

static const char * const best_str[] = {
	[best_t] = "Best",
	[worst_t] = "Worst",
	[average_t] = "Average"
};

static const char * const complexity_str[] = {
	[on] = "n",
	[on2] = "n^2",
	[on3] = "n^3",
	[ologn] = "logn",
	[onlogn] = "nlogn",
	[oone] = "1"
};

static void ui_print_table(const algorithm_t a, const case_t c, result_t *buf)
{	
	ui_line('*', PRINT_WIDTH);
	printf("\t\t\t%s: %s\n", algorithm_str[a], best_str[c]);
	ui_line('~', PRINT_WIDTH);
	printf("Size\tT (s)\t\tT/%s\t\tT/%s\t\tT/%s\n", (buf[0].comp_dir.cx > 0 ? complexity_str[buf[0].comp_dir.cx-1] : complexity_str[buf[0].comp_dir.cx]), complexity_str[buf[0].comp_dir.cx], complexity_str[buf[0].comp_dir.cx+1]);
	ui_line('~', PRINT_WIDTH);
	for(int i = 0;i < RESULT_ROWS; i++) {
		printf("%d\t%.8f\t%e\t%e\t%e\n", buf[i].size, buf[i].time, buf[i].better, buf[i].actual, buf[i].worse);
	}

}

//
// Public
//

void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
			// Bubble Sort
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				ui_print_table(bubble_sort_t, best_t, result);
				break;
			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				ui_print_table(bubble_sort_t,  worst_t, result);
				break;
			case 'e':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				ui_print_table(bubble_sort_t,  average_t, result);
				break;
			// Insertion Sort
			case 'f':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				ui_print_table(insertion_sort_t,  best_t, result);
				break;
			case 'g':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
				ui_print_table(insertion_sort_t,  worst_t, result);
				break;
			case 'h':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
				ui_print_table(insertion_sort_t,  average_t, result);
				break;
			// Quick Sort
			case 'i':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				ui_print_table(quick_sort_t,  best_t, result);
				break;
			case 'j':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
				ui_print_table(quick_sort_t,  worst_t, result);
				break;
			case 'k':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
				ui_print_table(quick_sort_t,  average_t, result);
				break;
			// Linear Search
			case 'l':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				ui_print_table(linear_search_t,  best_t, result);
				break;
			case 'm':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				ui_print_table(linear_search_t,  worst_t, result);
				break;
			case 'n':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				ui_print_table(linear_search_t,  average_t, result);
				break;
			// Binary Search
			case 'o':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				ui_print_table(binary_search_t,  best_t, result);
				break;
			case 'p':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				ui_print_table(binary_search_t,  worst_t, result);
				break;
			case 'q':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				ui_print_table(binary_search_t,  average_t, result);
				break;
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
