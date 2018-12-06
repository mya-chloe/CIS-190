/*Nathan Burdzel*/
#include <stdlib.h>
#include <stdio.h>
/*Defined constants*/
#define OUTPUT_FILE "OUTPUT.txt"
#define INPUT_FILE "INPUT.txt"

int main(void){
	/*Declare Variables*/
	double userNumber = -1;
	int digits = 6;
	int i, j;

	/*Create Files*/	
	FILE *output;	
	FILE *input;	

	/*Get User Input*/
	input = fopen(INPUT_FILE, "r");
	fscanf(input, "%lf", &userNumber);
	/*Reject numbers that aren't 6 digits*/
	if(userNumber < 100000){
		printf("Please change the chosen number\n");
		return 1;
	}
	fclose(input);

	/*Open Print File*/
	output = fopen(OUTPUT_FILE, "w");
	
	/*Print Result To File*/	
	fprintf(output, "%lf\n", userNumber); 	
	
	/*Find the number of digits in the integer portion*/
	for(i = 1000000; (int)userNumber != (int)userNumber % i; i *= 10){
		digits++;
	} 
	/*Even Number of Digits*/	
	if(digits%2==0){
		/*Even digit print*/	
		for(j = 1; j < i; j *= 100){
			printf("%d", (int)userNumber/j%10);
		} 
		printf("\n");	

		/*Odd digit print*/
		for(j = 10; j <= i; j *= 100){
			printf("%d", (int)userNumber/(i/j)%10);
		} 
		printf("\n");
	/*Odd number of digits*/
	}else{
		/*Even digit print*/
		for(j = 10; j < i; j *= 100){
			printf("%d", (int)(userNumber/j)%10);
		} 
		printf("\n");
		
		/*Odd digit print*/
		for(j = 1; j <= i; j *= 100){
			printf("%d", (int)(userNumber/j)%10);
		} 
		printf("\n");
	}
	
	/*Close File*/
	fclose(output);	

	printf("View OUTPUT.txt for results.\n");
		
	return 0;
}
