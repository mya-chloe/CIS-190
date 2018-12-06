/*Nathan Burdzel
 *Lab 7
 *Problem 1
 *10/24/18
 */

/*Preprocessor directives*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Defined constants*/
#define BUFFER 256

/*Function stubs*/
void printMatches(char stringA[], char stringB[]);

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
	printMatches(stringA, stringB);
	
	return 0;
}

/*Prints 1 if a character in stringA matches the respective character in stringB, and 0 if they don't if one string is longer than the other print 0's to length*/
void printMatches(char stringA[], char stringB[]){
	
	/*Starting index*/
	int index = 0;	
	
	/*Loop to go to length of longer string*/
	while(stringA[index] != '\0' || stringB[index] != '\0'){

		/*Print the result of the comparison and increment the index counter*/
		printf("%d ", stringA[index] == stringB[index]);
		index++;
	}
}
