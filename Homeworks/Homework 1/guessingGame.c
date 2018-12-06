/*
Nathan Burdzel
CIS 190 10/4/18
Homework 1 Problem 2*/

/*Preprocessor Directives*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
	srand(time(0));
	const int TRIES = 10, DIGITS = 3;
	int random_number, user_number, identical_digits = 0, hits = 0, matches = 0;

	/*Generate a random number with three different digits*/
	do{
		identical_digits = 0;
		random_number = rand() % ((int) pow(10, DIGITS - 1) - (int) pow(10, DIGITS)) + (int) pow(10, DIGITS - 1);
		for(int i = 0; i < DIGITS; i++)
			for(int j = 0; j < DIGITS; j++)
				if (i != j)
					if(random_number / (int) pow(10, i) % 10 == random_number / (int) pow(10, j) % 10)
						identical_digits++;
	}while(identical_digits);

	/*Print welcome statements*/
	printf("Let's play a guessing game! I will give you %d tries to guess a %d-digit number.\nFor each number in your guess I will tell you if each digit is\n1: A hit(a correct number in the correct place)\n2: A match(a correct number in the wrong place)\n3: A miss(a number not in my number)\n", TRIES, DIGITS);

	for(int i = 1; i <= TRIES; i++){
		/*Give user a prompt for a three digit number and retrieve the number*/
		i == TRIES ? printf("This is your final guess\nWhat is your guess?") : printf("This is guess number: %d\nWhat is your guess?", i);
		do{
			scanf("%d", &user_number);
			if(user_number < pow(10, DIGITS - 1) || user_number >= pow(10, DIGITS))
				printf("Please enter a %d-digit number", DIGITS);
		} while (user_number < pow(10, DIGITS - 1) || user_number >= pow(10, DIGITS));

		/*Check each digit for hit match or miss*/
		for(int j = DIGITS - 1; j >= 0; j--){

			/*Check to see if the digit is a hit, if it is tell the user and increase the number of hits found*/
			if(random_number / (int) pow(10, j) % 10 == user_number / (int) pow(10, j) % 10){
				printf("%d is a hit!\n", user_number / (int) pow(10, j) % 10);
				hits++;
			}

			else {
				/*If the digit isn't a hit check it against every other digit in the number to see if it's a match, if it is tell the user and increase the number of matches found*/
				for(int k = 0; k < DIGITS; k++){
					if(random_number / (int) pow(10, k) % 10 == user_number / (int) pow(10, j) % 10){
						printf("%d is a match\n", user_number / (int) pow(10, j) % 10);
							matches++;
					}
				}

				/*If no matches were found it's miss*/
				if(!matches){
					printf("%d is a miss\n", user_number / (int) pow(10, j) % 10);
				}

				/*Reset matches for the next loop*/
				matches = 0;
			}
		}

		/*If every digit was a hit print a win statement and end the program*/
		if(hits == DIGITS){
			printf("You correctly guessed that my number was %d!", random_number);
			return 0;
		}

		/*Reset the number of hits for the next loop*/
		hits = 0;
	}

	/*If every guess was used print a loss statement and end the program*/
	printf("You failed to guess that my number was %d", random_number);
	return 0;
}
