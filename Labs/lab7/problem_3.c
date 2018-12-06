/*Nathan Burdzel
 *Lab 7
 *Problem 3
 *10/24/18
 */

/*Preprocessor directives*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Defined constants*/
#define BUFFER 256
#define MIN_LETTER 65
#define MAX_LETTER 90
#define LETTER_DIFFERENCE 32


/*Function stubs*/
void printMatchesIgnoreCase(char stringA[], char stringB[]);

int main(void){
	
	/*Create the two strings*/
	char stringA[BUFFER] = {0};
	char stringB[BUFFER] = {0};
	
	/*Get the first string from user*/
	printf("Please enter your first string\n");	
	fgets(stringA, BUFFER, stdin);
	stringA[strlen(stringA) - 1] = 0;		

	/*Get the second string from user*/
	printf("Please enter your second string\n");
	fgets(stringB, BUFFER, stdin);
	stringB[strlen(stringB) - 1] = 0;
	
	/*Print the number of matches*/
	printMatchesIgnoreCase(stringA, stringB);
	
	return 0;
}

/*Prints 1 if a character in stringA matches the respective character in stringB ignoring case, and 0 if they don't if one string is longer than the other print 0's to length*/
void printMatchesIgnoreCase(char stringA[], char stringB[]){
	
	/*Starting index*/
	int index = 0;	
	char a, b;	

	/*Loop to go to length of longer string*/
	while(stringA[index] != '\0' || stringB[index] != '\0'){

		/*Print the result of the comparison turning uppercase letters into lowercase letters and increment the index counter*/
		char a =((stringA[index] >= MIN_LETTER && stringA[index] <= MAX_LETTER) ? stringA[index] + LETTER_DIFFERENCE : stringA[index]);
		char b = ((stringB[index] >= MIN_LETTER && stringB[index] <= MAX_LETTER) ? stringB[index] + LETTER_DIFFERENCE : stringB[index]);
		printf("%d ", a == b);
		index++;
	}
}
