/*
Nathan Burdzel
*/
#define LOWER_BOUND 25
#define UPPER_BOUND 50

#include <stdlib.h>
#include <stdio.h>

int main(void){
	/*Declare variables*/
	int random = 0;

	/*Initialize rand function*/
	srand(time(NULL));
	
	/*Generate random number*/		
	random = (rand() % (UPPER_BOUND - LOWER_BOUND)) + LOWER_BOUND;
	
	/*Print the random number*/
	printf("Your number is: %d\n", random);

	return 0;
}
