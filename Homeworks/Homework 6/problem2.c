/*Nathan Burdzel
 *11/28/18
 *Homework 6
 *Problem 2
 *Beer Inventory
 *Keeps track of the inventory of a beer company using a linked list
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
void makeOrder(Beer *firstBeer, int *orderedBeers, int numberOfBeers);
int checkIfEmpty(int *orderedBeers, int numberOfBeers);
int checkInt(char input[]);
int checkID(char input[]);
void printOrder(Beer *firstBeer, int numberOfBeers, int *orderedBeers);
Beer *findBeerByID(long id, Beer *firstBeer, int *beerIDIndex);
void searchBeerByID(char input[], Beer *firstBeer, int numberOfBeers);

/*Main method*/
int main(void){
	/*Declare variables*/
	int i, numberOfBeers;
	char input[BUFFER];
	FILE *fp;

  /*Initialize Beer linked list*/
	Beer *firstBeer;

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

/*Loads from file filepath to the linked list of beers*/
int loadFile(FILE *filePath, Beer **firstBeer, char input[BUFFER]){
	/*Declare local variables*/
	int numberOfBeers, i;

	/*Retrieve the number of beers from the file*/
	fgets(input, BUFFER, filePath);
	numberOfBeers = atoi(input);

	/*Create a pointer to a beer to traverse the list*/
  Beer *trav;

	/*Fill the linked list*/
	for(i = 0; i < numberOfBeers; i++){
		/*If this is the first beer*/
		if(!i){
			/*Create the new beer directly at head*/
			*firstBeer = malloc(sizeof(Beer));

			/*Get the name*/
			fgets(input, BUFFER, filePath);
			/*Strip the newline*/
			input[strlen(input) - 1] = 0;
			/*Copy it into (*firstBeer)[i].name*/
			strcpy((*firstBeer)->name, input);

			/*Get the id of the beer and set id to this id*/
			fgets(input, BUFFER, filePath);
			(*firstBeer)->id = atol(input);

			/*Get the rating and set the beers rating to it*/
			fgets(input, BUFFER, filePath);
			(*firstBeer)->quantity = atoi(input);

			/*Get the releaseDate and set the beers rating to it*/
			fgets(input, BUFFER, filePath);
			(*firstBeer)->price = atof(input);

			/*Set the next pointer to point to null*/
			(*firstBeer)->next = NULL;
			/*Move on to the next beer*/
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
		newBeer->id = atol(input);

		/*Get the rating and set the beers rating to it*/
		fgets(input, BUFFER, filePath);
		newBeer->quantity = atoi(input);

		/*Get the releaseDate and set the beers rating to it*/
		fgets(input, BUFFER, filePath);
		newBeer->price = atof(input);

		/*Add newBeer to the point where it should be added when sorted by price order*/
		/*Set trav to the beginning of the list*/
		trav = *firstBeer;
		/*Keep going until you have reached the last node or the next price is greater than the price of the newBeer*/
		while(trav->next != NULL && trav->price < newBeer->price && trav->next->price < newBeer->price){
		    trav = trav->next;
		}
		/*If it should be inserted at the start of the list add it to the start of the list*/
	    if(trav == *firstBeer && trav->price >= newBeer->price){
	        newBeer->next = *firstBeer;
	        *firstBeer = newBeer;
	    }

    	/*if it should be inserted after trav insert it after trav*/
    	else{
    		newBeer->next = trav->next;
    	    trav->next = newBeer;
    	}
	}
	/*Return the number of beers for use in other functions*/
	return numberOfBeers;
}

/*Frees the memory*/
void freeMemory(Beer **firstBeer){
	/*Declare local variables*/
	Beer *tempBeer;

	/*Delete all the beers*/
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

	/*Create a temporary pointer to beers for traversing through the list*/
  	Beer *temp = firstBeer;

	/*While there are still more beers print the current beer*/
	while(temp != NULL){
		printBeer(*temp);
		temp = temp->next;
	}
}

/*Prints the information on a single beer*/
void printBeer(Beer aBeer){
	printf("The name of this beer is: %s\n", aBeer.name);
	printf("This beer has an id of: %07ld\n", aBeer.id);
	printf("This beer has %d units in stock\n", aBeer.quantity);
	printf("This beer has a cost of $%.2lf\n\n", aBeer.price);
}

/*Allows the user to make as many choices as they want*/
void menu(char input[], Beer *firstBeer, int numberOfBeers){
	/*Declare local variables*/
	int test = 0;
	while(test != 4){
		/*Print out a menu for the user*/
		printf("What would you like to do?\n1: Search for a beer by it's ID number\n2: View information on all beers ordered by price\n3: Place an order\n4: Quit the program\n");

		/*Get user input*/
		fgets(input, BUFFER, stdin);

		/*Perform the requested operation*/
		switch (test = atoi(input)){
			/*If the user wanted to search for a beer call findBeerByID then break*/
			case 1:
				searchBeerByID(input, firstBeer, numberOfBeers);
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
	int beerIDIndex;
	int firstOrder = 1;
	int i;
  	Beer *temp;

	/*Zero out orderedBeers*/
	for(i = 0; i < numberOfBeers; i++){
		orderedBeers[i] = 0;
	}

	/*Continue looping as long as the user wants to add more beer to their order*/
	while(finished == 1){
		/*If this is not the first order find out if the user wants another item*/
		if(!firstOrder){
			printf("Please enter 1 to get another item or anything else to finish your order:\n");
			fgets(input, BUFFER, stdin);
			finished = atoi(input);
		}
		/*If this is the first order you already know they want to add a beer*/
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
					/*Assign temp to the Beer pointer returned by findBeerByID*/
					temp = findBeerByID(atol(input), firstBeer, &beerIDIndex);
					/*If temp is not NULL the beer was found*/
					if(temp != NULL){
						/*If the beer is in stock*/
						if(temp->quantity > 0){
							/*Give the user information on the beer*/
							printf("This beer costs $%.2lf per unit and has %d units remaining\n", temp->price, temp->quantity);
							printf("Please enter the number of beers you would like to order\nEnter a number less than one to remove this beer from your order\n");
							/*Get input from the user verifying that it is an integer*/
							do{
								fgets(input, BUFFER, stdin);
								/*If it is not an integer print out a correction statement*/
								if(integerTest = (checkInt(input)))
									printf("Please enter an integer number\n");
							}while(integerTest);

							/*Convert input to an int*/
							quantity = atoi(input);

							/*If the user chose a quantity greater than 0 make an order*/
							if(quantity > 0){
								/*If there is enough stock left to fill the order*/
								if(temp->quantity >= quantity){
									/*Add this beer to the array of ordered beers*/
									orderedBeers[beerIDIndex] = atoi(input);
								}
								/*If the user wants more than the remaining stock allow them to choose whether they want all the remaining stock or none of it*/
								else{
									printf("We only have %d units of that beer left in stock. Please enter 1 to order all remaining units or anything else to not order this type of beer", temp->quantity);
									fgets(input, BUFFER, stdin);
									if(atoi(input) == 1)
										orderedBeers[beerIDIndex] = temp->quantity;
								}
							/*If the user chose to remove the beer remove it from orderedBeers*/
							}else{
								printf("This beer has been removed from your order\n");
								orderedBeers[beerIDIndex] = 0;
							}
						/*If the beer is out of stoc inform the user*/
						}else{
							printf("%s is out of stock\n", temp->name);
						}
					/*Inform the user if no beer with that ID is in stock*/
					}else{
						printf("We do not have any beer with the entered index\n");
					}
				}
				/*Tell the user how to enter a valid ID*/
				else{
					printf("Please enter a seven digit id\n");
				}
			/*Continue looping until the beer is found*/
			}while(!beerIDIndex);
		}
		/*If the user doesn't want to add more beer get an order confirmation*/
		else{
			/*If the list is empty do not allow the user to check out*/
			if(checkIfEmpty(orderedBeers, numberOfBeers)){
				/*Get input from user on whether to add an item or cancel*/
				printf("You have no beers in your order\nPlease enter one to add an item or anything else to cancel your order\n");
				fgets(input, BUFFER, stdin);

				/*If they want to add some items do not retrun to the menu*/
				if(atoi(input) == 1){
					finished = 1;
				}

				/*If they want to cancel their order return to the menu*/
				else{
					finished = 0;
				}
			}
			/*Otherwise get the order confirmation*/
			else{
				/*Print out their current invoice*/
				printf("Here is your current order:\n");
				printOrder(firstBeer, numberOfBeers, orderedBeers);
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

	/*Create a temporary pointer to the linked list*/
  	Beer *temp = firstBeer;

	/*Remove the requested beers from their quantities*/
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
	if(strlen(input) != 7){
		return 0;
	}
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
Beer * findBeerByID(long id, Beer *firstBeer, int *beerIDIndex){
	/*Declare local variables*/
	int i = 0;

	/*Create a temporary pointer to the list of beers*/
	Beer *temp = firstBeer;

	/*Find the beer with that id or a NULL beer*/
	while(temp != NULL && temp->id != id){
    	temp = temp->next;
		i++;
  	}

	/*Set beerIDIndex to be the number of beers searched through and return the current temp*/
  *beerIDIndex = i;
  return temp;
}

/*Gets information on a beer and prints out information on it*/
void searchBeerByID(char input[], Beer *firstBeer, int numberOfBeers){
	/*Declare local variables*/
	int test;

	/*Create a temporary beer for traversing the list*/
 	Beer *temp;

	/*Get user input*/
	do{
		printf("Please enter a beer ID number\n");
		fgets(input, BUFFER, stdin);
		input[strlen(input) - 1] = '\0';
		if(test = !checkID(input))
			printf("Please enter a seven digit ID\n");
	}while(test);

	/*Find the beer with that id*/
  	temp = findBeerByID(atol(input), firstBeer, &numberOfBeers);
	/*If temp is not null print the information on it*/
	if(temp != NULL)
		printBeer(*temp);
	/*If no beer was found with that ID inform the user*/
	else{
		printf("We do not have any beers with that ID number\n");
	}

}
