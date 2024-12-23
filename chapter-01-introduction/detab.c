/*
 * Exercise 1-20
 * Write a program detab that replaces tabs in the input 
 * with the proper number of blanks to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns
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


// Run: ./detab <detab.c and check the 1's are aligned with the T's
//  T   T   T   T   T   T   T
//	1	2	12	123	123	12341

/*
1	5	9	1	1	2
			3	7	1
*/