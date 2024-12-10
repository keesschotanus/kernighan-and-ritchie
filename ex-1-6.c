/*
 * Exercise 1-6
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

/* copy input to output; 2nd version */
int main()
{
	int c;
	while (c = getchar() != EOF)
		printf("%d\n", c);
	printf("%d\n", c);
}

// Run for example with: ./a.out <ex-1-6.c
// The output is a 1 for every character that is not EOF
// The last line contains a 0 after EOF is encountered.
// Alternatively execute: ./a.out
// Enter data at the terminal and end with Control-D
