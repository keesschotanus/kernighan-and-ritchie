/*
 * Exercise 3-6
 * Write a version of itoa hat accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must be
 * padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>


void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    char n[20];
    itoa(127, n, 5);
    printf("%s\n", n);

}

void itoa(int n, char s[], int w)
{
    int i = 0;
    unsigned int nu = n;

    do {
        s[i++] = nu % 10 + '0';
    } while (( nu /= 10) > 0);
    if (n < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
	int start, end;
	for (int start = 0, end = strlen(s) - 1; start < end; ++start, --end) {
        int temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    }
}
