/*
 * Exercise 5-8
 * There is no error checking in day_of_year or month_day.
 * Remedy this defect.
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
	int yearday = day_of_year(1961, 9, 29);
	printf("y=1961 m=9 d=29 => day of year=%d\n", yearday);
	int month, day;
	month_day(1961, yearday, &month, &day);
	printf("yearday=%d => month=%d, day=%d\n", yearday, month, day);
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* Returns day of year from month and day */
int day_of_year(int year, int month, int day)
{
	int leap = year % 4 == 0 && year % 100 || year % 400 == 0;

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
		return 0;

	for (int i = 1; i < month; ++i)
		day += daytab[leap][i];
	return day;
}

/* Sets month and day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i;
	int leap = year % 4 == 0 && year % 100 || year % 400 == 0;
	for (i = 1; i < 13 && yearday > daytab[leap][i]; ++i)
		yearday -= daytab[leap][i];

	if (i > 12) {
		*pmonth = 0;
		*pday = 0;
	} else {
		*pmonth = i;
		*pday = yearday;
	}

}


