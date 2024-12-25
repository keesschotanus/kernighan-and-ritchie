/*
 * Exercise 2-7
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted, leaving the other bits unchanged.
 * 
 * Inverting bits sounds like we need the ~ operator, but we actually need ^.
 * Here is the idea:
 * Create a bitpattern of zeroes except for the n rightmost bits that are ones.
 * Shift that bitpattern into place (that is at position p).
 * Now perform x ^ bitpattern.
 * 
 * For example: invert(180, 4, 3)
 * 180 = binary 10110100
 * The bitpattern is created using (~(~0U << n))
 * This creates the pattern: 00000111.
 * Now shift to the left p - n + 1 times gives.
 * 00011100.
 * 
 * 00011100 
 * 10110100 ^
 * --------
 * 10101000 = 168
 * 
 * 
 * I came up with this solution:
 * return ((x & ~(~(~0U << n) << (p+1-n)))) | ((~((x >> (p - n + 1)) & (~(~0U << n))) & (~(~0U << n))) << (p - n + 1));
 * Where Ollama reduced it to: return x ^ (((1 << n) - 1) << (p - n + 1));
 */
	
#include <stdio.h>

unsigned int invert(unsigned x, unsigned p, unsigned n);

int main() 
{
	//       76543210
	// 180 = 10110100
	printf("%d\n", invert(180, 4, 3));
}

unsigned int invert(unsigned x, unsigned p, unsigned n) {
    return x ^ ((~(~0U << n)) << (p - n + 1));
}
