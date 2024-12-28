/*
 * Exercise 4-1
 * Write the function strrindex(s,t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 * 
 * I went for looping over s and t from right to left.
 * Alternatively you can reverse the string, find from the left and correct
 * for the fact that the string was reversed to begin with.
 */

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main()
{
	int result = strrindex("abcdcabcd", "bc");
	printf("%d\n", result);
	return result;
}

int strrindex(char s[], char t[])
{

	int length_of_t = strlen(t);
	for (int i = strlen(s) - 1; i >= 0; --i) {
		int j; // Used to loop over s[] from position i and back
		int k; // Used to loop over t[] from back to front
		for (j = i, k = length_of_t - 1; j >= 0 && k >= 0 && s[j] == t[k]; --j, --k)
			;
		// k is -1 when a match has been found
		if (k < 0)
			return j + 1; // Position we found t 
	}

	return -1;
}