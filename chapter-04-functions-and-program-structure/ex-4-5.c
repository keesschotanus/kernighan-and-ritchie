/*
 * Exercise 4-5
 * Add access to library functions like sin, exp, and pow.
 * See <math.h> in Appendix B, section 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP   100     // Max operand size
#define NUMBER  '0'     // Signal that number was found
#define FUNCTION '1'    // Signal that function was found

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void clear_stack(void);
void function(char []);

int main()
{
    char type;
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
                push(fmod(pop(), op2));
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
        case 'c': // clear stack
            clear_stack();
            break;
        case FUNCTION:
            function(s);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

void function(char f[]) 
{
    if (strcmp("exp", f) == 0)
        push(exp(pop()));
    else if (strcmp("sin", f) == 0)
        push(sin(pop()));
    else if (strcmp("cos", f) == 0)
        push(cos(pop()));
    else if (strcmp("pow", f) == 0) {
        double op2 = pop();
        double op1 = pop();
        push(pow(op1, op2));
    }
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

void clear_stack(void)
{
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i = 0, c;

    // skip whitespace
	while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    // Currently using single letters for commands like 'd' for duplicate
    if (isalpha(c) && c != '.' && c != '-') {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
		ungetch(c);
	    return strlen(s) == 1 ? s[0] : FUNCTION;
	}

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