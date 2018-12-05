/*Nathan Burdzel
 *CIS 190
 *Homework 5
 *Problem 1
 *11/27/18
 *Note: In case you were not informed I got an extension from Professor Valova because I needed to reinstall my OS and lost all of my files on sunday.
 */

/********************Preprocessor directives*********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Defined constants*/
/*Jagged array definitions*/
#define NUMBER_OF_ROWS 5
#define NUMBER_OF_ELEMENTS 30
#define ELEMENTS_IN_FIRST 10
#define ELEMENTS_IN_SECOND 5
#define ELEMENTS_IN_THIRD 2
#define ELEMENTS_IN_FOURTH 7
#define ELEMENTS_IN_FIFTH 6
#define LONGEST_ROW 10

/*Random number  generation definitions*/
#define MIN_FLOAT 0
#define MAX_FLOAT 100

/**************Function stubs*********************/
void generateFloats(float floats[NUMBER_OF_ELEMENTS]);
float generateFloat();
void allocateMemory(float *** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]);
void freeMemory(float *** jaggedArray);
void populateArray(float floats[], float *** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]);
void sortArray(float ** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]);
void quickSort(int index, int elementsInRow[NUMBER_OF_ROWS], float ** jaggedArray, int left, int right);
int partition(int index, int left, int right, int elementsInRow[NUMBER_OF_ROWS], float ** jaggedArray);
void insertionSort(int index, int elementsInRow[NUMBER_OF_ROWS], float ** jaggedArray);
void swap(float * first, float * second);
void printArray(float ** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]);

/*********************Main method**************************/
int main(void){
  /****Declare variables*********/
  float ** jaggedArray;
  float floats[NUMBER_OF_ELEMENTS];
  int elementsInRow[NUMBER_OF_ROWS] = {ELEMENTS_IN_FIRST, ELEMENTS_IN_SECOND, ELEMENTS_IN_THIRD, ELEMENTS_IN_FOURTH, ELEMENTS_IN_FIFTH};

  /*Seed the random number generator*/
  srand(time(0));

  /*Generate the random floats*/
  generateFloats(floats);

  /*Allocate the memory for the jagged array*/
  allocateMemory(&jaggedArray, elementsInRow);

  /*Assign values to the memory*/
  populateArray(floats, &jaggedArray, elementsInRow);

  /*Apply the sorts*/
  sortArray(jaggedArray, elementsInRow);

  /*Print the results*/
  printArray(jaggedArray, elementsInRow);

  /*Free the memory*/
  freeMemory(&jaggedArray);

  return 0;
}

/*Populates array with random floating point numbers*/
void generateFloats(float floats[NUMBER_OF_ELEMENTS]){
  /*Declare local variables*/
  int i;

  /*For every element in the array*/
  for(i = 0; i < NUMBER_OF_ELEMENTS; i++){
    /*Assign that element to be a random float*/
    floats[i] = generateFloat();
  }
}

/*Generates a single floating point number between MIN_FLOAT and MAX_FLOAT*/
float generateFloat(){
  return (float) MIN_FLOAT + ((float) rand() / ((float) RAND_MAX / (float) MAX_FLOAT));
}

/*Allocates memory for the jagged array described by the defined constants*/
void allocateMemory(float *** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]){
  /*Declare local variables*/
  int i;
  /*Create an element for each row*/
  *jaggedArray = malloc(sizeof(float*) * NUMBER_OF_ROWS);
  /*Set each row to be the full size*/
  for (i = 0; i < NUMBER_OF_ROWS; i++){
    (*jaggedArray)[i] = malloc(sizeof(float) * elementsInRow[i]);
  }
}

/*Frees the jaggedArray*/
void freeMemory(float *** jaggedArray){
  /*Declare local variables*/
  int i;

  /*Free each row individually*/
  for(i = 0; i < NUMBER_OF_ROWS; i++){
    free((*jaggedArray)[i]);
  }

  /*Free the full array*/
  free(*jaggedArray);
}

/*Populates the array with the random floats*/
void populateArray(float floats[], float *** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]){
  /*Declare local variables*/
  int i, j, index = 0;

  /*Loop through all of the positions in the jaggedArray*/
  for(i = 0; i < NUMBER_OF_ROWS; i++){
    for(j = 0; j < elementsInRow[i]; j++){
      /*Assign the element to the float at the current index then increment index*/
      (*jaggedArray)[i][j] = floats[index];
      index++;
    }
  }
}

/*Sorts the array according to the provided rules*/
void sortArray(float ** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]){
  /*Declare local variables*/
  int i;

  /*For every column in the jaggedArray*/
  for(i = 0; i < LONGEST_ROW; i++){
    /*If it is an odd numbered row do an insertion sort*/
    if(i % 2){
      insertionSort(i, elementsInRow, jaggedArray);
    }
    /*Otherwise do a quick sort*/
    else{
        quickSort(i, elementsInRow, jaggedArray, 0, NUMBER_OF_ROWS - 1);
    }
  }
}

/*Recurssively sorts element index of each array using quick sort via partitioning*/
void quickSort(int index, int elementsInRow[NUMBER_OF_ROWS], float ** jaggedArray, int left, int right){
   /*Declare variables*/
   int pivot;

   /*If the partition is too small to partition again return*/
   if(right - left <= 0){
       return;
   }

   /*Partition the array*/
   pivot = partition(index, left, right, elementsInRow, jaggedArray);
   /*Sort the left*/
   quickSort(index, elementsInRow, jaggedArray, left, pivot - 1);
   /*Then the right*/
   quickSort(index, elementsInRow, jaggedArray, pivot + 1, right);

  return;
}

/*Recurssively splits the array so that all values less than jaggedArray[pivotIndex][index] are before it in the table, and all greater are after it*/
int partition(int index, int left, int right, int elementsInRow[NUMBER_OF_ROWS], float ** jaggedArray){
    /*Declare local variables*/
    int leftPointer = left, rightPointer;
    int pivot = right;

    /*Adjust pivot to ensure that it is within the bounds of an array*/
    while(elementsInRow[pivot] <= index){
        pivot--;
        /*If pivot made it all the way to the left pointer return it*/
        if(pivot == left)
            return pivot;
    }
    /*Set rightPointer to be the last element before pivot*/
    rightPointer = pivot - 1;
    
    /*Infinite loop to be broken out of inside*/
    while(1){
        /*While leftPointer corresponds to an element outside of the array or corresponds to a value less than the pivot increment it*/
        while(elementsInRow[leftPointer] <= index || jaggedArray[leftPointer][index] < jaggedArray[pivot][index])
             leftPointer++;
        /*While rightPointer corresponds to an element outside of the array or corresponds to a value greater than the pivot decrement it*/
        while(elementsInRow[rightPointer] <= index || (rightPointer > 0 && jaggedArray[rightPointer][index] >= jaggedArray[pivot][index])){
             rightPointer--;
        }
        /*If leftPointer is on the wrong side of rightPointer*/
        if(leftPointer >= rightPointer){
            break;
        }
        /*Otherwise swap the positions with an index of leftPointer and rightPointer*/
        else
            swap(jaggedArray[leftPointer] + index, jaggedArray[rightPointer] + index);
    }
    /*If the left pointer is within bounds*/
    if(elementsInRow[leftPointer] > index){
        /*Swap the positions of the elements at pivot and leftPointer and return the new position of the pivot*/
        swap(jaggedArray[leftPointer] + index, jaggedArray[pivot] + index);
        return leftPointer;
    }
}

/*Non-Recurssively sorts element index of each array using insertion sort*/
void insertionSort(int index, int elementsInRow[NUMBER_OF_ROWS], float ** jaggedArray){
  int i, j;
  float *min;
  /*For every row in the array except the last*/
  for(i = 0; i < NUMBER_OF_ROWS; i++){
    /*If that row is not already outside of bounds*/
    if(elementsInRow[i] > index){
      /*Find the lowest number*/
      /*For every remaining row in the array*/
      for(j = i; j < NUMBER_OF_ROWS; j++){
          /*If this row is in bounds*/
          if(elementsInRow[j] > index){
            /*If this is the first element being checked or it is smaller than the last value checked set min to the memory location of jaggedArray[i][j]*/
            if(i == j || (jaggedArray[j][index] < *min)){
                min = jaggedArray[j] + index;
            }
          }
        }
        /*Swap the element at index in jaggedArray[i] with the smallest value found*/
        swap(jaggedArray[i] + index, min);
    }
  }
}

/*Swaps two values using temp as an auxillary value*/
void swap(float * first, float * second){
    float temp = *first;
    *first = *second;
    *second = temp;
}

/*Prints out every value in the array*/
void printArray(float ** jaggedArray, int elementsInRow[NUMBER_OF_ROWS]){
  /*Declare local variables*/
  int i, j;

  /*Loop through all of the positions in the jaggedArray*/
  for(i = 0; i < NUMBER_OF_ROWS; i++){
    for(j = 0; j < elementsInRow[i]; j++){
      /*Assign the element to the float at the current index then increment index*/
      printf("%f ", jaggedArray[i][j]);
    }
    /*End each line with a newline*/
    printf("\n");
  }
}
