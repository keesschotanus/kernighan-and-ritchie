/*
 * Exercise 2-8
 * Write a function rightrot(x, n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 * 
 * Here is what happens when you rotate right 01011011 (decimal 91)
 * 10101101 11010110 01101011 10110101 11011010 01101101
 * So the bits rotated right appear in the same order on the left.
 * 
 * (x >> n) | (x << (32 - n)) should do the trick.
 * It shifts x, n positions to the right and ors it with
 * x shifted to the left.
 * The downside of my solution is that it expects an int to be 32 bits.
 * Using sizeof(int) * 8 instead of 32 would be more portable.
 */
	
#include <stdio.h>

unsigned int rightrot(unsigned x, unsigned n);

int main() 
{
	printf("rightrot(91, 3)=%u\n", rightrot(91, 3));
}

unsigned int rightrot(unsigned x, unsigned n) {
    return (x >> n) | (x << (32 - n));
}
