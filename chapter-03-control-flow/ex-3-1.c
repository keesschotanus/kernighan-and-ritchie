/*
 * Exercise 3-1
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside).
 * Write a version with only one test inside the loop and measure the
 * difference in run-time.
 * 
 * Running with binsearch:  user 0m21,913s
 * Running with binsearch2: user 0m38,463s
 */

#include <stdio.h>


int binsearch(int x, int v[], int n);
int binsearchf(int x, int v[], int n);

int main()
{
    int a[1000];
    for (int i = 0 ; i < 1000; ++i)
        a[i] = i;

    long result = 0;
    for (int i = 0; i <= 1000000000; ++i) {
        int location = binsearch(i % 999, a, 1000);
        result += location;
        if (location != i % 999) {
            printf("i=%d, location=%d\n", i, location);
            return 1;
        }
    }        

    printf("Result=%ld", result);

}

int binsearch(int x, int v[], int n)
{
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return - 1;
}

int binsearchf(int x, int v[], int n)
{
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }

    mid = (low + high) / 2;
    return v[mid] == x ? mid : -1;
}