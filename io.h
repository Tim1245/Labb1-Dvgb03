/*
Tim Axelsson Säfström & Philip Fastberg
Laboration 1 - Funktionsanalyser
DVGB03
*/

#ifndef IO_H
#define IO_H

// read_line reads at least one and at most n-2 characters from stdin, writing a
// null-terminated result to buf; possible overflows are handled and and the
// length of buf is returned, e.g., 5 for "hello" and 0 on error.
int read_line(char *buf, int n);

#endif
