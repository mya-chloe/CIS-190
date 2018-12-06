/*Nathan Burdzel
 *Lab 8
 *Problem 1
 *11/7/18
 */

/*Preprocessor directives*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Defined constants*/
#define BUFFER 128
#define MIN_CHAR 65
#define MAX_CHAR 67
#define MIN_NUM_CHAR 49
#define MAX_NUM_CHAR 51


/*Function stubs*/
void printBoard(char board[][3]);
void xTurn(char board[][3], char userInput[]);
void oTurn(char board[][3], char userInput[]);
int checkWin();
int checkRows(char board [][3], int row, char c);
int checkCols(char board[][3], int row, int col, char c);
int checkDownDiags(char board[][3], int row, int col, char c);
int checkUpDiags(char board[][3], int row, int col, char c);
int checkRow(char row[], int col, char c);
void getInput(char board[][3], char userInput[], char c);

int main(void){
	
	/*Declare variables*/
	char board[3][3] = {{0}};
	char userInput[BUFFER] = {0};	

	/**/
	do{		
		/*Player playing as X's turn*/
		xTurn(board, userInput);
		/*Check to see if X won*/
		if(!checkWin(board))
			break;
		/*Player playing as O's turn*/
		oTurn(board, userInput);
	/*Check to see if O won*/	
	}while(checkWin(board));

	return 0;
}

/*Takes X's turn*/
void xTurn(char board[][3], char userInput[]){
	/*Show the user the board*/
	printf("The current board looks like:\n\n");	
	printBoard(board);
	/*Get the users input*/
	getInput(board, userInput, 'X');
}

/*Takes O's turn*/
void oTurn(char board[][3], char userInput[]){
	/*Show the user the board*/
	printf("The current board looks like:\n\n");	
	printBoard(board);
	/*Get the users input*/
	getInput(board, userInput, 'O');
}

/*Gets input from the user on where c should be placed and places it there*/
void getInput(char board[][3], char userInput[], char c){
	/*Get the choice from the user*/
	printf("Where would you like to go?\nThe rows are numbered A through C from top to bottom\nThe columns are numbered 1 to 3 from left to right\n");
	do{	
	fgets(userInput, BUFFER, stdin);
	/*Bad input print statments*/
	if(userInput[0] < MIN_CHAR || userInput[0] > MAX_CHAR)
		printf("Please enter a row between A and C:\n");
	if(userInput[1] < MIN_NUM_CHAR || userInput[1] > MAX_NUM_CHAR)
		printf("Please enter a column between 1 and 3:\n");
	else if(board[userInput[0] - MIN_CHAR][userInput[1] - MIN_NUM_CHAR])
		printf("Please choose an empty slot:\n");
	/*Keep looping until you get good input*/
	}while(board[userInput[0] - MIN_CHAR][userInput[1] - MIN_NUM_CHAR] || userInput[1] < MIN_NUM_CHAR || userInput[1] > MAX_NUM_CHAR || userInput[0] < MIN_CHAR || userInput[0] > MAX_CHAR);
	/*Set that position in the boarday to the character*/	
	board[userInput[0] - MIN_CHAR][userInput[1] - MIN_NUM_CHAR] = c;
}

/*Checks to see if someone won the game, if not return 1*/
int checkWin(char board[][3]){
	/*Checks to see if X won and prints a victory message*/	
	if(checkRows(board, 0, 'X') || checkCols(board, 0, 0, 'X') || checkUpDiags(board, 2, 0, 'X') || checkDownDiags(board, 0, 0, 'X')){	
		printf("X wins!\n");
		return 0;
	}	
	/*Checks to see if O won and prints a victory message*/
	if(checkRows(board, 0, 'O') || checkCols(board, 0, 0, 'O') || checkUpDiags(board, 2, 0, 'O') || checkDownDiags(board, 0, 0, 'O')){	
		printf("O wins!\n");
		return 0;
	}	
	return 1;	
}

/*Checks to see if there are three of char c in a row*/
int checkRows(char board [][3], int row, char c){
	/*Checks this row*/	
	if(checkRow(board[row], 0, c))		
		return 1;
	/*Else if this was the last row return false*/
	else if(row == 3)
		return 0;
	/*Check the next row*/
	else 
		checkRows(board, row + 1, c);
}

/*Checks to see if a row has all the same character*/
int checkRow(char row[], int col, char c){	
	/*If it matches the character*/	
	if(row[col] == c){
		/*If it was the last one return 1 otherwise check the next item in the row*/		
		if(col == 2)
			return 1;
		else 
			checkRow(row, col + 1, c);
	}
	/*Return false*/
	else
		return 0;
}

/*Checks for three c in a row in a column*/
int checkCols(char board[][3], int row, int col, char c){
	/*If there is a match*/	
	if(board[row][col] == c)
		/*If it is the third in a row return 1, otherwise check the rest of the column*/
		if(row == 2)
			return 1;
		else 
			checkCols(board, row + 1, col, c);
	/*If there are more columnts check the next one*/
	else if(col < 2)
		checkCols(board, 0, col + 1, c);
	/*If it was the last column return false*/	
	else
		return 0;
}

/*Checks for three in a row in the diagonal from top left to bottom right*/
int checkDownDiags(char board[][3], int row, int col, char c){	
	/*If there is a match*/	
	if(board[row][col] == c)
		/*If it is the third match return true, else check the next spot*/	
		if(col == 2)
			return 1;
		else 
			checkDownDiags(board, row + 1, col + 1, c);
	/*Otherwise return false*/	
	else
		return 0;
}


/*Checks for three in a row in the diagonal from top left to bottom right*/
int checkUpDiags(char board[][3], int row, int col, char c){	
	/*If there is a match*/	
	if(board[row][col] == c)
		/*If it is the third match return true, else check the next spot*/	
		if(col == 2)
			return 1;
		else 
			checkUpDiags(board, row - 1, col + 1, c);
	/*Otherwise return false*/	
	else
		return 0;
}

/*Prints the game board*/
void printBoard(char board[][3]){
	/*Declare variables*/	
	int i, j;	
	
	/*Print the board*/
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			/*If i, j is not 0 print out the character stored there, otherwise print out a blank*/
			printf("%c ", board[i][j] ? board[i][j] : '_');
		/*At the end of a line print out a new line character*/
		printf("\n");
	}
}
