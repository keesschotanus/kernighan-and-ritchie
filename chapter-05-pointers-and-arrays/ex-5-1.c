/*
 * Exercise 5-1
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero.
 * Fix it to push such a character back on the input.
 */

#include <stdio.h>
#include <ctype.h>

int getint(int *n);

int getch(void);
void ungetch(int);

int main()
{
	int n;
	int result = getint(&n);
	printf("Result: %d, n=%d", result, n);
}

int getint(int *pn)
{
    int c, sign, signchar;

    while (isspace(c = getch()))
        ;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	// It is not a number
		return 0;
	}


	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		signchar = c;
		c = getch();
		if (!isdigit(c)) {
			// Unget sign char and nondigit
			ungetch(c);
			ungetch(signchar);
			return 0;
		}
	}
		
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);

	return c;

}

#define BUFSIZE 2

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

/* Get a (possibly pushed back) character */
int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}