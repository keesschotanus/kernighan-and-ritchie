/*
 * Exercise 5-6
 * Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing.
 * 
 * I selected to do two of these functions.
 */

#include <stdio.h>
#include <string.h>

int get_line(char *s, int lim);
void reverse(char *s);

int main()
{
	char input[200];
	get_line(input, 200);
	printf("%s\n", input);

	char r[10] = "abcd";
	reverse(r);
	printf("%s\n", r);
}

/* get_line: read a line into s, return length */
/* Using getline conflicted with same function from the library */
int get_line(char *s, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';

	return i;
}

void reverse(char *s)
{
	char *e = s + strlen(s) -1;
	for ( ; s < e; ++s, --e) {
        int temp = *s;
        *s = *e;
        *e = temp;
	}
}
