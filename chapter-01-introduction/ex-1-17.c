/*
 * Exercise 1-17
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define MAXLINE 81 /* maximum input line length */

int get_line(char line[], int maxline);

int main()
{
	int len;				/* current line length */
	int max;				/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (line[len - 1] != '\n') {
			printf("%s", line);
			int c;
			while((c = getchar()) != EOF && c != '\n')
				putchar(c);
			if (c == '\n')
				putchar('\n');
		}

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
