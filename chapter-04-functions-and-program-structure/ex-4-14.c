/*
 * Exercise 4-14
 * Define a macro swap(t,x,y) that interchanges two arguments of type t.
 * (block structure will help.)
 */

#include <stdio.h>
#include <string.h>

#define swap(type,x,y) { type temp = x; x = y; y = temp; }

int main()
{
    short x = 1;
    short y = 2;
    swap(short,x,y);

    printf("x=%d, y=%d\n", x, y);
}
