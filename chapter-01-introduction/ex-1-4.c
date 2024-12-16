/*
 * Exercise 1-4
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for celsius = 0, 20, ..., 300;
 */
main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature scale */ 
	upper = 300;	/* upper limit */
	step = 20;		/* step size */ 
	
	printf("%3s %6s\n", "C", "F");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

// With celsius from 0, 20, ..., 300 the fahrenheit temperature
// is always an int, but I'm still using float types,
// in case someone changes lower, upper or step.