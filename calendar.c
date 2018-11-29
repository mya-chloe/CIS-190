/*
Nathan Burdzel
CIS 190 10/4/18
Homework 1 Problem 1*/

#define DAYS_IN_JANUARY 31
#define DAYS_IN_FEBRUARY 28
#define DAYS_IN_MARCH 31
#define DAYS_IN_APRIL 30
#define DAYS_IN_MAY 31
#define DAYS_IN_JUNE 30
#define DAYS_IN_JULY 31
#define DAYS_IN_AUGUST 31
#define DAYS_IN_SEPTEMBER 30
#define DAYS_IN_OCTOBER 31
#define DAYS_IN_NOVEMBER 30
#define DAYS_IN_DECEMBER 31
#define OUTPUT_FILE_LOCATION "OUTPUT.txt"

#include <stdio.h>

int main(void){
	/*Declare variables*/
	int user_year = -1;
	int day_of_week = 0;
	int i = 0;	
	int starting_day_of_week = 0;
	/*Print a welcome statement*/

	/*Get a year from the user*/	
	printf("Please enter the year that you would like the calendar of:\n");
	do{	
		scanf("%d", &user_year);
		/*Print statements if the chosen year is invalid*/
		if(user_year > 32767)
			printf("Chosen year is too large, please choose a smaller year.\n");
		else if(user_year < 1)
			printf("Year is not valid, please choose an integer year in the common era.\n");
	}while(user_year < 1 || user_year > 32767);
	
	/*Open the print file*/


	/*Calculate the day of the week for January 1st*/
	starting_day_of_week = (1 + 2 * 13 + (3 * (13 + 1) / 5 + user_year - 1) + (user_year - 1) / 4 - (user_year - 1) / 100 + (user_year - 1) / 400 + 2 + 1) % 7;
	fprintf(output, "%d", starting_day_of_week);

	/*Print the calendar*/
	fprintf(output, "Here is your calendar for %d", user_year);
	
	/*Print the month of January*/

	/*Print the month header*/
	fprintf(output, "\n\n\nJanuary\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_JANUARY; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_JANUARY - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of Febrary*/

	/*Print the month header*/
	fprintf(output, "\n\n\nFebruary\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_FEBRUARY; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_FEBRUARY - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}
	
	/*Print out the 29th if it is a leap year*/
	if(user_year % 4 && !(user_year % 100) && user_year % 400){
		fprintf(output, "29\n");	
		day_of_week = ++day_of_week % 7;
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of March*/

	/*Print the month header*/
	fprintf(output, "\n\n\nMarch\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_MARCH; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_MARCH - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of April*/

	/*Print the month header*/
	fprintf(output, "\n\n\nJApril\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_APRIL; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_APRIL - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of May*/

	/*Print the month header*/
	fprintf(output, "\n\n\nMay\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_MAY; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_MAY - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of June*/

	/*Print the month header*/
	fprintf(output, "\n\n\nJune\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_JUNE; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_JUNE - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of July*/

	/*Print the month header*/
	fprintf(output, "\n\n\nJuly\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}

	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_JULY; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_JULY - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of August*/

	/*Print the month header*/
	fprintf(output, "\n\n\nAugust\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}

	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_AUGUST; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_AUGUST - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of September*/

	/*Print the month header*/
	fprintf(output, "\n\n\nSeptember\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_SEPTEMBER; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_SEPTEMBER - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of October*/

	/*Print the month header*/
	fprintf(output, "\n\n\nOctober\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_OCTOBER; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_OCTOBER - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of November*/

	/*Print the month header*/
	fprintf(output, "\n\n\nNovember\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_NOVEMBER; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_NOVEMBER - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Reset day_of_week for the next month, saving it's value in day_of_week */
	starting_day_of_week = day_of_week;
	day_of_week = 0;

	/*Print the month of December*/

	/*Print the month header*/
	fprintf(output, "\n\n\nDecember\t\t\t\t\t%8d\n\n", user_year);
	fprintf(output, "Su\tMo\tTu\tWe\tTh\tFr\tSa\t\n\n");
	
	/*Print leading spaces to properly position the days of the month*/
	while(day_of_week < starting_day_of_week){
		fprintf(output, "\t");
		day_of_week++;
	}
	
	/*Print the numbered days*/
	for(i = 1; i <= DAYS_IN_DECEMBER; i++){
		day_of_week = ++day_of_week % 7;
		if(day_of_week % 7 && DAYS_IN_DECEMBER - i)
			fprintf(output, "%d\t", i);
		else
			fprintf(output, "%d\n", i);			
	}

	/*Close the output file*/


	/*Print exit message*/
	printf("Your calendar has finished printing, view %s to see your calendar!", OUTPTUT_FILE_LOCATION)

	return(0);
}
