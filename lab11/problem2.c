
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 25
#define BUFFER 256

typedef struct peg{
		char color[MAX_NAME_LEN];
    int sides;
    int pegNum;
	 	struct peg *next;
}PEG;

typedef struct hole{
    char color[MAX_NAME_LEN];
    int sides;
    int holeNum;
    struct hole *next;
}HOLE;

int main(void){

	PEG *pegList = malloc(sizeof(PEG));
  HOLE *holeList = malloc(sizeof(HOLE));
  int holeNum = 0;
  int pegNum = 0;
	char input[BUFFER];
	int choice;

	/*Add the users initial pegs*/
	do{
		printf("Enter 1 to add a peg, anything else to stop adding pegs");
		fgets(input, BUFFER, stdin);
		if(atoi(input) == 1){
			char inputColor[MAX_NAME_LEN];
			char userNumber[BUFFER];
			int inputNumber;
			printf("Please enter the color of the peg");
			fgets(inputColor, MAX_NAME_LEN, stdin);
			inputColor[strlen(inputColor) - 1] = '\0';
			do{
				printf("Please enter the number of sides, or 0 for a circle");
				fgets(userNumber, BUFFER, stdin);
			}while(checkInt(userNumber));
			inputNumber = atoi(userNumber);
			++pegNum;
			addPeg(pegList, inputColor, inputNumber, pegNum);
		}
	}while(atoi(input) == 1);

	/*Add the holes*/
	add all holes from a file to holeList
        ++holeNum;
        addHole(holeList, color to add, number of sides, holeNum)

	/*Continue getting the users input until they choose to quit*/
	do{
		printf("1: View all pegs with a certain color and number of sides\n");
		printf("2: Add a peg\n");
		printf("3: Remove a peg\n");
		printf("4: Write matching pegs and holes to a file\n");
		printf("5: Quit\n");
		printf("What option would you like to choose?\n");

		retrieve their choice

		switch(choice)
			case 1:
				char color[MAX_NAME_LEN];
				char input[BUFFER];
				printf("Please enter the color of the peg");
				fgets(color, MAX_NAME_LEN, stdin);
				color[strlen(color) - 1] = '\0';
				do{
					printf("Please enter the number of sides, or 0 for a circle");
					fgets(input, BUFFER, stdin);
				}while(checkInt(input));
				sides = atoi(input);
				printPeg(pegList, color, sides);
				break;
			case 2:
				retrieve color and num sides of peg to add
				++pegNum
				addPeg(pegList, name to add, num sides, pegNum)
				break;
			case 3:
                retrieve color and sides of peg to remove
				removePeg(pegList, name to remove, num of sides)
				break;
			case 4:
				retrieve name of file to write to
				printList(pegList, holeList, name of file)
				break;
			case 5:
				terminate program
	}while(choice != 5);
}

/*Prints all pegs that have a certain color andn number of sides*/
void printPeg(peg * pegList, char color[], int numSides){
	/*Declare local variables*/
	peg temp = pegList;
	int flag = 0;

	/*Go through all of the pegs*/
	while(temp != NULL){
		/*For every peg that is a match print out the information on it and throw the flag*/
		if(strcmp(temp.color, color) && temp.sides == numSides){
			printf("This peg is %s and has %d sides and is number %d", temp.color, temp.sides, temp.pegNum);
			flag = 1;
		}
		/*Go to the next item in the list*/
		temp = temp.next;
	}
	/*If the flag was not thrown print that no peg was found*/
	if(!flag)
		printf("There are no %s pegs with %d sides", color, numSides);
}

/*Adds a peg to the list of pegs*/
void addpeg(peg * pegList, char color[], int numSides, int pegNum){
    peg *temp = pegList;
    while(temp != null){
        temp = temp.next;
    }

		peg newPeg = malloc(sizeof(peg));
		newPeg.color = color;
		newPeg.sides = numSides;
		newPeg.pegNum = pegNum;

		newPeg.next = NULL;
		temp.next = newPeg;
}

/*Removes a peg with color and numSides from the list*/
void removepeg(peg * pegList, char color[], int numSides){
	/*Create pointers to pegs for removal operations*/
	peg *currentPeg = pegList;
	peg *previousPeg = NULL;

	/*Continue looping until the peg is found or the end of the list is reached*/
	while(currentPeg != NULL){
		/*If this peg is a match for the one to be removed*/
		if(strcmp(currentPeg.color, color) && currentPeg.sides == numSides){
			/*If this is the first peg change which peg pegList points to*/
			if(currentPeg == pegList)
				pegList = currentPeg.next;
			/*Otherwise make the previousPeg point to the peg after the peg being removed*/
			else
				previousPeg.next = currentPeg.next;
			/*Free the memory associated with the peg being removed*/
			free(currentPeg);

			/*Decrement the pegNumber for the remaining pegs*/
			previousPeg = previousPeg.next;
			while(previousPeg != NULL){
				previousPeg.pegNum--;
				previousPeg = previousPeg.next;
			}
			return;
		}
		/*Otherwise increment previousPeg and currentPeg*/
		previousPeg = currentPeg;
		currentPeg = currentPeg.next;
	}
}

/*Prints all matches to a file*/
void exportFile(peg *pegList, hole *holeList){
	/*Create a temporary peg and hole*/
	peg *tempPeg = pegList;
	hole *tempHole = holeList;

	/*Open a file for writing*/
	FILE *fp;
	fp = fopen("output.txt", "w");

	/*Go through both linked lists printing all matches to the file*/
	while(tempPeg != NULL){
      while(tempHole != NULL){
				/*If a match is found print it to the file*/
        if(strcmp(tempPeg.color, tempHole.color) && tempPeg.sides == tempHole.sides)
          fprintf(fp, "Peg %d matches with hole %d\n", tempPeg.pegNum, tempHole.holeNum);
				/*Move on to the next hole*/
        tempHole = tempHole.next;
      }
			/*Reset the list of holes to the beginning and move to the next peg*/
			tempHole = holeList;
      tempPeg = tempPeg.next;
    }
	}
	/*Close the file*/
	fclose(fp);
}
