/*
 * Exercise 5-11
 * Modify the program detab (written as exercises in Chapter 1)
 * to accept a list of tab stops as arguments.
 * Use the default tab settings if there are no arguments.
 */

#include <stdio.h>

#define TAB_SIZE 4

int main() 
{
	int c, position = 0;
	while ((c = getchar()) != EOF) {
		++position;
		if (c == '\n') {
			putchar(c);
			position = 0;
		} else if (c == '\t') {
			putchar(' ');
			while (position % TAB_SIZE) {
				putchar(' ');
				++position;
			}
		}
		else 
			putchar(c);
	}

	return 0;
}

