/*Nathan Burdzel
 *CIS 190
 *Homework 2
 *Problem 3
 *10/19/18
 */

/*Preprocessor Directives*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Defined Constants*/
#define INPUT_FILE "inputFile.txt"

/*Function Stubs*/
int getNumber(FILE**);
void checkAgainstLargest(int* number, int* largest, int* numberOfLargest, int* secondLargest, int* numberOfSecondLargest, int* thirdLargest, int* numberOfThirdLargest);
int checkIfLargest(int* number, int* current, int* currentOccurences);
int checkIfSecondLargest(int* number, int* current, int* currentOccurence);
int checkIfThirdLargest(int* number, int* current, int* currentOccurences);
void printLargest(int* largest, int* numberOfLargest, int* secondLargest, int* numberOfSecondLargest, int* thirdLargest, int* numberOfThirdLargest);

int main(void){

  /*Declare variables*/
  int i, number, largest = 0, numberOfLargest = 1, secondLargest = 0, numberOfSecondLargest = 1, thirdLargest = 0, numberOfThirdLargest = 1;
  FILE* file;

  /*Open the file*/
  file = fopen(INPUT_FILE, "r");

  /*Loop through each integer in the file*/
  for(i = 0; i < 20; i++){
    number = getNumber(&file);

    /*Check to see if it one of the largest 3 integers*/
    checkAgainstLargest(&number, &largest, &numberOfLargest, &secondLargest, &numberOfSecondLargest, &thirdLargest, &numberOfThirdLargest);
  }

  /*Close the file*/
  fclose(file);

  /*Print the largest numbers and their number of occurences*/
  printLargest(&largest, &numberOfLargest, &secondLargest, &numberOfSecondLargest, &thirdLargest, &numberOfThirdLargest);


}

/*Gets the next number from the file*/
int getNumber(FILE** file){

  /*Retrieve the number*/
  int number;
  fscanf(*file, "%d", &number);

  /*Return the number retrieved from the file*/
  return number;
}

/*Checks against the largest three numbers*/
void checkAgainstLargest(int* number, int* largest, int* numberOfLargest, int* secondLargest, int* numberOfSecondLargest, int* thirdLargest, int* numberOfThirdLargest){
  /*Check if number is the largest number*/
  if(checkIfLargest(number, largest, numberOfLargest)){

    /*If it is move first and second largest and their counts to second and third largest respectively and replace largest with number with a count of 1 found*/
    *thirdLargest = *secondLargest;
    *numberOfThirdLargest = *numberOfSecondLargest;
    *secondLargest = *largest;
    *numberOfSecondLargest = *numberOfLargest;
    *largest = *number;
    *numberOfLargest = 1;

/*Check if number is the second largest number*/
}else if(*number < *largest && checkIfSecondLargest(number, secondLargest, numberOfSecondLargest)){

    /*If it is move second largest and its count to  third largest and replace second largest with number with a count of 1 found*/
    *thirdLargest = *secondLargest;
    *numberOfThirdLargest = *numberOfSecondLargest;
    *secondLargest = *number;
    *numberOfSecondLargest = 1;

/*Check if number is the third largest number*/
}else if(*number < *secondLargest && checkIfThirdLargest(number, thirdLargest, numberOfThirdLargest)){

    /*If it is replace third largest with number with a count of 1 found*/
    *thirdLargest = *number;
    *numberOfThirdLargest = 1;

  }
}

/*Checks number against current, the current largest, return 1 if number is larger, otherwise return 0. If they are the same size increment the number of occurences*/
int checkIfLargest(int* number, int* current, int* currentOccurences){

  /*If number matches current increase the number of occurences*/
  if(*number == *current)
    *currentOccurences += 1;

  /*If number is larger than current return the value of 1*/
  if(*number > *current)
    return 1;

  /*If number is smaller return 0*/
  return 0;
}

/*Checks number against current, the current second largest, return 1 if number is larger, otherwise return 0. If they are the same size increment the number of occurences*/
int checkIfSecondLargest(int* number, int* current, int* currentOccurences){

    /*If number matches current increase the number of occurences*/
    if(*number == *current)
      *currentOccurences += 1;

    /*If number is larger than current return the value of 1*/
    if(*number > *current)
      return 1;

    /*If number is smaller return 0*/
    return 0;
}

/*Checks number against current, the current third largest, return 1 if number is larger, otherwise return 0. If they are the same size increment the number of occurences*/
int checkIfThirdLargest(int* number, int* current, int* currentOccurences){

    /*If number matches current increase the number of occurences*/
    if(*number == *current)
      *currentOccurences += 1;

    /*If number is larger than current return the value of 1*/
    if(*number > *current)
      return 1;

    /*If number is smaller return 0*/
    return 0;
}

/*Prints the largest numbers and their number of occurences*/
void printLargest(int* largest, int* numberOfLargest, int* secondLargest, int* numberOfSecondLargest, int* thirdLargest, int* numberOfThirdLargest){
  printf("The largest number is %d with %d occurences\nThe second largest number is %d with %d occurences\nThe third largest number is %d with %d occurences\n", *largest, *numberOfLargest, *secondLargest, *numberOfSecondLargest, *thirdLargest, *numberOfThirdLargest);
}
