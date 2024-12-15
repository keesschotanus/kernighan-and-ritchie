/*
 * Exercise 1-19
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void reverse(char []);

int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = get_line(line, MAXLINE)) > 0)
	{
		reverse(line);
		printf("%s", line);
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

void reverse(char line[]) 
{
	// Determine length of line
	int start, end;
	for (end = 0; line[end] != '\0'; ++end)
		;

	--end; // Index of last char in line array
	if (end > 0 && line[end] == '\n')
		--end; // Skip last character if it is a newline

    for (start = 0; start < end; start++, --end)
	{
		// Swap start char with end char
        int temp = line[start];
        line[start] = line[end];
        line[end] = temp;
    }
}
