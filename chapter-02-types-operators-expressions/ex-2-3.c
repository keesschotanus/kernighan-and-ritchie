/*
 * Exercise 2-3
 * Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9 ,a through f, and A through F.
 */
	
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int htoi(char s[]);

int main() 
{
	printf("%d\n", htoi("ab"));
	printf("%d\n", htoi("0xab"));
	printf("%d\n", htoi("0XaB"));
	printf("%d\n", htoi("0XaB$"));
	printf("%d\n", htoi("x"));
	printf("%d\n", htoi(""));
	printf("%d\n", htoi("$a"));
}

int htoi(char s[])
{
	int i = 0, n = 0;

	// Skip optional 0x or 0X
	if (strlen(s) >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;

	for (; s[i] && isdigit(s[i]) || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F') ; ++i) {
		if (isdigit(s[i]))
			n = 16 * n + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')  
			n = 16 * n + (s[i] - 'A' + 10);
		else if (s[i] >= 'a' && s[i] <= 'f')  
			n = 16 * n + (s[i] - 'a' + 10);
	}

	return n;
}
