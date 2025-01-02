/*
 * Exercise 4-13
 * Write a recursive version of the function reverse(s),
 * which reverses the string s in place.
 * 
 * I did now want reverse(s) to have any other parameters than s.
 * Using static variables is I think correct if you look at what you learn
 * in chapter 4.
 */

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char s[] = "abcd";
    reverse(s);
    printf("%s\n", s);

}

void reverse(char s[])
{
    static int begin = 0, end = 0;
    if (end == 0)
        end = strlen(s) - 1;
    
    if (begin < end) {
        char temp  = s[begin];
        s[begin++] = s[end];
        s[end--] = temp;
        reverse(s);
    }
}