/*Nathan Burdzel
CIS 190 Lab 4
9/26/18
*/

#define minInt 0
#define maxInt 32767
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	/*Declare Variables*/
	int number = -1;
	int numberOfDigits = 1;
	int i, j;

	do{
	/*Get User Input*/
	printf("Please enter a number between 0 and 32,767, inclusive");
	scanf("%d", &number);
	
	/*Verify input*/
	}while (number < minInt || number > maxInt);
	
	/*Find the number of digits in number*/
	for(i = 1; pow(10, i) <= number; i++)
		numberOfDigits++;

	/*Print Result*/	
	for(i = 1; i <= numberOfDigits; i++){
		for(j = i; j <= numberOfDigits; j++){
			int digit = number / (int) pow((double) 10, (double) numberOfDigits - j);
			printf("%4d", digit % 10);
		} 
		printf("\n");
	}

	return 0;
}
