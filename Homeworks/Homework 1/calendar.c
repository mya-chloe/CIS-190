/*
Nathan Burdzel
CIS 190 10/4/18
Homework 1 Problem 1*/

/*Preprocessor Directives*/
#include <stdio.h>

int main(void){

	/*Declare variables*/
	int user_year, day_of_week, month, day, days_in_month = -1;
	const int DAYS_IN_JANUARY = 31, DAYS_IN_MARCH = 31, DAYS_IN_MAY = 31, DAYS_IN_JULY = 31, DAYS_IN_AUGUST = 31, DAYS_IN_OCTOBER = 31, DAYS_IN_DECEMBER = 31;
	const int DAYS_IN_APRIL = 30, DAYS_IN_JUNE = 30, DAYS_IN_SEPTEMBER = 30, DAYS_IN_NOVEMBER = 30;
	const int DAYS_IN_FEBRUARY = 28;

	/*Print a welcome message then get a year from the user verifying that it is valid(Able to be stored in an int and is after the gregorian calendar was adopted)*/
	printf("Welcome to my Gregorian calendar generator!\nPlease enter the year of the calendar you want under the Gregorian calendar:\n");
	do{
		scanf("%d", &user_year);
		/*Print statements for if the chosen year is invalid*/
		if(user_year > 32767)
			printf("Chosen year is too large, please choose a smaller year:\n");
		else if(user_year < 1582)
			printf("Chosen year is too small\nPlease choose a year after the Gregorian calendar was adopted(1582):\n");
	}while(user_year < 1582 || user_year > 32767);

	/*Calculate the day of the week for January 1st, explanation of the calculation I used found at http://mathforum.org/library/drmath/view/55837.html (Credit goes to Dr. Bill, I just used his formula and edited it so that Sunday would result in a 0 and saturday a 6)*/
	day_of_week = (1 + 2 * 13 + (3 * (13 + 1) / 5) + (user_year - 1) + (user_year - 1) / 4 - (user_year - 1) / 100 + (user_year - 1) / 400 + 1) % 7;

	/*Print out a confirmation message*/
	printf("Here is your calendar for %d", user_year);

	/*Loop through each month in the year*/
	for(month = 1; month < 13; month++){
		/*Print out a month header and set days_in_month to the defined constant for the number of days in that month, February will be 28 or 29 depending on whether or not it's a leap year*/
		switch(month){
			case 1:
				printf("\n\nJanuary\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_JANUARY;
				break;
			case 2:
				printf("\n\nFebruary\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_FEBRUARY + (!(user_year % 4) && (user_year % 100 || !(user_year % 400)));
				break;
			case 3:
				printf("\n\nMarch\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_MARCH;
				break;
			case 4:
				printf("\n\nApril\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_APRIL;
				break;
			case 5:
				printf("\n\nMay\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_MAY;
				break;
			case 6:
				printf("\n\nJune\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_JUNE;
				break;
			case 7:
				printf("\n\nJuly\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_JULY;
				break;
			case 8:
				printf("\n\nAugust\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_AUGUST;
				break;
			case 9:
				printf("\n\nSeptember\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_SEPTEMBER;
				break;
			case 10:
				printf("\n\nOctober\t\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_OCTOBER;
				break;
			case 11:
				printf("\n\nNovember\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_NOVEMBER;
				break;
			case 12:
				printf("\n\nDecember\t\t\t\t%10d\nSu\tMo\tTu\tWe\tTh\tFr\tSa\t\n", user_year);
				days_in_month = DAYS_IN_DECEMBER;
				break;
		}

		/*Prints blank spaces while day < 1, and then all of the days of the month with properly positioned line breaks*/
		for(day = 1 - day_of_week; day <= days_in_month; day++)
			day < 1 ? printf("\t") : (printf("%2d%c", day, ((day_of_week + day) % 7 || day == days_in_month) ? '\t' : '\n'));

		/*Set day_of_week to be the representation of the first day of the next month*/
		day_of_week = (day_of_week + day - 1) % 7;
	}

	/*Print a finished message*/
	printf("\n\nHere's your calendar!\nGoodbye!");

	return(0);
}
