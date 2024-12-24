/*
 * Exercise 2-4
 * Write an alternate version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s2.
 */
	
#include <stdio.h>

#define false 0
#define true 1

void squeeze(char s[], char t[]);

int main() 
{
	char input[] = "abc";
	squeeze(input, "ab");
	printf("squeeze(\"abc\", \"ab\") = %s\n", input);

	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	squeeze(alphabet, "aeiouy");
	printf("squeeze(\"abcdefghijklmnopqrstuvwxyz\", \"aeiouy\") = %s\n", alphabet);
}

/*
 * Squeezes characters existing in t from s.
 * For example: 
 *	char input[] = "abc";
 *	squeeze(input, "ab");
 * input = "c"
 */
void squeeze(char s[], char t[])
{
	int j = 0;
	for (int i = 0; s[i]; ++i) {
		// Introducing this variable since we can't use break yet
		int found = false; 
		for (int k = 0; t[k] && !found; ++k) {
			if (s[i] == t[k])
				found = true;
		}
		if (!found)
			s[j++] = s[i];
	}
	s[j] = '\0';
}
