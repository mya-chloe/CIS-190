/*Nathan Burdzel
  *CIS 190
  *Homework 4
  *Problem 1
  *Recursive solution for the towers of HaHa problem
  *Towers of HaHa problem: You are given a stack of disks ordered from 1 to n where odd disks are colored red and even disks are colored orange
  *The goal is to move the disks from tower 1 to tower 2 such that no disks of the same color are ever placed directly on top of one another
  *11/2/19
  */

/*Preprocessor Directives*/
#include <stdio.h>

/*Function stubs*/
void towers(int, char, char, char, int total);

int main(){
  /*Declare variables*/
  int num;

  /*Get a numbder of disks from the user*/
  printf("Enter the number of disks:");
  scanf("%d", &num);

  /*Print out the solution*/
  printf("The sequence of moves involved in the Tower of HaHa are:\n");
  towers(1, 1, 2, 3, num);

  return 0;
}

/*Solves the tower of HaHa problem by flipping the disks already ordered to not be touching one of the same color, onto an auxillary tower, then flipping them back onto the goal tower*/
void towers (int num, char starting_tower, char goal_tower, char auxillary_tower, int total){
  /*If there is only one disk move it straight to the goal tower*/
  if (total == 1){
    printf("\nMove disk 1(Red) from peg %d to peg %d", starting_tower, goal_tower);
    return;
  }

  /*If the disk is at the bottom of the stack move it straight to tower 2*/
  if(num == total){
    printf("\nMove disk %d(%s) from peg %d to peg %d", num, (num % 2) ? "Red" : "Orange", starting_tower, goal_tower);
    return;
  }

  /*Move the disk to the the auxillary tower*/ 
  printf("\nMove disk %d(%s) from peg %d to peg %d", num, (num % 2) ? "Red" : "Orange", starting_tower, auxillary_tower);
  /*Move the rest of the disks to the goal tower*/ 
  towers(num + 1, starting_tower, goal_tower, auxillary_tower, total);
  /*Move the disk to the goal tower*/
  printf("\nMove disk %d(%s) from peg %d to peg %d", num, (num % 2) ? "Red" : "Orange", auxillary_tower, goal_tower);
}
