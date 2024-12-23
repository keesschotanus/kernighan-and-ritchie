/*
 * Exercise 1-1
 * Run the "hello, world" program on your system.
 * Experiment with leaving out parts of the program,
 * to see what error messages you get.
 */

#include <stdio.h>

main() {
	printf("hello, world\n");
}

// When leaving out: #include <stdio.h>
// warning: implicit declaration of function ‘printf’
// note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
//
// When leaving out: main
// undefined reference to `main'
