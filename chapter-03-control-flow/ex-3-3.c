/*
 * Exercise 3-3
 * Write a function expand(s1, s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */

#include <stdio.h>
#include <string.h>


void expand(char s1[], char s2[]);

int main()
{
    char output[100];
    expand("-a-b-c-1-5-", output);
    printf("%s\n", output);
}

void expand(char s1[], char s2[])
{
    // We keep track of the previous and next character
    int j = 0, previous = '\0', next;
    for (int i = 0; s1[i]; ++i) {
        next = s1[i + 1];
        if (s1[i] != '-') {
            s2[j++] = s1[i];
        } else {
            // Located a hyphen
            if (previous == '\0' || next == '\0') {
                s2[j++] = s1[i]; // Dangling hyphen
            } else {
                // For "a-d" we print bc since a has been printed and d will be 
                for (int c = previous + 1; c < next; ++c)
                    s2[j++] = c;
            }
        }
        previous = s1[i];
    }

    s2[j] = '\0';
}