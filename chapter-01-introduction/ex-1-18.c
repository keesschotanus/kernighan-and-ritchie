/*
 * Exercise 1-18
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);

int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = get_line(line, MAXLINE)) > 0)
	{
		// The first --len skips the string terminator
		for (--len; len >= 0 && (line[len] == '\t' || line[len] == ' ' || line[len] == '\n'); --len)
			line[len] = '\0';
		if (len >= 0) 
			printf("%s$\n", line);
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
