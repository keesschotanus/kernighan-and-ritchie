/*
 * Exercise 2-6
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p, set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 * 
 * Let's start with the simpler bitpattern for y.
 * For y we need to keep the n rightmost bits and discard all others.
 * We can do that using y & bitpattern, where bitpattern is: ~(~0 << n).
 * ~0 << n, creates a bitpattern consisting of all ones, except for the last n
 * bits, that contain zeroes. Flipping this pattern gives us the desired pattern.
 * So: (y & ~(~0 << n)) gives us the n rightmost bits only.
 * We can align the bits to the proper position by shifting them left, lke this:
 * (y & ~(~0 << n)) << p+1-n
 * 
 * We need to do something similar for x where we need to keep all bits, except
 * for the n bits from position p.
 * This should do the trick:
 * ~(~(~0 << n) << p+1-n)
 * ~0 creates a pattern of ones, shift left n times sets n rightmost bits to 0.
 * Flipping the bits results in 0 zeroes, except for the last n bits which are 1.
 * We now shift the bits into position. So far the code looks like this:
 * ~(~0 << n) << p+1-n 
 * We now have zeroes on all positions except for n bits starting at p.
 * We flip the result again so we can `and` the result with x.
 * The result is ored with our previous expression to become:
 * x & ~(~(~0 << n) << p+1-n) | (y & ~(~0 << n)) << p+1-n;
 */
	
#include <stdio.h>

int setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main() 
{
	// 23 = 00010111 7 = 00000111
	printf("%d\n", setbits(23, 5, 3, 7)); // 63 
	printf("%d\n", setbits(23, 5, 3, 0)); //  7

}

int setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
 	return (x & ~(~((unsigned)~0 << n) << (p+1-n))) | ((y & ~((unsigned)~0 << n)) << (p+1-n));
}
