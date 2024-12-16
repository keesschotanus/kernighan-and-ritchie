/*
 * Exercise 1-13
 * Write a program to print a histogram of the lengths of words in its inputs.
 * 
 * Words are treated as anything surrounded by whitespace.
 * The frequency of words with length n, are stored in frequency[n -1].
 * 
 */

#include <stdio.h>

#define MAX_WORD_LENGTH 12

main()
{
	int c, i, j, length = 0, frequency[MAX_WORD_LENGTH];

	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		frequency[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') 
		{
			if (length > 0 && length < MAX_WORD_LENGTH) 
				++frequency[length - 1];
			length = 0;
		} else 
	   	{
			++length;
		}
	}

	/* Print histogram horizontally */
	for (i = 0; i < MAX_WORD_LENGTH; ++i)
	{
		printf("%2d | ", i + 1);
		for (j = 0; j < frequency[i]; ++j)
			putchar('*');
		putchar('\n');
	}


	/* Print histogram vertically */
	/* Determine the maximum frequency (is mnumber of rows to print) */
	int max_frequency = frequency[0];
	for (i = 1; i < MAX_WORD_LENGTH; ++i) {
		if (frequency[i] > max_frequency)
			max_frequency = frequency[i];
	}

	int row = 0;
	for (row = max_frequency; row > 0; --row) {
		for (i = 0; i < MAX_WORD_LENGTH; ++i) {
			if (frequency[i] >= row)
				putchar('*');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	printf("%s\n", "123456789");
}
