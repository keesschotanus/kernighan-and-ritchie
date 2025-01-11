/*
 * Exercise 5-7
 * Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage.
 * How much faster is the program?
 * 
 * Instead of using an array I decided to use the malloc library function to
 * allocate data for each line.
 * This is probably the slowest version but it handles MAXLINES of potentially
 * very long lines (limited by memory.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000		// Max #lines to be sorted

char *lineptr[MAXLINES];	// Pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void q_sort(char *v[], int left, int right);

int main()
{
	int nlines;				// Number of input lines read
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		q_sort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000			// Max length of a single input line
int get_line(char *s, int lim);

int readlines(char *lineptr[], int maxlines) 
{
	int len, nlines = 0;
	char *p, line[MAXLEN];

	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';	// Delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* get_line: read a line into s, return length */
/* Using getline conflicted with same function from the library */
int get_line(char *s, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		*s++ = c;
	if (c == '\n') {
		*s++ = c;
		++i;
	}
	*s = '\0';

	return i;
}


void q_sort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;

	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i<= right; ++i)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	q_sort(v, left, last - 1);
	q_sort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}