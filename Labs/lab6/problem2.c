/*
 *Nathan Burdzel
 *Lab 6
 *Problem 2
 */

/*Preprocessor Directives*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Defined Constants*/
#define BUFFER 256

/*Function Stubs*/
void findLength(int number, int length);
void sumDigits(int number, int total);
void findLargest(int number, int largest);

int main(void){

	/*Declare Variables*/
	char string[BUFFER];
	int num, functionNum, length = 0, total = 0, largest = 0;	

	/*Get a number greater than 0 from the user*/
	printf("Please enter an integer greater than 0:\n");	
	do{
		fgets(string, BUFFER, stdin);
		num = atoi(string);
		if(num < 1)
			printf("That number is not an integer greater than 0, please enter an integer greater than 0:\n");
	} while (num < 1);
	

	/*Find the length of the number and print it to the screen*/
	printf("The length of %d is ", num);	
	findLength(num, length);
	
	/*Find the sum of the digits and print it to the screen*/
	printf("The sum of the digits of %d is ", num);
	sumDigits(num, total);

	/*Find the largest digit and print it to theh screen*/
	printf("The largest digit of %d is ", num);
	findLargest(num, largest);

	return 0;
}


/*Prints the length of number*/
void findLength(int number, int length){

	/*Terminating condition: The number is 0, print the length*/
	if(number == 0){
		printf("%d\n", length);
		return;	
	}

	/*Call the function again with the number having the last digit truncated and length incremented*/	
	findLength(number / 10, length + 1);
}

/*Prints the sum of the digits*/
void sumDigits(int number, int total){

	/*Terminating condition: The number is 0, print the total*/
	if(number == 0){
		printf("%d\n", total);
		return;
	}
	
	/*Increase total by the last digit of the number and call the function again with the new total and number having the last digit being truncated*/
	total += number % 10;
	sumDigits(number / 10, total);
}

void findLargest(int number, int largest){
	
	/*Terminating condition: The number is 0, print the largest number*/
	if(number == 0){
		printf("%d\n", largest);
		return;
	}
	
	/*Check if it's the largest digit found*/
	if(number % 10 > largest){
		largest = number % 10;
	}

	/*Call the function again with the current and number having the last digit being truncated*/
	findLargest(number / 10, largest);

}
