/*
 * Exercise 4-2
 * Extend atof to handle scientific notation of the form 123.45-e6
 * where a floating-point number may be followed by e or E
 * and an optionally signed exponent.
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
	double result = atof("3.2e-3");
	printf("%f\n", result);

	return 0;
}

double atof(char s[])
{

	double val, power = 1.0;
	int i, sign, expsign, expval = 0;

	for (i = 0; isspace(s[i]); ++i)
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + s[i] - '0';
	if (s[i] == '.')
	{
		++i;
		for (; isdigit(s[i]); ++i)
		{
			val = 10.0 * val + s[i] - '0';
			power *= 10;
		}
	}
	if (s[i] == 'e' || s[i] == 'E')
	{
		++i;
		expsign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			++i;
		for (; isdigit(s[i]); ++i)
		{
			expval = 10 * expval + s[i] - '0';
		}
		return (sign * val / power) * pow(10, expval * expsign);
	}
	else
		return sign * val / power;
}