/*Nathan Burdzel
 *11/28/18
 *Homework 6
 *Problem 1
 *Beer Inventory
 *Keeps track of the inventory of a beer company using an array of structures
 */

/*Preprocessor directives*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Defined constants*/
#define BUFFER 256

/*Integer checking constants*/
#define MINUS 45
#define MIN_INT 48
#define MAX_INT 57

/*Structures*/
typedef struct beer{
	char name[BUFFER];
	long id;
	int quantity;
	double price;
  struct beer * next;
}Beer;

/*Function stubs*/
int loadFile(FILE *filePath, Beer **firstBeer, char input[BUFFER]);
void freeMemory(Beer **firstBeer);
void printAllBeers(Beer *firstBeer);
void printBeer(Beer beer);
void menu(char input[], Beer *firstBeer, int numberOfBeers);
void takeOrder(char input[], Beer *firstBeer, int numberOfBeers);
void makeOrder(Beer *firstBeer, int *orderedBeers);
int checkIfEmpty(int *orderedBeers);
int checkInt(char input[]);
int checkID(char input[]);
void printOrder(Beer *firstBeer, int *orderedBeers);
Beer *findBeerByID(long id, Beer *firstBeer);
void searchBeerByID(char input[], Beer *firstBeer);

int main(void){
	/*Declare variables*/
	int i, numberOfBeers;
	char input[BUFFER];
	FILE *fp;

  /*Initialize the array of beers*/
	Beer *firstBeer = malloc(0);

	/*Open the file*/
	fp = fopen("beer.dat", "r");

  /*Load the file*/
	numberOfBeers = loadFile(fp, &firstBeer, input);

	/*Close the file*/
	fclose(fp);

	/*Run the menu*/
	menu(input, firstBeer, numberOfBeers);

	/*Free the memory*/
	freeMemory(&firstBeer);
}

/*Loads from file filepath to the array of structures beers*/
int loadFile(FILE *filePath, Beer *firstBeer, char input[BUFFER]){
	/*Declare local variables*/
	int numberOfBeers, i;

	/*Retrieve the number of beers from the file*/
	fgets(input, BUFFER, filePath);
	numberOfBeers = atoi(input);

  Beer *trav;

	/*Fill the structure array*/
	for(i = 0; i < numberOfBeers; i++){
    /*If this is the first beer*/
    if(!i){
      /*Create the new beer directly at head*/
      Beer *newBeer = malloc(sizeof(Beer));
  		/*Get the name*/
  		fgets(input, BUFFER, filePath);
  		/*Strip the newline*/
  		input[strlen(input) - 1] = 0;
  		/*Copy it into (*firstBeer)[i].name*/
  		strcpy(firstBeer->name, input);

      /*Get the id of the beer and set id to this id*/
  		fgets(input, BUFFER, filePath);
  		firstBeer->id = atol(input);

  		/*Get the rating and set the beers rating to it*/
  		fgets(input, BUFFER, filePath);
  		firstBeer->quantity = atoi(input);

  		/*Get the releaseDate and set the beers rating to it*/
  		fgets(input, BUFFER, filePath);
  		firstBeer->price = atof(input);
      firstBeer->next = NULL;
      continue;
    }

    /*Create the new beer*/
    Beer *newBeer = malloc(sizeof(Beer));
		/*Get the name*/
		fgets(input, BUFFER, filePath);
		/*Strip the newline*/
		input[strlen(input) - 1] = 0;
		/*Copy it into (*firstBeer)[i].name*/
		strcpy(newBeer->name, input);

		/*Get the id of the beer and set id to this id*/
		fgets(input, BUFFER, filePath);
		newBeer.id = atol(input);

		/*Get the rating and set the beers rating to it*/
		fgets(input, BUFFER, filePath);
		newBeer.quantity = atoi(input);

		/*Get the releaseDate and set the beers rating to it*/
		fgets(input, BUFFER, filePath);
		newBeer.price = atof(input);


    /*set trav to the beginning of the list*/
    trav = firstBeer;
    /*Keep going until the point the new node should be inserted is reached*/
    while(trav->next != NULL && trav->next->price < newBeer->price){
      trav = trav->next;
    }

    /*Add the beer to the list*/
    newBeer->next = trav->next;
    trav->next = newBeer;

	}

	/*Return the number of beers for use in iterating through the full array*/
	return numberOfBeers;
}

/*Frees the memory*/
void freeMemory(Beer **firstBeer){
	/*Declare local variables*/
	Beer *tempBeer;
	/*Delete all the pegs*/
	while(*firstBeer != NULL){
		tempBeer = *firstBeer;
		*firstBeer = (*firstBeer)->next;
		free(tempBeer);
	}
	/*Free the head node*/
	free(*firstBeer);

}

/*Prints information on every beer*/
void printAllBeers(Beer *firstBeer){
	/*Declare local variables*/
	int i;

  Beer *temp = firstBeer;

	/*While there are still more beers print the current beer*/
	while(temp != NULL)){
		printBeer(*temp);
	}
}

/*Prints the information on a single beer*/
void printBeer(Beer aBeer){
	printf("The name of this beer is: %s\n", aBeer.name);
	printf("This beer has an id of: %07ld\n", aBeer.id);
	printf("This beer has %d units in stock\n", aBeer.quantity);
	printf("This beer has a cost of $%.2lf\n\n", aBeer.price);
}

void menu(char input[], Beer *firstBeer, int numberOfBeers){
	/*Declare local variables*/
	int test = 0;
	while(test != 4){
		/*Print out a menu for the user*/
		printf("\nWhat would you like to do?\n1: Search for a beer by it's ID number\n2: View information on all beers ordered by price\n3: Place an order\n4: Quit the program\n");

		/*Get user input*/
		fgets(input, BUFFER, stdin);

		/*Perform the requested operation*/
		switch (test = atoi(input)){
			/*If the user wanted to search for a beer call findBeerByID then break*/
			case 1:
				searchBeerByID(input, firstBeer);
				break;

			/*If the user wanted to find information on all beers sort the array then print information on all the beers*/
			case 2:
				printAllBeers(firstBeer);
				break;

			/*If the user wanted to place an order call makeOrder*/
			case 3:
				takeOrder(input, firstBeer, numberOfBeers);
				break;

			/*If the user chose to quit do nothing*/
			case 4:
				break;

			/*If the user entered bad input then print out a correction mesage*/
			default:
				printf("Please enter an integer between 1 and 4");
				break;
		}
	}
}

/*Gets an order from the user*/
void takeOrder(char input[], Beer *firstBeer, int numberOfBeers){
	/*Declare local variables*/
	int orderedBeers[numberOfBeers];
	int finished = 1;
	int quantity = 0;
	int integerTest = 1;
	long beerIDIndex;
	int firstOrder = 1;
	int i;
  Beer *temp;

	/*Zero out orderedBeers*/
	for(i = 0; i < numberOfBeers; i++){
		orderedBeers[i] = 0;
	}

	/*Continue looping as long as the user wants to add more beer to their order*/
	while(finished == 1){
		/*If this is not the first order get find out if the user wants another item*/
		if(!firstOrder){
			printf("Please enter 1 to get another item or anything else to finish your order:\n");
			fgets(input, BUFFER, stdin);
			finished = atoi(input);
		}
		else{
			firstOrder = 0;
			finished = 1;
		}
		/*If the user wanted to add a beer*/
		if(finished == 1){
			/*Keep on attempting to add beer until the user asks for a valid beer to be added*/
			do{
				/*Get user input and strip the newline character*/
				printf("Please enter the ID of the beer you would like to order,\nEnter the id of a beer you already added to your order to change your order\n");
				fgets(input, BUFFER, stdin);
				input[strlen(input) - 1] = 0;

				/*If the user entered an integer try and add the beer by ID*/
				if(checkID(input)){
					temp = findBeerByID(atol(input), firstBeer, &beerIDIndex);
					if(temp != NULL){
						if(temp->quantity > 0){
							printf("This beer costs $%.2lf per unit and has %d units remaining\n", beers[beerIDIndex - 1].price, beers[beerIDIndex - 1].quantity);
							printf("Please enter the number of beers you would like to order\nEnter a number less than one to remove this beer from your order\n");
							/*Get input from the user verifying that it is an integer*/
							do{
								fgets(input, BUFFER, stdin);
								/*If it is not an integer print out a correction statement*/
								if(integerTest = (checkInt(input)))
									printf("Please enter an integer number\n");
							}while(integerTest);

							quantity = atoi(input);

							if(quantity > 0){
								/*If there is enough stock left to fill the order*/
								if(temp->quantity >= quantity){
									/*Add this beer to the array of ordered beers*/
									orderedBeers[beerIDIndex - 1] = atoi(input);
								}else{
									printf("We only have %d units of that beer left in stock. Please enter 1 to order all remaining units or anything else to not order this type of beer", beers[beerIDIndex - 1].quantity);
									fgets(input, BUFFER, stdin);
									if(atoi(input) == 1)
										orderedBeers[beerIDIndex - 1] = temp->quantity;
								}
							}else{
								printf("This beer has been removed from your order\n");
								orderedBeers[beerIDIndex - 1] = 0;
							}
						}else{
							printf("%s is out of stock\n", temp->name);
						}
					}else{
						printf("We do not have any beer with the entered index");
					}
				}
				else{
					printf("Please enter a seven digit id");
				}
			}while(!beerIDIndex);
		}
		/*If the user doesn't want to add more beer get an order confirmation*/
		else{
			/*If the list is empty do not allow the user to check out*/
			if(checkIfEmpty(orderedBeers, numberOfBeers)){
				printf("You have no beers in your order\n");
				finished = 1;
			}
			/*Otherwise get the order confirmation*/
			else{
				/*Print out their current invoice*/
				printf("Here is your current order:\n");
				printOrder(beers, numberOfBeers, orderedBeers);
				/*Get confirmation on the order*/
				printf("Please enter 1 to confirm your order or anything else to edit your order:\n");
				fgets(input, BUFFER, stdin);
				/*If the order is confirmed make the order*/
				if(atoi(input) == 1){
					printf("Order confirmed");
					makeOrder(firstBeer, orderedBeers, numberOfBeers);
				}
				/*Otherwise ensure the loops will continue*/
				else{
					finished = 1;
				}
			}
		}
	}
}

/*Return 1 if the array is empty, or 0 if it isn't*/
int checkIfEmpty(int orderedBeers[], int numberOfBeers){
	/*declare local variables*/
	int i;

	/*If any element is nonzero return 0*/
	for(i = 0; i < numberOfBeers; i++)
		if(orderedBeers[i])
			return 0;

	/*If no elements were nonzero return 1*/
	return 1;
}


/*Removes the ordered beers from the inventory*/
void makeOrder(Beer *firstBeer, int orderedBeers[], int numberOfBeers){
	/*Declare local variables*/
	int i;

  Beer *temp = firstBeer;

	/*Remove the beers*/
	for(i = 0; i < numberOfBeers; i++){
		temp->quantity -=orderedBeers[i];
    temp = temp->next;
	}
}

/*Checks if input is an int*/
int checkInt(char input[]){
	int i;
	/*If the first character isn't a number or the minus sign return 0*/
	if((input[0] < MIN_INT || input[0] > MAX_INT) && input[0] != MINUS)
		return 0;
	/*If there is more than a minus sign return 0*/
	else if(input[0] == MINUS)
		if(strlen(input) == 1)
			return 0;
	/*If any character isn't a valid int return 0*/
	for(i = 1; i < strlen(input); i++){
		if(input[i] < MIN_INT || input[i] > MAX_INT)
			return 0;
	}
	/*Otherwise return 1*/
	return 1;
}

/*Checks if input is a valid beer id*/
int checkID(char input[]){
	int i;
	if(strlen(input) != 7)
		return 0;
	/*If any character isn't a valid int return 0*/
	for(i = 1; i < strlen(input); i++){
		if(input[i] < MIN_INT || input[i] > MAX_INT)
			return 0;
	}
	/*Otherwise return 1*/
	return 1;
}

/*Prints an invoice*/
void printOrder(Beer *firstBeer, int numberOfBeers, int orderedBeers[]){
	/*Declare local variables*/
	int i;
	double runningTotal;
  Beer *temp = firstBeer;

	/*Prints out a header for the invoice*/
	printf("Beer\t\tQuantity Ordered\tPrice Per Unit\t\tSubtotal\n");

	/*Print out each beers information*/
	for(i = 0; i < numberOfBeers; i++){
		if(orderedBeers[i]){
			printf("%07ld\t\t%d\t\t\t%.2lf\t\t\t%.2lf\n", temp->id, orderedBeers[i], temp->price, orderedBeers[i] * temp->price);
			runningTotal += orderedBeers[i] * temp->price;
		}
    temp = temp->next;
	}
	/*Print out the total*/
	printf("\t\t\t\t\t\t\t\tTotal\n");
	printf("\t\t\t\t\t\t\t\t%.2lf\n", runningTotal);
}

/*Returns the index location of a beer in the array of beers + 1 or 0 if no beer with that id exists*/
Beer * findBeerByID(long id, Beer *firstBeer, int numberOfBeers){
	/*Declare local variables*/
	int i;

	Beer *temp = firstBeer;

  while(temp != NULL && temp->id != id){
    temp = temp->next;
  }
  return temp;
}

void searchBeerByID(char input[], Beer *firstBeer, int numberOfBeers){
	/*Declare local variables*/
	int test;

  Beer *temp;

	/*Get user input*/
	do{
		printf("Please enter a beer ID number\n");
		fgets(input, BUFFER, stdin);
		if(test = checkInt(input))
			printf("Please enter an integer number");
	}while(test);

  temp = findBeerByID(atol(input), beers, numberOfBeers);
	if(temp != NULL)
		printBeer(*temp);
	else{
		printf("We do not have any beers with that ID number");
	}

}
