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

int main(int argc, char *argv[])
{
	int numeric = argc > 1 && strcmp(argv[1], "-n") == 0 ? 1 : 0;
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

int stringcmp(const void *left, const void *right)
{
	// From the man page: The actual arguments to this function are
	// "pointers to pointers to char", but strcmp() arguments are
	// "pointers to char", hence the following cast plus dereference
    return strcmp(*(const char **)left, *(const char **)right);
}

/* Compare two strings numerically */
int numcmp(const void *left, const void *right)
{
	double vleft = atof(*(const char **)left);
	double vright = atof(*(const char **)right);

	if (vleft < vright)
		return -1;
	else if (vleft > vright)
		return 1;
	return 0;
}
