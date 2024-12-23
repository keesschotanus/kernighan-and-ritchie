#include <stdio.h>
/*
 * Exercise 1-8
 * Write a program that count blanks, tabs and newlines.
 */

main()
{
	int c;
	long blanks, tabs, nl;
	
	blanks = 0;
	tabs = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == '\t')
			++tabs;
		if (c == ' ')
			++blanks;
	}
	printf("#blanks=%ld, #tabs=%ld, #newlines=%ld\n", blanks, tabs, nl);
}
