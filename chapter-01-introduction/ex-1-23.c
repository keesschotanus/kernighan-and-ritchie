/*
 * Exercise 1-23
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 *
 * The problem with removing comments is that you read a slash character and
 * don't know yet if you have to output it or not.
 * When followed by another slash or asterisk, you found a comment for which
 * you don't want to output these characters.
 * This is why I keep track of the previous character and of the fact if the
 * previous character needs to be part of the ouput.
 * 
 * This code will properly handle single-line comments in multi-line comments.
 * It should also handle comments within strings.
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

#define true 1
#define false 0

int get_line(char line[], int maxline);

int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	int in_single_comment = false;
	int in_multi_comment = false;
	int in_string = false;

	char previous_char = '\0';
	int print_previous = false;

	while ((len = get_line(line, MAXLINE)) > 0) {
		for (int i = 0; i < len; ++i) {
			if (in_single_comment) {
				if (line[i] == '\n')
					in_single_comment = false;
			} else if (in_multi_comment) {
				if (previous_char == '*' && line[i] == '/') {
					in_multi_comment = false;
					print_previous = false;
				}
			} else if (in_string) {
				if (previous_char != '\\' && line[i] == '"')
					in_string = false;
				putchar(line[i]);
			} else {
				if (previous_char == '/' && line[i] == '/')
					in_single_comment = true;
				else if (previous_char == '/' && line[i] == '*')
					in_multi_comment = true;
				else if (line[i] == '"') {
					in_string = true;
					putchar(line[i]);
				}
				else {
					if (print_previous && previous_char == '/') {
						putchar(previous_char);
					}
					if (line[i] != '/')
						putchar(line[i]);
				}
				print_previous = true;
			}
			previous_char = line[i];
		}
	}

	return 0;
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
