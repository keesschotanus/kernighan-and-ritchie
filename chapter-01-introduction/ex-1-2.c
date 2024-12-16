/*
 * Exercise 1-2
 * Experiment to find out what happens when printf's argument string contains \c,
 * where c is none of n,t,b,",\
 */

#include <stdio.h>
main()
{
	printf("hello, world\!");
}

// Using a character that does not need to be escaped, simply prints the character.
// The compiler gives this warning: unknown escape sequence: '\!'
