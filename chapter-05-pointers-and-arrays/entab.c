/*
 * Exercise 5-11
 * Modify the program entab (written as exercises in Chapter 1)
 * to accept a list of tab stops as arguments.
 * Use the default tab settings if there are no arguments.
 * 
 * Not sure if the code is correct but I think my approach is.
 * Here is what happens in the entab function.
 * If the char is a space, we simply count it.
 * If it is not a space, we see if there are any previous spaces.
 * If so, we process them.
 * If the char is a tab, we move to the next tab stop,
 * else we just print the char.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 8
#define MAX_LINE_LENGTH 1000

int tabstops[MAX_LINE_LENGTH];

int main(int argc, char **argv)
{
	void set_tab_stops(int argc, char **argv, int tabstops[]);
	void entab(char *line);
	int get_line(char *, int len);

	set_tab_stops(argc, argv, tabstops);

	int len;
	char line[MAX_LINE_LENGTH] = "Hello World!";

	// while ((len = get_line(line, MAX_LINE_LENGTH) > 0)) {
	// 	entab(line);
	// }
	entab(line);
	return 0;
}

void set_tab_stops(int argc, char **argv, int tabstops[])
{
	if (argc == 1) {
		// No tab stops were supplied, use the default TAB_SIZE
		for (int i = 0; i < MAX_LINE_LENGTH; i += TAB_SIZE)
			tabstops[i] = 1;
	} else {
		while (--argc > 0) {
			int tabstop = atoi(*++argv);
			if (tabstop > 0 && tabstop < MAX_LINE_LENGTH)
				tabstops[tabstop] = 1;
		}
	}
}

void entab(char *line)
{
	int process_spaces(int pos, int spaces);
	int process_tab(int pos);

	int c;
	int spaces = 0;
	int pos = 1;

	while (c = *line++) {
		if (c == ' ')
			++spaces;
		else {
			if (spaces) {
				process_spaces(pos, spaces);
				spaces = 0;
			}

			if (c == '\t')
				process_tab(pos);
			else {
				putchar(c);
				++pos;
			}
		}
	}
}

int process_spaces(int pos, int spaces)
{
	int process_tab(int pos);

	int remainingSpaces = 0;
	for (int i = 1; i <= spaces; ++i, ++remainingSpaces) {
		if (tabstops[pos + i]) {
			// We have enough spaces to reach a tab stop
			pos = process_tab(pos + i);
			remainingSpaces = 0;
		}
	}

	for (; remainingSpaces; --remainingSpaces, ++pos) {
		putchar(' ');
	}
		
	return pos;
}

int process_tab(int pos)
{
	putchar('\t');
	// Move to next tabstop
	while (!tabstops[++pos]);
	return pos;
}

/* get_line: read a line into s, return length */
/* Using getline conflicted with same function from the library */
int get_line(char *s, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		*s++ = c;
	if (c == '\n') {
		*s++ = c;
		++i;
	}
	*s = '\0';

	return i;
}
