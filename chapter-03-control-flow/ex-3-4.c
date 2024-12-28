/*
 * Exercise 3-4
 * In a two's complement number representation our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^(wordsize-1)). Explain why not.
 * Modify it to print that value correctly, regardless of the machine on which
 * it runs.
 * 
 * The problem is that the largest negative number (-128 for a byte) cannot
 * be represented as positive 128 since the largest value for a byte is 127.
 * Using an unsigned int does the trick.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>


void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    char n[20];
    itoa(INT_MIN, n);
    printf("%s\n", n);

}

void itoa(int n, char s[])
{
    int i = 0;
    unsigned int nu = n;

    do {
        s[i++] = nu % 10 + '0';
    } while (( nu /= 10) > 0);
    if (n < 0)
        s[i++] = '-';
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
