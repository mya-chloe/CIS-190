/*Nathan Burdzel
  *CIS 190
  *Homework 3
  *Problem 2
  *Recursive solution for the bolt matching problem
  *Bolt array is randomly generated using recursive algorithms that I wrote before we were told we could hard code the nut and bolt sizes
  *11/2/19
  */

/*Preprocessor directives*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Defined constants*/
#define NUMBER_OF_PAIRS 5

/*Function Stubs*/
void findMatches(int nut, int bolt, int nuts[], int bolts[]);
void populateArray(int toFill[], int index);
void placeInArray(int array[], int index, int number);

int main(void){
  /*Prepare rand() to be able to produce random numbers*/
  srand(time(NULL));

  /*Fill an array for the sizes of the nuts and bolts with all 0's*/
  int boltSizes [NUMBER_OF_PAIRS] = {0};
  int nutSizes [NUMBER_OF_PAIRS] = {0};

  /*Randomly populate the arrays with numbers 0 to NUMBER_OF_PAIRS*/
  populateArray(nutSizes, 0);
  populateArray(boltSizes, 0);

  /*Print the size of each nut*/
  for(int i = 0; i < NUMBER_OF_PAIRS; i++)
    printf("Nut %d: %d\n", i, nutSizes[i]);

  /*Print the size of each nut*/
  for(int i = 0; i < NUMBER_OF_PAIRS; i++)
    printf("Bolt %d: %d\n", i, boltSizes[i]);

  /*Find the bolt that matches each nut*/
  findMatches(0, 0, nutSizes, boltSizes);
}

/*Recursively finds a bolt that is a match for nut and prints out which number bolt they are andtheir size*/
void findMatches(int nut, int bolt, int nuts[], int bolts[]){

  /*If the nut and bolt are the same size print the result and move onto the next nut if one exists*/
  if(nuts[nut] == bolts[bolt]){
    printf("Nut %d(Size %d) matches with bolt %d(Size %d)\n", nut, nuts[nut], bolt, bolts[bolt]);
    if(nut < NUMBER_OF_PAIRS){
       findMatches(nut + 1, 0, nuts, bolts);
    }
  }

  /*Otherwise check it against the next bolt*/
  if(bolt < NUMBER_OF_PAIRS){
    findMatches(nut, bolt + 1, nuts, bolts);
  }
}

/*The following functions were created before I knew I could hard code the arrays so I didn't bother deleting them*/

/*Recursively populates array toFill with the integers from 0 to NUMBER_OF_PAIRS placed quasi-randomly within the array*/
void populateArray(int toFill[], int index){

  /*For each int from 0 to NUMBER_OF_PAIRS insert it into the array at a random spot*/
  if(index < NUMBER_OF_PAIRS){
    int random = rand() % NUMBER_OF_PAIRS + 1;
    placeInArray(toFill, random, index);
    populateArray(toFill, index + 1);
  }
}

/*Recursively place number an array at index index, or another empty index*/
void placeInArray(int array[], int index, int number){

  /*Base case: array[index] is empty*/
  if(!array[index])
    array[index] = number;

  /*Other cases: increase index by one, and if index ends up greater than the size of the array reset it to 0*/
  else
    placeInArray(array, (index + 1) % NUMBER_OF_PAIRS, number);
}
