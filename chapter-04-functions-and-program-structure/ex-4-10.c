/*
 * Exercise 4-10
 * An alternative organization uses getline to read an entire input line;
 * this makes getch and ungetch unnecessary.
 * Revise the calculator to use this approach.
 * 
 * I took some shortcuts here since I had a peek at the next exercise where
 * we have to use the getop() function again and do not use the getline().
 * My implementation does no support negative numbers nor functions anymore.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 1000 // Max line length
#define MAXOP 100	 // Max operand size
#define NUMBER '0'	 // Signal that number was found
#define FUNCTION '1' // Signal that function was found
#define STR_VAR '2'	 // Signal to store a variable
#define RCL_VAR '3'	 // Signal to recall a variable

int getop(char[], int pos);
void push(double);
double pop(void);
double peek(void);
void clear_stack(void);
int get_line(char line[], int maxline);
void get_var_name(char s[], char line[], int pos);
int get_number(char s[], char line[], int pos);

int main()
{
	char line[MAXLINE] = {0};
	int len;
	char type;
	double op1, op2;
	char s[MAXOP];
	double var[26];

	while ((len = get_line(line, MAXLINE)) > 0)
	{
		int i = 0, c;
		do
		{
			// Skip whitespace
			while (line[i] == ' ' || line[i] == '\t')
				++i;
			switch (line[i])
			{
			case '#':
				get_var_name(s, line, i + 1);
				push(var[tolower(s[0]) - 'a']);
				break;
			case '@':
				get_var_name(s, line, i + 1);
				var[tolower(s[0] - 'a')] = pop();
				break;
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
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			case 'p': // print
				var['p' - 'a'] = peek();
				printf("\t%.8g\n", peek());
				break;
			case 's': // swap
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case 'd': // duplicate
				push(peek());
				break;
			case 'c': // clear stack
				clear_stack();
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				int oplen = get_number(s, line, i);
				push(atof(s));
				i += oplen - 1;
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
			}
			++i;
		} while (i < len - 1);

		printf("\t%.8g\n", pop());

	}

	return 0;
}

void get_var_name(char s[], char line[], int pos)
{
	s[0] = line[pos];
	s[1] = '\0';
}

int get_number(char s[], char line[], int pos)
{
	int i;
	for (i = 0; isdigit(line[pos + i]); ++i)
	{
		s[i] = line[pos + i];
	}

	if (line[pos + i] == '.')
	{ // Collect fraction part
		for (; isdigit(line[pos + i]); ++i)
		{
			s[i] = line[pos + i];
		}
	}

	s[i] = '\0';
	return i;
}

#define MAXVAL 100 // Max stack size

	int sp = 0;			// Next free stack position
	double val[MAXVAL]; // value stack

	void push(double f)
	{
		if (sp < MAXVAL)
			val[sp++] = f;
		else
			printf("error: stack full, can't push %g\n", f);
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

	double peek(void)
	{
		if (sp > 0)
			return val[sp - 1];
		else
		{
			printf("error: stack empty\n");
			return 0.0;
		}
	}

	void clear_stack(void)
	{
		sp = 0;
	}

	/* get_line: read a line into s, return length */
	/* Using getline conflicted with same function from the library */
	int get_line(char s[], int lim)
	{
		int c, i;
		for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
			s[i] = c;
		if (c == '\n')
			s[i++] = c;
		s[i] = '\0';

		return i;
	}
