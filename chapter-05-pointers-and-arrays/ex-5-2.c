/*
 * Exercise 5-2
 * Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value?
 * 
 * I'm using the same return type as for getint.
 * My solution does not process scientific notation,
 * but that should be easy to add.
 */

#include <stdio.h>
#include <ctype.h>

int getfloat(double *n);

int getch(void);
void ungetch(int);

int main()
{
	double n;
	int result = getfloat(&n);
	printf("Result: %d, n=%g", result, n);
}

int getfloat(double *pn)
{
	double power, fraction;
	int i, sign;
    int c;

    while (isspace(c = getch()))
        ;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	// It is not a number
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
	}
		
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;

	if (c == '.') {
		c = getch();
		for (power = 1.0, fraction = 0.0; isdigit(c); c = getch()) {
			fraction = 10.0 * fraction + c - '0';
			power *= 10;
		}
		*pn += sign * (fraction / power);
	}

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
