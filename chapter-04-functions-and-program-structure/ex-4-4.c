/*
 * Exercise 4-4
 * Add commands to print the top element of the stack without popping,
 * to duplicate it, and to swap the top two elements.
 * 
 * The new commands are 'p' for print, 'd' for duplicate and 's' for swap.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP   100 // Max operand size
#define NUMBER  '0' // Signal that number was found

int getop(char []);
void push(double);
double pop(void);
double peek(void);

int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: modulo of zero");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case 'p': // print
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
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

#define MAXVAL  100 // Max stack size

int sp = 0;         // Next free stack position
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
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double peek(void)
{
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    if (!isdigit(c) && c != '.' && c != '-') {
		    s[1] = '\0';
	        return c; // not a number
	}

	if (c == '-') {
		if (!isdigit(c = getch())) {
			// Assume '-' followed by non-digit is minus operator
			// `2 3 -` works since - i followed by non-digit ('\n')
			s[1] = '\0';
			ungetch(c);
			return s[0];
		} else
			ungetch(c);
	}

    i = 0;
    while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')   // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

/* Get a (possibly pushed back) character */
int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}