/*
 * Exercise 5-5
 * Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n character of their argument strings.
 * Full descriptions are in Appendix B.
 * 
 * I wrote my own versions of these methods.
 * mystrncpy for example, always adds a zero terminator.
 */

#include <stdio.h>
#include <string.h>

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);


int main()
{
	char input1[] = "Testing one two three";
	mystrncpy(input1, "Burpabc", 4);
	printf("input1=%s\n", input1);

	char input2[] = "Hello, ";
	mystrncat(input2, "World!!!", 6);
	printf("input2=%s\n", input2);

	char input3[] = "To be";
	
	printf("mystrncmp(\"To be\", \"To be\", 16)=%d\n", mystrncmp(input3, "To be", 16));
	printf("mystrncmp(\"To be\", \"To be\", 2)=%d\n", mystrncmp(input3, "To be", 2));
	printf("mystrncmp(\"To be\", \"or not to be\", 2)=%d\n", mystrncmp(input3, "or not to be", 2));

}

// Copies at most n characters from t to s.
// Assumes s is long enough
// At the end s will b a zero terminated string
void mystrncpy(char *s, char *t, int n)
{
	for (; *t && n > 0; --n)
		*s++ = *t++;
	*s = '\0';
}

// Adds at most n characters from t to the end of s
void mystrncat(char *s, char *t, int n)
{
	// Locate end of s
	while (*s)
		++s;
	// Copy at most n characters
	for (; *t && n > 0; --n)
		*s++ = *t++;

	*s = '\0';
}

// Compares at most n characters 
int mystrncmp(char *s, char *t, int n)
{
	for ( ; *s == *t && n > 0; s++, t++, --n)
		if (*s == '\0' || n == 0)
			return 0;
	return *s - *t;
}
