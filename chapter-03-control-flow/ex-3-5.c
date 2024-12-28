/*
 * Exercise 3-5
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s.
 * In particular, itob(n,s,16) formats n as a hexadecimal integer in s
 * 
 * For base 2, 0 and 1 are used
 * For base 10, 0-9 are used.
 * For larger bases we use A-Z, so the largest supported base is 36.
 * Adding a-z would support a base upto 62.
 */

#include <stdio.h>
#include <string.h>


void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char n[20];
    for (int i = 2; i <= 36; ++i) {
        itob(127, n, i);
        printf("127, base(%2d)=%7s\n", i, n);
    }

}

void itob(int n, char s[], int b)
{
    int i = 0;
    unsigned int nu = n;

    do {
        // Works with ASCII only
        unsigned mod = nu % b + '0';
        // If the last 'digit' is larger than '9' then skip the symbols after
        // '9' and before 'A'
        s[i++] = mod + (mod <= '9' ?  0 : 7);
    } while (( nu /= b) > 0);
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
