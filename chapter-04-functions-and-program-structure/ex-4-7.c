/*
 * Exercise 4-7
 * Write a routine unget(s) that will push back an entire string
 * onto the input.
 * Should ungets know about buf and bufp, or should it just use ungetch?
 */

#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);

int main()
{
    return 0;
}

/*
 * Ungets a string.
 * By declaring it here, it does not need knowledge of buf or bufp.
 * Chars are ungotten in reverse order.
 */
void ungets(char s[]) {
    for (int i = strlen(s) - 1; i >= 0; --i)
        ungetch(s[i]);
}

#define BUFSIZE 100

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