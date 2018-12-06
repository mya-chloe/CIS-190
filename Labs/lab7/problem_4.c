/*Nathan Burdzel
 *Lab 7
 *Problem 4
 *10/24/18
 */

/*Preprocessor directives*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customString.h"

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
	
	/*Print the reverse of both strings*/
	reverseString(stringA, 0);
	reverseString(stringB, 0);
	printString(stringA);
	printString(stringB);

	/*Unreverse the strings*/
	reverseString(stringA, 0);
	reverseString(stringB, 0);

	/*Print the number of matches ignoring case*/
	printMatchesIgnoreCase(stringA, stringB);

	return 0;
}
