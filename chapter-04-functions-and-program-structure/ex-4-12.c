/*
 * Exercise 4-12
 * Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer to a string by calling a recursive routine.
 * 
 * Not sure if my solution is correct.
 * Using pointers would avoid using the static i variable,
 * but pointers are the topic of the next chapter.
 */

#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
    char n[20];
    itoa(0-123, n);
    printf("%s\n", n);

}

void itoa(int n, char s[])
{
    static int i;
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
        itoa(n / 10, s);
    s[i++] = n % 10 + '0';

    s[i] = '\0';
}