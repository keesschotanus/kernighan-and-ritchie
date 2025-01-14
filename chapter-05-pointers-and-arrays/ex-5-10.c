/*
 * Exercise 5-10
 * Write the program expr, which evaluates a reverse Polish expression
 * from the command line, where each operator or operand is a separate
 * argument.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void push(double);
double pop(void);

int main(int argc, const char *argv[])
{
	double op2;
	while (--argc > 0) {
		++argv;
		// process (negative) numbers
		if (isdigit(**argv) || (**argv == '-' && strlen(*argv) > 1)) {
			push(atof(*argv));
		} else {
			switch(**argv) {
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor");
				break;
			default:
				printf("Illegal operator or operand: %s\n", *argv);
			}
		}
	}

	printf("Result: %g\n", pop());
}

#define MAXVAL 100 // Max stack size

int sp = 0;			// Next free stack position
double val[MAXVAL]; // value stack

void push(double value)
{
	if (sp < MAXVAL)
		val[sp++] = value;
	else
		printf("error: stack full, can't push %g\n", value);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}
