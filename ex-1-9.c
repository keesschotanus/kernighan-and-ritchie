/*
 * Exercise 1-9
 * Write a program to copy its input to its output,
 * replacing one or more blanks by a single blank.
 */

#include <stdio.h>

main()
{
	int c;
	int inSpace;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (inSpace == 0) 
			{
				inSpace = 1;
				putchar(c);
			}
		}

		// Else has not been discussed yet
		if (c != ' ')
		{
			inSpace = 0;
			putchar(c);
		}
	}
}
