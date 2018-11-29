#ifndef BROKEN_H
	#define BROKEN_H
	//reverses a string
	void reverse();
    //checks if a string is a palindrone
	void pali();
    //counts the number of unique characters
	void countC();
    //menu for app
	void menu();
    //checks if a number is prime
	int prime(int num);
    //string menu
	void string();
    //number menu
	void numM();
    //plays a game
	void game(void);
    //Takes in a guess from the user for game and checks it
	int guess(char word[], char letter, char guessed[]);
    //draws a hangman depending on num wrong
	void draw(int countWrong);
    //fills Hangman array
	void fillArray(int stringLength, char guessed[]);
    //finds factorial of a number
	long fact(long num);
    //Finds the mean of any number of numbers, uses memory allocation
	void mean();
#endif
