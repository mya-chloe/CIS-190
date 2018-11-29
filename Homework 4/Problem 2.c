/*Nathan Burdzel
  *CIS 190
  *Homework 4
  *Problem 2
  *Recursive solution for the text prediction problem
  *11/15/19
  */

/*Preprocessor directives*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Defined constants*/
#define MIN_LETTER 97
#define MAX_LETTER 122
#define MIN_NUMBER 50
#define MAX_NUMBER 57
#define NUMBER_MODIFIER 48
#define NUMBER_OF_LETTERS 26
#define BUFFER 128
#define DICTIONARY_SIZE 125
#define DICTIONARY_FILE_PATH "dictionary.txt"

/*Function stubs*/
int convertCharToKey(char c, int keyCodes[NUMBER_OF_LETTERS]);
void getUserInput(char input[], int keyCodes[NUMBER_OF_LETTERS]);
int checkInputAgainstDictionary(char userInput[], int letter, int wordNumber, char word[], int keyCodes[], FILE* fp);
int checkInput(char userInput[], int index);

int main(void) {

    /*Declare variables*/
    int keyCodes[NUMBER_OF_LETTERS] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    char userInput[BUFFER] = {0};
    char word[BUFFER];
    FILE* fp;

    /*Get the string of numbers from the user*/
    getUserInput(userInput, keyCodes);

    /*Open the file*/
    fp = fopen(DICTIONARY_FILE_PATH, "r");


    /*Check the users input against the words in the dictionary printing every possible match, if there are no matches inform the user of this, if there are matches tell the user once the last one was printed*/
    if(!checkInputAgainstDictionary(userInput, 0, 0, word, keyCodes, fp))
      printf("No entries exist corresponding to that input");
    else
      printf("All entries printed");

    /*Close the file*/
    fclose(fp);

    return 0;
}

/*Gets a string of valid integers from the user and stores them as chars in userInput*/
void getUserInput(char userInput[], int keyCodes[NUMBER_OF_LETTERS]){
    /*Loop getting new input as long as invalid input was entered*/
    do{
      printf("Please enter the string of integers for text prediction:\n");
      fgets(userInput, BUFFER, stdin);
      /*Strip the newline character*/
      userInput[strlen(userInput) - 1] = '\0';
    } while (checkInput(userInput, 0));
}

/*Verifies that all of the chars are in the range of valid integers*/
int checkInput(char userInput[], int index){
  /*If the last character was checked return 0*/
  if(!userInput[index])
    return 0;
  /*If there is an invalid character print out a correction statement and return 1*/
  if(userInput[index] < MIN_NUMBER || userInput[index] > MAX_NUMBER){
    printf("Please enter only numbers between 2 and 9 inclusive\n");
    return 1;
  }
  /*Otherwise return the result for the check of the rest of input*/
  return checkInput(userInput, index + 1);
}

/*Retrieves the next word from the dictionary*/
void readWordFromDictionary(char word[], FILE* fp){
    fgets(word, BUFFER, fp);
    word[strlen(word) - 1] = '\0';
}

/*Returns the phone key that a letter belongs on, or 0 if c is an invalid character*/
int convertCharToKey(char c, int keyCodes[NUMBER_OF_LETTERS]){
    if(!(c < MIN_LETTER) && !(c > MAX_LETTER))
        return keyCodes[c - MIN_LETTER];
    return 0;
}

/*Recursively prints all words from the dictionary that correspond to the string of numbers in userInput, returns 0 if no words were found or a positive number if words were found*/
int checkInputAgainstDictionary(char userInput[], int letter, int wordNumber, char word[], int keyCodes[], FILE* fp){
    /*If the full dictionary was printed return that no word was found*/
    if(wordNumber >= DICTIONARY_SIZE){
        return 0;
    }
    /*If this is the first letter of a word load that word from the file*/
    if(!letter){
        readWordFromDictionary(word, fp);
    }
    /*If there are no more numbers provided by the user this word is a match, print this word and move on to the next word and ensure a positive number will be returned*/
    if(!userInput[letter]){
        printf("%s\n", word);
        return checkInputAgainstDictionary(userInput, 0, wordNumber + 1, word, keyCodes, fp) + 1;
    }
    /*If the letter from the word from the dictionary matches the respective number entered by the user check the next letter and return whether there was a match in the rest of the dictionary*/
    if(convertCharToKey(word[letter], keyCodes) == (userInput[letter] - NUMBER_MODIFIER))
        return checkInputAgainstDictionary(userInput, letter + 1, wordNumber, word, keyCodes, fp);
    /*There was no match, move on to the next word and return whether there was a match in the rest of the dictionary*/
    return checkInputAgainstDictionary(userInput, 0, wordNumber + 1, word, keyCodes, fp);
}
