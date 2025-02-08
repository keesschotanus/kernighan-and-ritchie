/*
 * Exercise 5-14, 5-15 and 5-16.
 * 5-14 Modify the sort program to handle a -r flag to reverse the sort order.
 * Make sure it works with -n.
 * 5-15 Add the option -f to fold upper and lower case together.
 * That is, sort case insensitive.
 * 5-16 Add the -d ("directory order") option, which makes comparison only on
 * letters, numbers and blanks.
 * 
 * At this stage I tried to use the built in versions of qsort and readlines.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int numcmp(const void *left, const void *right);
int stringcmp(const void *left, const void *right);
void process_arguments(int argc, char *argv[]);

int numeric = 0;
int reverse = 0;
int fold = 0;
int directory = 0;

int main(int argc, char *argv[])
{
	process_arguments(argc, argv);
	size_t nlines;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort(lineptr, nlines, sizeof(char *), numeric ? numcmp : stringcmp);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("Input too big to sort\n");
		return 1;
	}
}

void process_arguments(int argc, char *argv[])
{
	while (--argc) {
		++argv;
		if (**argv == '-') {
			int c;
			while (c = *(++*argv)) {
				switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				case 'f':
					fold = 1;
					break;
				case 'd':
					directory = 1;
					break;
				default:
					fprintf(stderr, "Ignoring unsupported option: -%c\n", c);
					break;
				}
			}
		}
	}	
}

int readlines(char *lineptr[], int maxlines)
{
	char *line = NULL;
	ssize_t length = 0, actual_length;

	int nlines = 0;
	while (nlines < maxlines && (actual_length = getline(&line, &length, stdin)) > 0)
	{
		lineptr[nlines] = malloc(actual_length); // We won't store '\n'
		line[actual_length - 1] = '\0';
		strcpy(lineptr[nlines], line);
		++nlines;
	}
	free(line);

	return nlines < maxlines ? nlines : -1;
}

void writelines(char *lineptr[], int nlines)
{
	for (int i = 0; nlines; --nlines, ++i) {
		printf("%s\n", lineptr[i]);
		free(lineptr[i]);
	}
}

/* Compare two strings */
int stringcmp(const void *left, const void *right)
{
	// From the man page: The actual arguments to this function are
	// "pointers to pointers to char", but strcmp() arguments are
	// "pointers to char", hence the following cast plus dereference
	const char *pleft = *(const char **)left;
	const char *pright = *(const char **)right;

	if (directory) {
		// find first space, or alphanumeric char
		while (*pleft && !isalnum(*pleft) && !isblank(*pleft))
			++pleft;
		while (*pright && !isalnum(*pright) && !isblank(*pright))
			++pright;
	}

	char cleft, cright;
	while (*pleft && *pright) {
		cleft = fold ? toupper(*pleft) : *pleft;
		cright = fold ? toupper(*pright) : *pright;
		if (cleft != cright)
			break;
		pleft++, pright++;

		if (directory) {
			// find next space, or alphanumeric char
			while (*pleft && !isalnum(*pleft) && !isblank(*pleft))
				++pleft;
			while (*pright && !isalnum(*pright) && !isblank(*pright))
				++pright;
		}
	}

	return reverse ? cright - cleft : cleft - cright;
}

/* Compare two strings numerically */
int numcmp(const void *left, const void *right)
{
	double vleft = atof(*(const char **)left);
	double vright = atof(*(const char **)right);

	return reverse ? vright - vleft : vleft - vright;
}

/*
 * Compare two strings directory style, that is only taking
 * letters, digits and blanks into account.
 */
int dircmp(const void *left, const void *right)
{
	// char *leftchar = *(const char **)left;
	// char *rightchar = *(const char **)right;

	// while (*leftchar && *rightchar) {
	// 	while(*leftchar && !isalnum(*leftchar) && !isblank(*leftchar))
	// 		++leftchar; // find next char we must compare
	// 	while(*rightchar && !isalnum(*rightchar) && !isblank(*rightchar))
	// 		++rightchar; // find next char we must compare
	// 	if (*leftchar == '\0' && *rightchar == '\0')
	// 		return 0;
	// 	if (*leftchar == '\0')
	// 		return -1;
	// 	if (*rightchar == '\0')
	// 		return 1;
	// 	if (leftchar != rightchar)
	// 		return leftchar - rightchar;
			
	// 	++leftchar;
	// 	++rightchar;
	// }

	return 1;
}
