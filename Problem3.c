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
  for

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
  
  
  /*Remove pipes to match with this pipe form the array of pipes and return the number of pipes needed to fill the remaining orders*/
  else{
    /*Remove the lengths*/
  	remove_stock_length(pipe_lengths, index, number_of_pipes, STOCK_LENGTH, 0);
    /*Return the number of pipes needed to fill the orders*/
    int i;
    printf("\n");
    for (i = 0; i < number_of_pipes; i++)
        printf("%d", pipe_lengths[i]);
    return 1 + find_number_of_stock_pipes(pipe_lengths, index + 1, number_of_pipes);
  }
}

/*Takes the array of stock lengths and sets to 0 the pipe located at index and the pipes needed to use the most possible stock with this pipe*/
int remove_stock_length(int pipe_lengths[], int index, int number_of_pipes, int current_stock_length, int goal_stock_length){
  /*If the goal stock length was achieved return true*/
  if(current_stock_length == goal_stock_length)
    return goal_stock_length;
  /*If the goal was failed return -1*/
  if(current_stock_length < goal_stock_length)
    return -1;
  /*If every pipe was checked return -2*/
  if(index == number_of_pipes)
    return -2;
    
  /*If there is still space for pipes to be removed cut out this pipe and try the next pipe*/
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
  /*If the pipe was too long try the next index*/
  else if(achieved_length == -1){
    pipe_lengths[index] = temp;
    return remove_stock_length(pipe_lengths, index + 1, number_of_pipes, current_stock_length, goal_stock_length);
  }
}

/*Fill array with random numbers between min and max inclusive*/
void rand_fill_array(int array[], int length, int min, int max){
  int i;
  for(i = 0; i < length; i++){
    array[i] = rand() % (max - min) + min;
    printf("%d ", array[i]);
  }
}