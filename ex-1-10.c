/*
 * Exercise 1-10
 * Write a program to copy its input to its output,
 * replacing each tab by \t, backspace by \b and backslash by \\
 */

#include <stdio.h>

#define BACKSLASH '\\'

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar(BACKSLASH);
			c = 't';
		}

		if (c == '\b') {
			putchar(BACKSLASH);
			c = 'b';
		}

		if (c == BACKSLASH) {
			putchar(BACKSLASH);
			c = BACKSLASH;
		}

		putchar(c);
	}
}
