/*Nathan Burdzel
 *Lab 7
 *Problem 2
 *10/24/18
 */

/*Preprocessor directives*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Defined constants*/
#define BUFFER 256

/*Function stubs*/
void reverseString(char string[], int index);
void printString(char string[]);

int main(void){
	
	/*Create the string*/
	char string[BUFFER] = {0};
	
	/*Get the string from user*/
	printf("Please enter your string\n");	
	fgets(string, BUFFER, stdin);
	string[strlen(string) - 1] = 0;		
	
	/*Print the reverse of string*/
	reverseString(string, 0);
	printString(string);	

	return 0;
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
}
