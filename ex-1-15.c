/*
 * Exercise 1-15
 * Rewrite the temperature conversion program of section 1.2
 * to use a function for conversion.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table */
float fahrenheit_to_celsius(int fahrenheit);

int main()
{
	float fahrenheit, celsius;
	int lower, upper, step;

	lower = LOWER;
	upper = UPPER;
	step = STEP;
	
	printf("%3s %6s\n", "F", "C");
	fahrenheit = lower;
	while (fahrenheit <= upper) {
		celsius = fahrenheit_to_celsius(fahrenheit);
		printf("%3.0f %6.1f\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + step;
	}

	return 0;
}

float fahrenheit_to_celsius(int fahrenheit)
{
	return (5.0/9.0) * (fahrenheit - 32.0);
}