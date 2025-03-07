/*
 * Exercise 2-10
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 */
	
#include <stdio.h>

int lower(int c);

int main() 
{
	printf("lower('a')=%c\n", lower('a'));
	printf("lower('A')=%c\n", lower('A'));
}

int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
