/*Nathan Burdzel
  *CIS 190
  *Lab 10
  *Broken lab
  *11/22/19
  */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "broken.h"
#define BUF 256

char in[BUF];


int main(void){
  menu();

  return 0;
}

void menu(){
  int choice = 0;
  char in[BUF] = {0};
  while(choice != 4){
    printf("Enter 1 for string choices, 2 for number choices, and 3 for a game, 4 to exit\n");
    fgets(in, BUF, stdin);
    choice = strtol(in, NULL, 10);
    switch(choice){
        case 1:
            string();
            break;
        case 2:
            numM();
            break;
        case 3:
            game();
            break;
        case 4:
            break;
        default:
            printf("Bad choice\n");
            break;
    }
  }
  return;
}

void string(){
  int choice = -1;
  char in[BUF] = {0};
  while(choice != 4){
    printf("Enter 1 for reverse, 2 for palindrome check, and 3 to check number of unique characters, 4 to exit\n");
    fgets(in, BUF, stdin);
    choice = strtol(in, NULL, 10);
    switch(choice){
      case 1:
        reverse();
        break;
      case 2:
        pali();
        break;
      case 3:
        countC();
        break;
      case 4:
        break;
      default:
        printf("Bad choice\n");
        break;
    }
  }
}

void numM(){
  int choice = -1;
  char in[BUF] = {0};
  while(choice != 4){
    printf("Enter 1 for factorial, 2 for prime check, and 3 to find mean, 4 to exit\n");
    fgets(in, BUF, stdin);
    choice = strtol(in, NULL, 10);
    switch(choice){
      case 1:
        printf("Enter a number now for factorial\n");
        fgets(in, BUF, stdin);
        int fac = strtol(in, NULL, 10);
        while(fac < 1){
           printf("Enter a number now for factorial\n");
           fgets(in, BUF, stdin);
           fac = strtol(in, NULL, 10);
        }
        printf("factorial %d is %ld\n", fac, fact(fac));
        break;
      case 2:
        printf("Enter a number now for prime check\n");
        fgets(in, BUF, stdin);
        int p = strtol(in, NULL, 10);
        while(p < 1){
          printf("Enter a number now for prime check\n");
          fgets(in, BUF, stdin);
          p = strtol(in, NULL, 10);
        }
        printf("%d %s a prime\n", p, prime(p) ? "is": "is not");
        break;
      case 3:
        mean();
        break;
      case 4:
        break;
      default:
        printf("Bad choice\n");
        break;
    }
  }
  return;
}

void game(void){
  char word[BUF] = {0};
  char letter = 0;
  char guessed[BUF] = {0};
  int countWrong = 0;
  int won = 0;
  printf("Enter the word to be guessed\n");
  fgets(word, BUF, stdin);
  word[strlen(word)-1] = 0;
  fillArray(strlen(word), guessed);
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  while(!won && countWrong < 6){
    printf("Enter your guess\n");
    letter = fgetc(stdin);
    getchar();
    countWrong += guess(word, letter, guessed);
    printf("Your guesses so far: %s\n", guessed);
    //draws my terrible hangman for the user
    draw(countWrong);
    if(!(strcmp(guessed, word)))
      ++won;
  }
  if(won)
    printf("Congratulations, you won!\n");
  else
    printf("Sorry, you lost\n");
  }

int guess(char word[], char letter, char guessed[]){
  int i = 0;
  int right = 0;
  for(i; i < strlen(word); ++i){
    if(word[i] == letter){
      ++right;
      guessed[i] = letter;
    }
  }

  if(right){
    printf("Letter %c is right\n", letter);
    return 0;
  } else{
    printf("Letter %c is wrong\n", letter);
    return 1;
  }
}

void draw(int countWrong){
  switch(countWrong){
    case 0:
      return;
    case 1:
      printf(" o\n");
      break;
    case 2:
      printf(" o\n");
      printf(" |\n");
      break;
    case 3:
      printf(" o\n");
      printf("\\|\n");
      break;
    case 4:
      printf(" o\n");
      printf("\\|/\n");
      break;
    case 5:
      printf(" o\n");
      printf("\\|/\n");
      printf("/\n");
      break;
    case 6:
      printf(" o\n");
      printf("\\|/\n");
      printf("/ \\ \n");
      break;
  }
}

void fillArray(int stringLength, char guessed[]){
  int i = 0;
  for(i; i < stringLength; ++i)
    guessed[i] = '*';
}

void reverse(){
  char in[BUF] = {0};
  char * rev;
  int i = 0;
  printf("Enter a string to be reversed\n");
  fgets(in, BUF, stdin);

  in[strlen(in) - 1] = 0;
  rev = malloc(strlen(in) * sizeof(char*));
  int k = strlen(in) - 1;
  for(i = 0; i < strlen(in); ++i){
    rev[k] = in[i];
    --k;
  }
  printf("%s\n", rev);
  free(rev);
  return;
}

void pali(){
  char in[BUF] = {0};
  int i = 0;
  int k = 0;
  printf("Enter a string to be palindromed\n");
  fgets(in, BUF, stdin);
  in[strlen(in) - 1] = 0;

  int flag = 1;
  for(i = 0, k = strlen(in) - 1; i <= k; ++i, --k){
    if(in[i] != in[k]){
      flag =0;
      break;
    }
  }
  if(flag)
    printf("%s is a palindrome\n", in);
  else
    printf("%s is not a palindrome\n", in);
  return;
}

void countC(){
  char in[BUF] = {0};
  char * unique = malloc(0);
  printf("Enter a string, the unique characters will be counted.\n");
  fgets(in, BUF, stdin);
  in[strlen(in) - 1] = 0;
  int size = 0;
  int i, j;
  unsigned short flag = 0;
  for(i = 0; i < strlen(in); ++i){
    flag = 1;
    for(j = 0; j < size; ++j){
      if(in[i] == unique[j])
        flag = 0;
    }
    if(flag){
      ++size;
      unique = realloc(unique, sizeof(int) * size);
      unique[size - 1] = in[i];
    }
  }
  printf("num of elements: %d\n", size);
  for(i = 0; i < size; ++i){
    printf("element %o: %c\n", i, unique[i]);
  }
  free(unique);
}

long fact(long num){
  return num == 1 ? 1 : num * fact(num - 1);
}

int prime(int num){
  int i = 0;
  for(i = 2; i <= sqrt(num); i++){
    if(num % i == 0)
      return 0;
  }
  return 1;
}

void mean(){
  int * arr = malloc(0);
  int size = 0;
  char in[BUF] = {0};
  int num = 0;
  int i = 0;
  int sum = 0;

  printf("Enter any number of numbers, 0 or anything else to quit\n");
  do{
    fgets(in, BUF, stdin);
    num = strtol(in, NULL, 10);
    if(num){
      ++size;
      arr = realloc(arr, sizeof(int) * size);
      arr[size - 1] = num;
    }
  }while(num);
  for(i = 0; i < size; i++){
    sum += arr[i];
  }
  free(arr);
  printf("The mean is %f, %d\n", (float)sum/(float)size, size);
  return;
}

