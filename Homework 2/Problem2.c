/*Nathan Burdzel
 *CIS 190
 *Homework 2
 *Problem 2
 *10/19/18
 */

/*Preprocessor Directives*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Defined Constants*/
#define INPUT_FILE "inputFile.txt"

/*Function Stubs*/
int getNumber(int loop);
int checkIfLargest(int number, int current);
int checkIfSecondLargest(int number, int current);
int checkIfThirdLargest(int number, int current);
void printLargest(int largest, int numberOfLargest, int secondLargest, int numberOfSecondLargest, int thirdLargest, int numberOfThirdLargest);

int main(void){

  /*Declare variables*/
  int i, number, largest = 0, numberOfLargest = 1, secondLargest = 0, numberOfSecondLargest = 1, thirdLargest = 0, numberOfThirdLargest = 1;

  /*Loop through each integer in the file*/
  for(i = 0; i < 20; i++){
    number = getNumber(i);

    /*Check if number is the largest number*/
    if(checkIfLargest(number, largest)){

      /*If it is the same as previous largest increase the number of that number found*/
      if(largest == number)
        numberOfLargest++;

      /*If it isn't move first and second largest and their counts to second and third largest respectively and replace largest with number with a count of 1 found*/
      else{
        thirdLargest = secondLargest;
        numberOfThirdLargest = numberOfSecondLargest;
        secondLargest = largest;
        numberOfSecondLargest = numberOfLargest;
        largest = number;
        numberOfLargest = 1;
      }

    /*Check if number is the second largest number*/
    }else if(checkIfSecondLargest(number, secondLargest)){

      /*If it is the same as previous second largest increase the number of that number found*/
      if(secondLargest == number)
        numberOfSecondLargest++;

      /*If it isn't move second largest and its count to  third largest and replace second largest with number with a count of 1 found*/
      else{
        thirdLargest = secondLargest;
        numberOfThirdLargest = numberOfSecondLargest;
        secondLargest = number;
        numberOfSecondLargest = 1;
      }

    /*Check if number is the third largest number*/
    }else if(checkIfLargest(number, thirdLargest)){

      /*If it is the same as previous third largest increase the number of that number found*/
      if(thirdLargest == number)
        numberOfThirdLargest++;

      /*If it isn't replace third largest with number with a count of 1 found*/
      else{
        thirdLargest = number;
        numberOfThirdLargest = 1;
      }
    }
  }

  /*Print the largest numbers and their number of occurences*/
  printLargest(largest, numberOfLargest, secondLargest, numberOfSecondLargest, thirdLargest, numberOfThirdLargest);


}

/*Gets the next number from the file*/
int getNumber(int loop){

  /*Open the file if this is the first loop(The requirements of needing to do this in this function, not being allowed arrays, and not being allowed pass by reference
  force me to use a static file or throw out the first loop numbers from the file that I already checked, I chose to use the static file as I feel it would be more efficient)*/
  static FILE* file;
  if (!loop)
    file = fopen(INPUT_FILE, "r");

  /*Retrieve the number*/
  int number;
  fscanf(file, "%d", &number);


  /*Close the file if this is the last number to be retrieved*/
  if(loop == 19)
    fclose(file);

  /*Return the number retrieved from the file*/
  return number;
}

/*Checks number against current, the current largest*/
int checkIfLargest(int number, int current){
  if(number >= current)
    return 1;
  return 0;
}

/*Checks number against current, the current second largest*/
int checkIfSecondLargest(int number, int current){
  if(number >= current)
    return 1;
  return 0;
}

/*Checks number against current, the current third largest*/
int checkIfThirdLargest(int number, int current){
  if(number >= current)
    return 1;
  return 0;
}

/*Prints the largest numbers and their number of occurences*/
void printLargest(int largest, int numberOfLargest, int secondLargest, int numberOfSecondLargest, int thirdLargest, int numberOfThirdLargest){
  printf("The largest number is %d with %d occurences\nThe second largest number is %d with %d occurences\nThe third largest number is %d with %d occurences\n", largest, numberOfLargest, secondLargest, numberOfSecondLargest, thirdLargest, numberOfThirdLargest);
}
