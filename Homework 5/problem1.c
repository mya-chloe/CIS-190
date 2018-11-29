/*Nathan Burdzel
 *CIS 190
 *Homework 5
 *Problem 1
 *11/27/18
 *Notes: -Allows for any numbers to be used, starting at any number, ending at any number, and having any number of elements per letter
 *      Some functions are written a bit weird to accommodate for this fact
 *
 *      -In case you were not informed I got an extension from Professor Valova because I needed to reinstall my OS and lost all of my files on sunday.
 */


/**************************************Preprocessor directives*****************************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**************************************Defined constants*****************************************/
/*Defined constants for creating and accessing the game boards*/
#define NUMBER_OF_PLAYERS 3
#define NUMBER_OF_LETTERS 5
#define NUMBER_OF_NUMBERS_PER_LETTER 5

/*Constants for generating numbers*/
#define MAX_NUMBER 75
#define MIN_NUMBER 1
#define NUMBERS_PER_LETTER 15

/*Constants for user input*/
#define BUFFER 256

/**************************************Function stubs*****************************************/
void allocateMemory(int **** boards);
void freeMemory(int **** boards);
void swap(int * first, int * second);
int drawNumbers(int drawnNumbers[MAX_NUMBER - MIN_NUMBER + 1]);
void playGame(int *** boards, int *** played, int drawnNumbers[], char letters[], char input[]);
void playTurn(int *** boards, int *** played, int drawnNumbers[], char letters[], int turn, char input[]);
int checkWin(int *** played);
void markAsPlayed(int *** boards, int *** played, int value);
void fillBoards(int *** boards);
void fillBoard(int ** board);
void fillRow(int* row, int letter);
int checkBoards(int *** boards, int boardNumber, int ** board);
int checkBoard(int ** oldBoard, int ** newBoard);
int checkRow(int* oldRow, int* newRow);
int checkForValueInRow(int* row, int value, int currentIndex);
void printNumber(int number, char letters[]);
void printBoard(int *** boards, int *** played, int index, char letters[]);

/**************************************Main Method*****************************************/
int main(){
    /************Declare variables******************/
    /*The players game boards*/
    int *** boards;
    int *** played;
    int drawnNumbers[MAX_NUMBER - MIN_NUMBER + 1];
    char letters[NUMBER_OF_LETTERS] = {'B', 'I', 'N', 'G', 'O'};
    char input[BUFFER];

    /*Seed the rand function*/
    srand(time(0));

    /*Allocate memory for the boards*/
    allocateMemory(&boards);
    allocateMemory(&played);

    /*Draw the numbers to be used for each turn*/
    drawNumbers(drawnNumbers);

    /*Fill the players boards*/
    fillBoards(boards);

    /*Play the game*/
    playGame(boards, played, drawnNumbers, letters, input);

    /*Free the memory*/
    freeMemory(&boards);
    freeMemory(&played);

    return 0;
}

/**************************************Function Definitions*****************************************/

/*Allocates the memory for the three boards*/
void allocateMemory(int **** boards){
    /*Local variables*/
    int i, j;
    /*Allocate memory for the full 3 dimensional array*/
    (*boards) = malloc(sizeof(int **) * NUMBER_OF_PLAYERS);
    /*For each two dimensional array allocate it's memory*/
    for(i = 0; i < NUMBER_OF_PLAYERS; i++){
        /*Allocate the memory for the full two dimensional array*/
        (*boards)[i] = malloc(sizeof(int **) * NUMBER_OF_LETTERS);
        /*Allocate the memory for each one dimensional array*/
        for(j = 0; j < NUMBER_OF_LETTERS; j++){
            (*boards)[i][j] = malloc(sizeof(int *) * NUMBER_OF_NUMBERS_PER_LETTER);
        }
    }
}

/*Frees the memory*/
void freeMemory(int **** boards){
    /*Local variables*/
    int i, j;

    /*Free the memory*/
    /*Free each table row by row then the full table*/
    for(i = 0; i < NUMBER_OF_PLAYERS; i++){
        /*Free each row*/
        for(j = 0; j < NUMBER_OF_LETTERS; j++){
            /*Free the row*/
            free((*boards)[i][j]);
        }
        /*Free the full table*/
        free((*boards)[i]);
    }
    /*Free the full three dimensional aray*/
    free(*boards);
}

/*Swaps two ints using temp as auxillary storage*/
void swap(int * first, int * second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*Fills an array with every number to be drawn this game*/
int drawNumbers(int drawnNumbers[MAX_NUMBER - MIN_NUMBER + 1]){
    /*Local variables*/
    int i;

    /*Fill the array with the range of numbers without randomizing*/
    for(i = MIN_NUMBER; i < MAX_NUMBER + MIN_NUMBER; i++){
        drawnNumbers[i - MIN_NUMBER] = i;
    }

    /*Swap each element of the array with a random element*/
    for(i = 0; i < (MAX_NUMBER - MIN_NUMBER + 1); i++){
        swap(drawnNumbers + i, drawnNumbers + ((rand() % (MAX_NUMBER - MIN_NUMBER)) + MIN_NUMBER));
    }
}

/*Runs the game from start to finish*/
void playGame(int *** boards, int *** played, int drawnNumbers[], char letters[], char input[]){
    /*Local variables*/
    int turn = 0, test;

    /*While no player has won*/
    do{
        /*Run a single turn*/
        playTurn(boards, played, drawnNumbers, letters, turn, input);
        /*Increment the turn counter*/
        turn++;
    }while(!checkWin(played));
}

/*Runs each individual turn*/
void playTurn(int *** boards, int *** played, int drawnNumbers[], char letters[], int turn, char input[]){
    /*Declare local variables*/
    int test, inputValue;

    /*Tell the players what turn it is*/
    printf("Turn %d:\n", turn);

    /*Mark the new value in drawnNumbers as played*/
    markAsPlayed(boards, played, drawnNumbers[turn]);

    /*Report what number was drawn*/
    printNumber(drawnNumbers[turn], letters);
    printf(" was drawn\n");

    /*If a player has won the game*/
    if(test = checkWin(played)){
        /*Print that that player won*/
        printf("Player %d has won the game\n", test);
        /*And print their board*/
        printBoard(boards, played, test - 1, letters);
        /*Then return*/
        return;
    }

    /*Otherwise allow the user to print as many boards as they want*/
    do{
        /*Get user input*/
        printf("What would you like to do?\n1:View player 1's board\n2:View player 2's board\n3: View player 3's board\n4:View the drawn number again\n5:Move to the next turn\n");
        fgets(input, BUFFER, stdin);

        /*Perform the user requested operation*/
        switch(inputValue = atoi(input)){
            /*Print the board of player 1*/
            case 1:
                printBoard(boards, played, 0, letters);
                break;
            /*Print the board of player 2*/
            case 2:
                printBoard(boards, played, 1, letters);
                break;
            /*Print the board of player 3*/
            case 3:
                printBoard(boards, played, 2, letters);
                break;
            /*Print the drawn number*/
            case 4:
                printNumber(drawnNumbers[turn], letters);
                printf(" was drawn\n");
                break;
            /*Return to the main play game function*/
            case 5:
                return;
            /*Invalid input: print a statement and continue looping*/
            default:
                printf("Please choose one of the options");
        }
    }while(inputValue != 5);
}

/*Checks for a win, returns the players number + 1(so that if the first player wins it is still considered true)*/
int checkWin(int *** played){
    /*Declare local variables*/
    int player, letter, row;

    /*Check the rows for all players*/
    /*For each player*/
    for(player = 0; player < NUMBER_OF_PLAYERS; player++){
        /*For each letter*/
        for(letter = 0; letter < NUMBER_OF_LETTERS; letter++){
            /*For each number in the row*/
            for(row = 0; row < NUMBER_OF_NUMBERS_PER_LETTER; row++){
                /*If that number was not played this row is not a match, break*/
                if(!played[player][letter][row])
                    break;
                /*If this was the last element in the row return the player number + 1*/
                if(row == NUMBER_OF_NUMBERS_PER_LETTER - 1)
                    return player + 1;
            }
        }
    }

    /*Check the columns for all players*/
    /*For each player*/
    for(player = 0; player < NUMBER_OF_PLAYERS; player++){
        /*For each column*/
        for(row = 0; row < NUMBER_OF_NUMBERS_PER_LETTER; row++){
            /*For each row*/
            for(letter = 0; letter < NUMBER_OF_LETTERS; letter++){
                /*If that number was not played this column is not a match, break*/
                if(!played[player][letter][row])
                    break;
                /*If this was the last element in the column return the player number + 1*/
                if(letter == NUMBER_OF_LETTERS - 1)
                    return player + 1;
            }
        }
    }

    /*Check the downwards diagonal for all players*/
    /*For each player*/
    for(player = 0; player < NUMBER_OF_PLAYERS; player++){
        /*For each point on the diagonal*/
        for(row = 0; row < NUMBER_OF_NUMBERS_PER_LETTER && row < NUMBER_OF_LETTERS; row++){
                /*If that point has not been played this diagonal is not a match, break*/
                if(!played[player][row][row])
                    break;
                /*If this is the last element in the diagonal it is a match, return player number + 1*/
                if(row == NUMBER_OF_NUMBERS_PER_LETTER - 1)
                    return player + 1;
        }
    }

    /*Check the upwards diagonal for all players*/
    /*For each player*/
    for(player = 0; player < NUMBER_OF_PLAYERS; player++){
        /*For each point on the diagonal*/
        for(row = 0; row < NUMBER_OF_NUMBERS_PER_LETTER && row < NUMBER_OF_LETTERS; row++){
                /*If that point has not been played this diagonal is not a match, break*/
                if(!played[player][NUMBER_OF_LETTERS - row - 1][row])
                    break;
                /*If this is the last element in the diagonal it is a match, return player number + 1*/
                if(row == NUMBER_OF_NUMBERS_PER_LETTER - 1)
                    return player + 1;
        }
    }
    /*If none of these were a match the game was not won, return 0*/
    return 0;
}

/*Marks a value as played*/
void markAsPlayed(int *** boards, int *** played, int value){
    /*Local variables*/
    int i, index, row;

    /*Identify which row value would be in*/
    row = (value - MIN_NUMBER) / NUMBERS_PER_LETTER;

    /*For each player*/
    for (i = 0; i < NUMBER_OF_PLAYERS; i ++){
        /*Look for the value in the row*/
        index = checkForValueInRow(boards[i][row], value, NUMBER_OF_NUMBERS_PER_LETTER - 1) - 1;

        /*If the value was found*/
        if(index != -1)
            /*Set played at that index to be 1*/
            played[i][row][index] = 1;
    }
}

/*Randomly fill the boards*/
void fillBoards(int *** boards){
   /*Declare local variables*/
   int i;

   /*For each player add a unique board*/
   for(i = 0; i < NUMBER_OF_PLAYERS; i++){
       /*Continue looping as long as there are repeated boards*/
       do{
          /*Generate a new random board*/
          fillBoard(boards[i]);
       }while(checkBoards(boards, i, boards[i]));
    }
}

/*Randomly fill a single board*/
void fillBoard(int ** board){
    /*Declare local variables*/
    int i;

    /*Fill each row in board*/
    for(i = 0; i < NUMBER_OF_LETTERS; i++){
        fillRow(board[i], i);
    }
}

/*Randomly fills a row of an array with numbers in the proper range*/
void fillRow(int* row, int letter){
    /*Declare local variables*/
    int i, random;

    /*For each element in the row*/
    for(i = 0; i < NUMBER_OF_NUMBERS_PER_LETTER; i++){
        /*Looping until a value is chosen which does not already exist in the array*/
        do{
            /*Generate a random value*/
            random = rand() % (NUMBERS_PER_LETTER) + 1 + (letter * NUMBERS_PER_LETTER);
        }while(checkForValueInRow(row, random, i));
        /*When a value is found that was not already added, add it*/
        row[i] = random;
    }

}

/*Check that no two boards are a match, returns 1 if they are perfect matches and 0 if they are not a perfect match*/
int checkBoards(int *** boards, int boardNumber, int ** board){
    /*Declare local variables*/
    int i;

    /*For every board filled so far*/
    for(i = 0; i < boardNumber; i++){
        /*If an already filled board is a match for board return 1*/
        if(!checkBoard(boards[i], board))
            return 1;
    }
    /*Otherwise return 0*/
    return 0;
}

/*Checks to see if two boards are an exact match, return 0 if the boards are perfect matches and 1 if they are not perfect matches*/
int checkBoard(int ** oldBoard, int ** newBoard){
    /*Declare local variables*/
    int i;

    /*For every row in each board*/
    for(i = 0; i < NUMBER_OF_LETTERS; i++){
        /*If a row is not a match return 1*/
        if(checkRow(oldBoard[i], newBoard[i]))
            return 1;
    }
    /*If every row is a match return 0*/
    return 0;
}

/*Checks to see if two rows are an exact match, return 0 if the rows are perfect matches and 1 if they are not perfect matches*/
int checkRow(int* oldRow, int* newRow){
    /*Declare local variables*/
    int i;

    /*For each value in both arrays*/
    for(i = 0; i < NUMBERS_PER_LETTER; i ++){
        /*If the elements are not a match return 1*/
        if(oldRow[i] != newRow[i])
            return 1;
    }
    /*If every element is a match return 0*/
    return 0;
}

/*Checks to see if a value alread exists in a row of a table*/
int checkForValueInRow(int* row, int value, int currentIndex){
    /*Declare local variables*/
    int i;

    /*For each i*/
    for(i = 0; i < currentIndex; i++){
        /*If value is a match with i return i + 1*/
        if(row[i] == value)
            return i + 1;
    }
    /*If no value was a match for i return 0*/
    return 0;
}

/*Prints a number with it's letter prefix*/
void printNumber(int number, char letters[]){
    printf("%c%d", letters[(number - MIN_NUMBER) / NUMBERS_PER_LETTER], number);
}

/*Print a players board*/
void printBoard(int *** boards, int *** played, int index, char letters[]){
    /*Declare local variables*/
    int i, j;

    /*Print out explanation statement*/
    printf("Here is the current board for Player %d\n", index + 1);
    printf("A number in parantheses means that it has already been played\n");

    /*Print each row in the array*/
    for(i = 0; i < NUMBER_OF_LETTERS; i++){
        /*Print the corresponiding letter*/
        printf("%c\t", letters[i]);
        /*Print all the elements in that row*/
        for(j = 0; j < NUMBER_OF_NUMBERS_PER_LETTER; j++){
            /*If it has been played print it in parantheses*/
            if(played[index][i][j])
                printf("(%d)\t", boards[index][i][j]);
            /*Otherwise print it by itself*/
            else
                printf("%d\t ", boards[index][i][j]);
        }
        printf("\n");
    }
}
