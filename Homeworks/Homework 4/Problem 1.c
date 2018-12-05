/*Nathan Burdzel
  *CIS 190
  *Homework 4
  *Problem 1
  *Recursive solution for the pyramid problem
  *11/15/19
  */

Preprocessr directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*Defined constants*/
/*Note: MAX_WEIGHT * 10 ^ DECIMAL_ACCURACY cannot exceed the integer maximum*/
#define MIN_WEIGHT 50
#define MAX_WEIGHT 350
#define MIN_ROWS 1
#define MAX_ROWS 9
#define DECIMAL_ACCURACY 2

/*Funcion stubs*/
void fillPyramid(int toFill, double* pyramid);
void getRowInput(int* userRows);
int findNumberOfPeople(int rows);
void printPyramid(int row, int index, int maxRows, double* rowStart);
void printSpaces(int numberOfSpaces);
void addWeights(int row, int index, int maxRows, double* rowStart);

int main(void){
  /*Declare variables*/
  int userRows;

  /*Get the number of rows the user wants*/
  getRowInput(&userRows);

  /*Use the user entered number of rows to make an array of the proper size plus one 0 weight*/
  double pyramid[findNumberOfPeople(userRows + 1)];

  /*Prep random values*/
  srand(time(NULL));

  /*Fill pyramid with random values*/
  fillPyramid(findNumberOfPeople(userRows), pyramid);

  /*Print out the starting pyramid*/
  printf("The pyramid of starting weights looks like:\n");
  printPyramid(0, 0, userRows, pyramid);

  /*Distribute the weights down the pyramid to find out the effective weight on each person*/
  addWeights(1, 0, userRows, pyramid);

  /*Print the pyramid with the effective weights*/
  printf("After distributing the weights from above the pyramid of weights looks like:\n");
  printPyramid(0, 0, userRows, pyramid);

  return 0;
}

/*Fills the pyramid with random weights up to the full number of people*/
void fillPyramid(int toFill, double* pyramid){
  /*If more numbers need to be filled add the next random number and fill the rest of the array*/
  if(toFill > 0){
  /*Note: The random number generated will have a bias due to the size of the range of numbers generated by rand()(0-32767) and the default max weight and decimal accuracy I am using(two decimal digits), so the first 2767 numbers will have double the chance of being chosen*/
  *(pyramid + toFill - 1) = (double) (rand() % ((int) ((MAX_WEIGHT - MIN_WEIGHT) * pow(10, DECIMAL_ACCURACY))) + MIN_WEIGHT * pow(10, DECIMAL_ACCURACY)) / (double) pow(10, DECIMAL_ACCURACY);
  fillPyramid(toFill - 1, pyramid);
  }
}

/*Gets the number of rows in the pyramid from the user and verifies that it is in the proper range*/
void getRowInput(int* userRows){
    /*Get input from the user*/
    printf("How many rows tall is the pyramid?");
    do{
      scanf("%d", userRows);
      /*Print statements asking for corrected input*/
      if(*userRows > MAX_ROWS)
        printf("Please enter a number of rows less than or equal to %d rows", MAX_ROWS);
      if(*userRows < MIN_ROWS)
        printf("Please enter a number of rows greater than or equal to %d rows", MIN_ROWS);
    /*Continue looping until valid input is provided*/
    }while (*userRows > MAX_ROWS || *userRows < MIN_ROWS);
}

/*Find the number of people that will exist in a pyramid with rows rows*/
int findNumberOfPeople(int rows){
  /*If this is not the last row*/
  if(rows)
    /*Return the number of people remaining plus the number of people in this row*/
    return findNumberOfPeople(rows - 1) + rows;
}

/*Prints out all the weights in the pyramid formatted to look like a pyramid*/
void printPyramid(int row, int index, int maxRows, double* rowStart){
  /*If the end of the row was reached*/
  if(index >= row){
    /*If the next row isn't empty print out the spaces on a new line and print the rest of the rows*/
    printf("\n");
    if(row < maxRows){
      printSpaces(maxRows - (row + 1));
      printPyramid(row + 1, 0, maxRows, rowStart + row);
    }
  }
  /*If this is in the middle of a row print out the persons weight and print the rest of the row*/
  else{
    printf("%6.2lf\t\t", *(rowStart + index));
    printPyramid(row, index + 1, maxRows, rowStart);
  }
}

/*Prints out the spaces required for formatting the pyramid in a pyramid shape*/
void printSpaces(int numberOfSpaces){
  if(numberOfSpaces){
    printf("\t");
    printSpaces(numberOfSpaces - 1);
  }
}

/*Increases the weights in the pyramid beneath the person indicated by rowStart and index*/
void addWeights(int row, int index, int maxRows, double* rowStart){
  /*Base case: If the next row is empty no more weights need to be added*/
  if(row < maxRows){
    /*If this item is past the end of the row add the weights on the next row*/
    if(index >= row)
      addWeights(row + 1, 0, maxRows, rowStart + row);
    /*Otherwise add one half the weight on this person to the two people below them and move on to the next person in this row*/
    else{
      *(rowStart + row + index) += *(rowStart + index) / 2;
      *(rowStart + row + index + 1) += *(rowStart + index) / 2;
      addWeights(row, index + 1, maxRows, rowStart);
    }
  }
}