/*
 * Exercise 5-3
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 * 
 */

#include <stdio.h>

void strcat(char *s, char *t);

int main()
{
	char s[20] = "Hello, ";
	strcat(s, "World!");
	puts(s);
}

void strcat(char *s, char *t)
{
	// Locate end of string
	while (*s)
		++s;

	// Copy t into s
	while (*s++ = *t++)
		;
}

