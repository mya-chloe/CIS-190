/*Nathan Burdzel
 *Homework 3
 *Problem 3
 *10/30/18
 *Recursively finds the lowest number of pipes with a given stock length required to purchase to cut into smaller pipe lengths
 */

/*Preprocessor directives*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Defined constants*/
#define STOCK_LENGTH 10
#define MIN_PIPE_LENGTH 1

/*Function stubs*/
void rand_fill_array(int array[], int length, int min, int max);
int find_number_of_stock_pipes(int pipe_lengths[], int index, int number_of_pipes);
int remove_stock_length(int pipe_lengths[], int index, int number_of_pipes, int current_stock_length, int goal_stock_length);

int main(void){
  /*Declare variables*/
  int number_of_pipes = 3;
  int i;

  /*Get the number of pipes from the user*/
  printf("How many lengths of pipe do you need?");
  scanf("%d", &number_of_pipes);

  /*Create an array with and fill it with user entered values*/
  int pipe_lengths[number_of_pipes];
  for (i = 0; i < number_of_pipes; i++){
    /*Loop to used to insure valid user input*/ 
    do{
        /*Get a value from the user*/
        printf("What is the length of the next pipe?\n");
        scanf("%d", &pipe_lengths[i]);
        /*Make sure the value is valid(Longer than 0 and shorter than the stock length)*/
        if(pipe_lengths[i] < MIN_PIPE_LENGTH || pipe_lengths[i] > STOCK_LENGTH)
          printf("Please enter a pipe length between %d and %d\n", MIN_PIPE_LENGTH, STOCK_LENGTH);
    }while (pipe_lengths[i] < MIN_PIPE_LENGTH || pipe_lengths[i] > STOCK_LENGTH);
  }

  /*Print out the array of pipe lengths for clarity*/
  printf("The lengths of pipes that you requested are: %d", pipe_lengths[0]);
  for(i = 1; i < number_of_pipes; i++){
    printf(", %d", pipe_lengths[i]);
  }

  /*Print the solution to the problem*/
  printf("\nThe smallest possible number of stock pipes is %d", find_number_of_stock_pipes(pipe_lengths, 0, number_of_pipes));

  return 0;
}

/*Returns the number of stock pipes required to fulfill the group of orders given*/
int find_number_of_stock_pipes(int pipe_lengths[], int index, int number_of_pipes){
  /*If the pipe has already been used with another pipe move on to the next pipe*/
  if(!pipe_lengths[index])
    find_number_of_stock_pipes(pipe_lengths, index + 1, number_of_pipes);

  /*If there are no pipes remaining return 0*/
  else if(index >= number_of_pipes)
    return 0;

  /*If there is a single pipe return 1*/
  else if(index == number_of_pipes - 1)
    return 1;

  /*Remove pipes to match with this pipe from the array of pipes and return the number of pipes needed to fill the remaining orders*/
  else{
    /*Remove the lengths*/
  	remove_stock_length(pipe_lengths, index, number_of_pipes, STOCK_LENGTH, 0);
    /*Return the number of pipes needed to fill the orders*/
    return 1 + find_number_of_stock_pipes(pipe_lengths, index + 1, number_of_pipes);
  }
}

/*Takes the array of pipe lengths and sets to 0 the pipe located at the index this is orignally called at and the pipes needed to use the most possible stock with this pipe*/
int remove_stock_length(int pipe_lengths[], int index, int number_of_pipes, int current_stock_length, int goal_stock_length){
  /*Base Cases*/

  /*If the goal stock length was achieved return true*/
  if(current_stock_length == goal_stock_length)
    return goal_stock_length;
  /*If the length of the remaining pipe is negative return -1*/
  if(current_stock_length < 0)
    return -1;
  /*If every pipe was checked return -2*/
  if(index == number_of_pipes)
    return -2;

  /*Reduction steps / recursive calls*/

  /*If there is still space for pipes to be removed cut this pipe from the stock and try the next pipe*/
  int temp = pipe_lengths[index];
  pipe_lengths[index] = 0;
  /*Find the length remainder that was returned*/
  int achieved_length = remove_stock_length(pipe_lengths, index + 1, number_of_pipes, current_stock_length - temp, goal_stock_length);
  /*If the goal length was achieved*/
  if(achieved_length == goal_stock_length){
    /*Return that the goal length was achieved*/
    return goal_stock_length;
  }
  /*If you ran out of pipes try again with a smaller goal length*/
  else if(achieved_length == -2){
    pipe_lengths[index] = temp;
    return remove_stock_length(pipe_lengths, index, number_of_pipes, current_stock_length, goal_stock_length + 1);
  }
  /*If the pipe was too long try with the next pipe*/
  else if(achieved_length == -1){
    pipe_lengths[index] = temp;
    return remove_stock_length(pipe_lengths, index + 1, number_of_pipes, current_stock_length, goal_stock_length);
  }
}
