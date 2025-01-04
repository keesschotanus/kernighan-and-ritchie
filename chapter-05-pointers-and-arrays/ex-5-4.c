/*
 * Exercise 5-4
 * Write the function strend(s,t), which returns 1 if the string t occurs at the
 * end of the string s, and zero otherwise.
 */

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main()
{
	char s[20] = "Hello, World!";
	printf("%d", strend(s, "World!"));
	printf("%d", strend(s, "Hello"));
}

/*
 * Determines if s ends with t.
 * Returns 1 if it does, 0 if it doesn't.
*/
int strend(char *s, char *t)
{
	// Protect against t being longer than s
	int length_s = strlen(s);
	int length_t = strlen(t); 
	if (length_t > length_s)
		return 0;

	s += length_s - length_t;
	while (*s && *s == *t)
		++s, ++t;

	return *s == *t;
}

