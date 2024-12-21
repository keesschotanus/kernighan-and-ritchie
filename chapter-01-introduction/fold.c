/*
 * Exercise 1-22
 * Write a program to "fold" long input lines into two ore more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input.
 * 
 * Make sure your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column.
 *
 * This program handles lines of unlimited length.
 * It doesn't handle tabs very well.
 */

#include <stdio.h>

#define FOLD 40 // Postion to fold at

void write(char s[], int length);

int main()
{
	char line[FOLD + 1]; // Current line with room for a linefeed
	int length = 0;
	int space_pos = -1; // Position at which a space is found or -1
    char c;

	while ((c = getchar()) != EOF) 
	{
		if (c == ' ' || c == '\t')
			space_pos = length;

		line[length++] = c;

		if (c == '\n')
		{
			// new-line located before we have to fold, so simply write the line
    		write(line, length);
			length = 0;
			space_pos = -1;			
		} else if (length == FOLD + 1)
		{
			if (space_pos == -1)
			{
				// No space found, just break
	    		write(line, length);
				putchar('\n');
				length = 0;
				space_pos = -1;
			}
			else
			{
				// Break at the space we found
				line[space_pos] = '\n';
	    		write(line, space_pos);

				// Copy chars at end of the buffer to the beginning
				for (int i = 0; space_pos + i <= length; ++i)
					line[i] = line[space_pos + i];

				length = length - space_pos;
				space_pos = -1;
			}
		}

	}

	// Write what remains in the buffer
	write(line, length);
}

/*
 * Writes length characters of the supplied line.
 * One possible optimization is to add a null terminator
 * to the line and then use printf or puts to write it.
 */
void write(char line[], int length)
{
	for (int i = 0; i < length; ++i)
		putchar(line[i]);
}
