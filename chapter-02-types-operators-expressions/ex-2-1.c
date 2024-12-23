#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() 
{
	printf("          char [%d..%d]\n", CHAR_MIN, CHAR_MAX);
	printf("   signed char [%d..%d]\n", SCHAR_MIN, SCHAR_MAX);
	printf(" unsigned char [%d..%d]\n", 0, UCHAR_MAX);

	printf("  signed short [%d..%d]\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short [%d..%d]\n", 0, USHRT_MAX);

	printf("    signed int [%d..%d]\n", INT_MIN, INT_MAX);
	printf("  unsigned int [%u..%u]\n", 0, UINT_MAX);

	printf("   signed long [%ld..%ld]\n", LONG_MIN, LONG_MAX);
	printf(" unsigned long [%d..%lu]\n", 0, ULONG_MAX);

	printf("         float [%.*g..%.*g\n", FLT_DECIMAL_DIG, -FLT_MAX, FLT_DECIMAL_DIG, FLT_MAX);
	printf("        double [%.*g..%.*g\n", DBL_DECIMAL_DIG, -DBL_MAX, DBL_DECIMAL_DIG, DBL_MAX);
	printf("   long double [%.*Lg..%.*Lg\n", LDBL_DECIMAL_DIG, -LDBL_MAX, LDBL_DECIMAL_DIG, LDBL_MAX);
}
