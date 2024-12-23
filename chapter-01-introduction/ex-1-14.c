/*
 * Exercise 1-14
 * Write a program to print a histogram of the frequencies
 * of different characters in its inputs.
 */

#include <stdio.h>

#define MAX_CHARS 127 // ASCII character range

int main()
{
	int c, i, j, frequency[MAX_CHARS];
	for (i = 0; i < MAX_CHARS; ++i)
		frequency[i] = 0;

	while ((c = getchar()) != EOF) 
		++frequency[c];

	for (i = 0; i < MAX_CHARS; ++i) {
		if (i > 32)
			printf("  %c | ", i); // Print printable characters as char
		else
			printf("%3d | ", i);  // Print non-printable characters as int

		for (j = 0; j < frequency[i]; ++j)
			putchar('*');
		putchar('\n');
	}
}
