/*
 * Exercise 2-5
 * Write the function any(s1, s2), which returns the first location in the
 * string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no character from s2.
 */
	
#include <stdio.h>

#define false 0
#define true 1

int any(char s[], char t[]);

int main() 
{
	printf("any(\"abcde\", \"c\") = %d\n", any("abcde", "c"));
	printf("any(\"abcde\", \"q\") = %d\n", any("abcde", "q"));
}

int any(char s[], char t[])
{
	for (int i = 0; s[i]; ++i) {
		for (int j = 0; t[j]; ++j) {
			if (s[i] == t[j])
				return i;
		}
	}

	return -1;
}

// If you don't want 2 return statements
// int any(char s[], char t[])
// {
// 	int result = -1;
// 	for (int i = 0; s[i] && result == -1; ++i) {
// 		for (int j = 0; t[j] && result == -1; ++j) {
// 			if (s[i] == t[j])
// 				result = i;
// 		}
// 	}

// 	return result;
// }

