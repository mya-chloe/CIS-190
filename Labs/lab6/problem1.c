/*
 *Nathan Burdzel
 *Lab 6
 *Problem 1
 */

/*Preprocessor Directives*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Defined Constants*/
#define BUFFER 256

/*Function Stubs*/
void findLength(int* number);
void sumDigits(int* number);
void findLargest(int* number);

int main(void){

	/*Declare Variables*/
	char string[BUFFER];
	int num;	

	/*Get a number greater than 0 from the user*/
	printf("Please enter an integer greater than 0:\n");	
	do{
		fgets(string, BUFFER, stdin);
		num = atoi(string);
		if(num < 1)
			printf("That number is not an integer greater than 0, please enter an integer greater than 0:\n");
	} while (num < 1);
	
	/*Find the length of the number and print it to the screen*/
	findLength(&num);
	
	/*Find the sum of the digits and print it to the screen*/
	sumDigits(&num);

	/*Find the largest digit and print it to theh screen*/
	findLargest(&num);

	return 0;
}



void findLength(int* number){

	/*Declare Variables*/	
	int i = 0, length = 0;

	/*Find the length*/
	for(i = 0; *number / (int) pow(10, i); i++){
		length++;
	}

	/*Print the length*/
	printf("The length of %d is %d\n", *number, length);
}

void sumDigits(int* number){

	/*Declare Variables*/	
	int i, total = 0;

	/*Find the total*/
	for(i = 0; *number / (int) pow(10, i); i++){
		total += (*number / (int) pow(10, i)) % 10;		
	}

	/*Print the total*/
	printf("The sum of the digits of %d is %d\n", *number, total);
}

void findLargest(int* number){

	/*Declare Variables*/	
	int i, largest = 0;

	/*Find the total*/
	for(i = 0; *number / (int) pow(10, i); i++){
		if((*number / (int) pow(10, i)) % 10 > largest)
			largest = (*number / (int) pow(10, i)) % 10;		
	}

	/*Print the total*/
	printf("The largest digit of %d is %d\n", *number, largest);

}
