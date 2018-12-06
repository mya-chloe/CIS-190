/*
Nathan Burdzel
*/

#define INCHES_PER_FOOT 12
#define INCHES_PER_YARD 36
#define CENTIMETERS_PER_INCH 2.54
#define INCHES_PER_METER 39.37

#include <stdlib.h>
#include <stdio.h>

int main(void){
	/*Declare variables*/
	float measure_in_inches = 0;
	float feet = 0;
	float yards = 0;
	float centi = 0;
	float meters = 0;

	/*Get user input*/
	scanf("%f", &measure_in_inches);

	feet = measure_in_inches / INCHES_PER_FOOT;
	yards = measure_in_inches / INCHES_PER_YARD;
	centi = measure_in_inches * CENTIMETERS_PER_INCH;
	meters = measure_in_inches / INCHES_PER_METER;
	printf("%.2f inches is %.2f feet,\n%.2f yards,\n%.2f centimeters,\nand %.2f meters\n", measure_in_inches, feet, yards, centi, meters);	
	
	return 0;
}
