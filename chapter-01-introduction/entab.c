/*
 * Exercise 1-21
 * Write a program entab that replaces strings of spaces
 * by the minimum number of tabs and blanks, to achieve
 * the same spacing.
 * Use the same tab stops as for detab.
 * 
 * In theory, this program works with any line length.
 */

#include <stdio.h>

#define TAB_SIZE 4

void entab(char buffer[], int length);

int main() 
{
	int c;
	char buffer[TAB_SIZE];
	int  length = 0; // Number of characters in the buffer

	while ((c = getchar()) != EOF) {
    	buffer[length++] = c;
    	if (length % TAB_SIZE == 0 || c == '\n' || c == '\t') {
    		entab(buffer, length);
			length = 0;
		}
	}

	// Write remaining chars (if any) in buffer
	if (length != 0)
		entab(buffer, length);

	return 0;
}

/*
 * Replaces characters from the supplied buffer with tabs
 * or writes the characters as-is.
 * Characters are written as-is, unless the last characters
 * in the buffer are spaces.
 * A single space at the end is kept, but multiple spaces are
 * replaced with a single tab character.
 */
void entab(char buffer[], int length)
{
	// Determine position of last space (from the right) in the buffer
	int spc = length;
	while (spc > 0 && buffer[spc - 1] == ' ')
		--spc;

	// Print non space characters in buffer
	for (int i = 0; i < spc; ++i) {
		putchar(buffer[i]);
	}

	if (length - spc == 1)
		putchar(' '); 	// Buffer ends with single space
	else if (length - spc > 1)
		putchar('\t');	// Buffer ends with multiple spaces
}
