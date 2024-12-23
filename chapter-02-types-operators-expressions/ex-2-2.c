/*
 * Exercise 2-2
 * Write a loop equivalent to the for loop above without using && or ||.
 * Comes down to rewriting the statement below without using && or ||
 * for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
 *     s[i] = c;
 * 
 * This code would be way easier if we could use a break statement,
 * but we will learn about break after this exercise.
 */

#include <stdio.h>

#define MAXLINE 100

int get_line(char s[], int lim);

int main() 
{
	char line[MAXLINE];		/* current input line */
	int len;

	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("%s", line);
	}

}

int get_line(char s[], int lim)
{
	int c, i = 0, done = 0;
	while (done != 1) {
		if ((c = getchar()) == EOF) {
			done = 1;
			s[i] = '\0';
		} else {
			s[i++] = c;
			if (c == '\n') {
				s[i] = '\0';
				done = 1;
			}
		}
	}

	return i;
}
