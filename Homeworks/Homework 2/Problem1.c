/*Nathan Burdzel
 *CIS 190
 *Homework 2
 *Problem 1
 *10/19/18
 *Note: Several functions utilize pass by reference when they should more realistically be pass by value, this is only due to the requirement of having them be pass by reference
 */

/*Preprocessor Directives*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Function Stubs*/
void print_square_root(int* number, int* numberOfIntegers);
void print_number_of_integers(int* numberOfIntegers);
void print_sum_of_integers(int* sum, int* number);
void print_average_of_integers(int* sum, int* numberOfValues);
void print_if_under_twenty(int* number, int* underTwenty);
void print_if_outside_range(int* number, int* outsideRange);
void do_operations(int* number, int* sum, int* underTwenty, int* outsideRange);

int main(void){

  /*Declare variables*/
  int userNumber, numberOfIntegers = 0, sum = 0, underTwenty = 0, outsideRange = 1;

  /*Begin the loop for integers*/
  do{

    /*Get user input*/
    printf("Please enter a positive integer, or a negative integer to quit: ");
    scanf("%d", &userNumber);

    /*Check to see if the loop should be quit or not*/
    if(userNumber < 0){
      break;
    }

    /*Increment the count of integers entered*/
    numberOfIntegers++;

    /*Print the square root of the number*/
    print_square_root(&userNumber, &numberOfIntegers);

    /*Perform the per-number operations*/
    do_operations(&userNumber, &sum, &underTwenty, &outsideRange);


  }while (userNumber >= 0);


  /*Print number of integers entered so far*/
  print_number_of_integers(&numberOfIntegers);

  /*Print the total of the integers entered so far*/
  print_sum_of_integers(&sum, &userNumber);

  /*Print the average of the integers entered so far*/
  print_average_of_integers(&sum, &numberOfIntegers);

  /*Print whether or not a number under 20 was entered*/
  print_if_under_twenty(&userNumber, &underTwenty);

  /*Print whether all the numbers are in the range of 10-90*/
  print_if_outside_range(&userNumber, &outsideRange);
}

/*Prints out the square root of number, or -1 if number is negative*/
void print_square_root(int* number, int* numberOfIntegers){
  if(*number >= 0){
    printf("The square root of integer %d is: \t\t%.2f\n", *numberOfIntegers, sqrt(*number));
  } else
    printf("-1\n");
}

/*Prints out the number of integers entered so far*/
void print_number_of_integers(int* numberOfIntegers){
  printf(".......\nThe number of integers is : \t\t\t%d\n", *numberOfIntegers);
}

/*Increases total by number and prints the result*/
void print_sum_of_integers(int* sum, int* number){
  printf("The sum of the integers is: \t\t\t%d\n", *sum);
}

/*Prints the average of the integers*/
void print_average_of_integers(int* sum, int* numberOfValues){
  printf("The average of the integers is:\t\t\t%.2f\n", (float) *sum / *numberOfValues);
}

/*Prints whether or not a number under twenty has been printed*/
void print_if_under_twenty(int* number, int* underTwenty){
  printf("At least one number was <20: \t\t\t%s\n", *underTwenty ? "True" : "False");
}

/*Prints whether or not a number outside of 10-90 has been printed*/
void print_if_outside_range(int* number, int* outsideRange){
  printf("All numbers were between 10 and 90: \t\t%s\n\n", *outsideRange ? "True" : "False");
}

/*Adds number to the sum of all numbers entered and performs the range checking operations*/
void do_operations(int* number, int* sum, int* underTwenty, int* outsideRange){

  /*Increase sum by number*/
  *sum += *number;

  /*Check to see if number is under twenty*/
  if(*number < 20)
    *underTwenty = 1;

  /*Check to see if number is outisde the range of 10-90*/
  if(*number < 10 || *number > 90)
    *outsideRange = 0;
}
