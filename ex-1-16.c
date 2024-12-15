/*
 * Exercise 1-16
 * Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrary long input lines
 * and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 60 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved */

	while ((len = get_line(line, MAXLINE)) > 0)
	{
		if (line[len - 1] != '\n')
		{
			// Buffer was full, keep reading to determine actual length
			int c;
			while ((c = getchar()) != EOF && c != '\n')
				++len;
			if (c == '\n')
				++len;
			printf("%5d %s\n", len, line);
		} else
			printf("%5d %s", len, line);
	}

	return 0;
}

/* get_line: read a line into s, return length */
/* Using getline conflicted with same function from the library */
int get_line(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

