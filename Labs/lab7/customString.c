/*Nathan Burdzel
 *Lab 7
 *Problem 4 Functions
 *10/24/18
 */

#include "customString.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	printf("\n");
}

/*Reverses the order of the characters in string*/
void reverseString(char string[], int index){	
	
	/*Check to see if the middle of the string was reached*/	
	if((strlen(string)) / 2 == index)  
		return;

	/*Swap the first and last characters*/
	char temp = string[index];
	string[index] = string[strlen(string) - 1 - index];
	string[strlen(string)- 1 - index] = temp;
	
	/*Reverse the rest of the string*/
	reverseString(string, index + 1);
}

/*Prints out string*/
void printString(char string[]){
	int i;	
	for(i = 0; i < strlen(string); i++)
		printf("%c", string[i]);
	printf("\n");
}


/*Prints 1 if a character in stringA matches the respective character in stringB ignoring case, and 0 if they don't if one string is longer than the other print 0's to length*/
void printMatchesIgnoreCase(char stringA[], char stringB[]){
	
	/*Starting index*/
	int index = 0;	
	
	/*Loop to go to length of longer string*/
	while(stringA[index] != '\0' || stringB[index] != '\0'){

		/*Print the result of the comparison turning uppercase letters into lowercase letters and increment the index counter*/
		printf("%d ", ((stringA[index] >= MIN_LETTER && stringA[index] <= MAX_LETTER) ? stringA[index] + LETTER_DIFFERENCE : stringA[index]) == ((stringB[index] >= MIN_LETTER && stringB[index] <= MAX_LETTER) ? stringB[index] + LETTER_DIFFERENCE : stringB[index]));
		index++;
	}
}
