/*
 * Exercise 2-9
 * In a two's compliment number system, x &= (x - 1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of bitcount.
 *
 * Let's see what happens when the bitpattern is 1001 (9 decimal)
 * x &= (x - 1) becomes
 *
 * 1001
 * 1000 &
 * ----
 * 1000
 *
 * In the next step we compute
 * 1000
 * 0111 &
 * ----
 * 0000
 *
 * So in two steps we reach zero.
 * 
 * By subtracting one from x, the rightmost one bit becomes 0.
 * All zero bits after the rightmost 1 bit become 1.
 */
	
#include <stdio.h>

int bitcount(unsigned x);

int main() 
{
	printf("bitcount(~0)=%d\n", bitcount(~0));
	printf("bitcount(9)=%d\n", bitcount(9));
}

int bitcount(unsigned x) {
    int bits = 0;
    for (; x; x &= (x - 1), ++bits);

    return bits;
}
