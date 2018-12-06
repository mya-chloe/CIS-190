/*Nathan Burdzel
 *Lab 7
 *Problem 4 Header
 *10/24/18
 */

#ifndef CUSTOMSTRING_H
	#define CUSTOMSTRING_H
	#define BUFFER 512
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define MIN_LETTER 65
	#define MAX_LETTER 90
	#define LETTER_DIFFERENCE 32
	void reverseString(char string[], int index);
	void printString(char string[]);
	void printMatches(char stringA[], char stringB[]);
	void printMatchesIgnoreCase(char stringA[], char stringB[]);
#endif
