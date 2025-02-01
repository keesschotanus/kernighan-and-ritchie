/*
 * Exercise 5-13
 * Write the program tail, which prints the last n lines of its input.
 * By default, n is 10, but it can be changed by an optional argument,
 * so that `tail -n` prints the last n lines.
 * The program should behave rationally no matter how unreasonable the input
 * or the value of n.
 * Write the program so it makes the best use of available storage;
 * lines should be stored as in the sorting program of Section 5.6;
 * not in a two-dimensional array of fixed size.
 * 
 * Since we don't know how many line of input are present we only store n
 * lines of input.
 * Room for lines will be allocated using malloc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10

int main(int argc, char **argv)
{
	int get_n(int argc, char **argv);
	int n = get_n(argc, argv);

	// Use an array of line pointers
	char *n_lines[n];
	// And array with the length of each line.
	// Structs can't be used as they are in the next chapter.
	size_t n_line_sizes[n];
	for (int i = 0; i < n; ++i)
		n_lines[i] = NULL, n_line_sizes[i] = 0;

	char *line = NULL;
	size_t line_length = 0, mod_line_number = 0, abs_line_number = 0;

	while (getline(&line, &line_length, stdin) > 0) {
		// Store the line
		if (n_line_sizes[mod_line_number] == 0) {
			// allocate memory for new line
			n_line_sizes[mod_line_number] = line_length;
			n_lines[mod_line_number] = malloc(line_length + 1);
		} else if (line_length > n_line_sizes[mod_line_number]) {
			// reallocate room for line longer than current line length
			free(n_lines[mod_line_number]);
			n_lines[mod_line_number] = malloc(line_length + 1);
		}
		strcpy(n_lines[mod_line_number], line);
		mod_line_number = ++mod_line_number % n;
		++abs_line_number;
	}

	// When the input lines equal or exceed n, we print n lines, starting from
	// mod_line_number. With fewer input we start from 0
	int current_line = abs_line_number < n ? 0 : mod_line_number;
	int count = abs_line_number < n ? abs_line_number : n;
	for (; count > 0; ++current_line, --count) {
		printf("%s", n_lines[current_line % n]);
		free(line);
	}

	return 0;
}

/*
 * Gets the n (the number of lines to show) from command line arguments.
*/
int get_n(int argc, char **argv)
{
	int max_lines = MAX_LINES;

	if (argc == 2 && **++argv == '-')
		max_lines = atoi(++*argv);

	if (max_lines < 1)
		max_lines = MAX_LINES;

	return max_lines;
}
