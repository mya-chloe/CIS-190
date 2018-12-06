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
}Beer;

/*Function stubs*/
int loadFile(FILE *filePath, Beer **beers, char input[BUFFER]);
void freeMemory(Beer **beers);
void printAllBeers(Beer *beers, int numberOfBeers);
void printBeer(Beer beer);
void selectionSort(Beer * beers, int sorted, int numberOfBeers);
int findSmallest(Beer *beers, int sorted, int numberOfBeers);
void swap(Beer *first, Beer *second);
void menu(char input[], Beer *beers, int numberOfBeers);
void takeOrder(char input[], Beer *beers, int numberOfBeers);
void makeOrder(Beer *beers, int orderedBeers[], int numberOfBeers);
int checkIfEmpty(int orderedBeers[], int numberOfBeers);
int checkInt(char input[]);
int checkID(char input[]);
void printOrder(Beer *beers, int numberOfBeers, int orderedBeers[]);
int findBeerByID(long id, Beer *beers, int numberOfBeers);
void searchBeerByID(char input[], Beer *beers, int numberOfBeers);

int main(void){
	/*Declare variables*/
	int i;
	char input[BUFFER];
	FILE *fp;
	int numberOfBeers;

  /*Initialize the array of beers*/
	Beer *beers = malloc(0);

	/*Open the file*/
	fp = fopen("beer.dat", "r");

    /*Load the file*/
	numberOfBeers = loadFile(fp, &beers, input);

	/*Close the file*/
	fclose(fp);

	/*Run the menu*/
	menu(input, beers, numberOfBeers);

	/*Free the memory*/
	freeMemory(&beers);
}

/*Loads from file filepath to the array of structures beers*/
int loadFile(FILE *filePath, Beer **beers, char input[BUFFER]){
	/*Declare local variables*/
	int numberOfBeers, i;

	/*Retrieve the number of beers from the file*/
	fgets(input, BUFFER, filePath);
	numberOfBeers = atoi(input);

	/*Allocate the right amount of memory*/
	(*beers) = realloc((*beers), sizeof(Beer) * numberOfBeers);

	/*Fill the structure array*/
	for(i = 0; i < numberOfBeers; i++){
		/*Get and copy the name of the beer*/
		/*Get the name*/
		fgets(input, BUFFER, filePath);
		/*Strip the newline*/
		input[strlen(input) - 1] = 0;
		/*Copy it into (*beers)[i].name*/
		strcpy((*beers)[i].name, input);

		/*Get the id of the beer and set id to this id*/
		fgets(input, BUFFER, filePath);
		(*beers)[i].id = atol(input);

		/*Get the rating and set the beers rating to it*/
		fgets(input, BUFFER, filePath);
		(*beers)[i].quantity = atoi(input);

		/*Get the releaseDate and set the beers rating to it*/
		fgets(input, BUFFER, filePath);
		(*beers)[i].price = atof(input);
	}

	/*Return the number of beers for use in iterating through the full array*/
	return numberOfBeers;
}

/*Frees the memory*/
void freeMemory(Beer **beers){
	/*Free the whole array*/
	free((*beers));
}

/*Prints information on every beer*/
void printAllBeers(Beer *beers, int numberOfBeers){
	/*Declare local variables*/
	int i;

	/*While there are still more beers print the current beer*/
	for(i = 0; i < numberOfBeers; i++){
		printBeer(beers[i]);
	}
}

/*Prints the information on a single beer*/
void printBeer(Beer aBeer){
	printf("The name of this beer is: %s\n", aBeer.name);
	printf("This beer has an id of: %07ld\n", aBeer.id);
	printf("This beer has %d units in stock\n", aBeer.quantity);
	printf("This beer has a cost of $%.2lf\n\n", aBeer.price);
}

/*Recurssive implementation of a selection sort*/
void selectionSort(Beer * beers, int sorted, int numberOfBeers){
    /*Base case: The remaining elements to be sorted have a length of 1 or less*/
    if(sorted == (numberOfBeers - 1))
        return;

		printf("%d%d", sorted, findSmallest(beers, sorted, numberOfBeers));
    /*Swap the smallest number with the first index that still needs to be sorted*/
    swap(beers + sorted, beers + findSmallest(beers, sorted, numberOfBeers));

    /*Sort the rest of the array*/
    selectionSort(beers, sorted + 1, numberOfBeers);
}

/*Finds the index of the beer with the smallest price*/
int findSmallest(Beer *beers, int sorted, int numberOfBeers){
    /*Declare local variables*/
    int i, currentSmallest = sorted;

    /*Loop through the remaining beers looking for the smallest price*/
    for(i = sorted; i < numberOfBeers; i++)
        if(beers[i].price < beers[currentSmallest].price)
            currentSmallest = i;

    /*Return the index of the beer with the smallest price*/
    return currentSmallest;
}

/*Swaps the positions of first and second using tempBeer for temporary storage*/
void swap(Beer *first, Beer *second){
     Beer tempBeer = *second;
     *second = *first;
     *first = tempBeer;
}

void menu(char input[], Beer *beers, int numberOfBeers){
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
				searchBeerByID(input, beers, numberOfBeers);
				break;

			/*If the user wanted to find information on all beers sort the array then print information on all the beers*/
			case 2:
				selectionSort(beers, 0, numberOfBeers);
				printAllBeers(beers, numberOfBeers);
				break;

			/*If the user wanted to place an order call makeOrder*/
			case 3:
				takeOrder(input, beers, numberOfBeers);
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
void takeOrder(char input[], Beer *beers, int numberOfBeers){
	/*Declare local variables*/
	int orderedBeers[numberOfBeers];
	int finished = 1;
	int quantity = 0;
	int integerTest = 1;
	long beerIDIndex;\
	int firstOrder = 1;
	int i;

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
					beerIDIndex = findBeerByID(atol(input), beers, numberOfBeers);
					if(beerIDIndex){
						if(beers[beerIDIndex - 1].quantity > 0){
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
								if(beers[beerIDIndex - 1].quantity >= quantity){
									/*Add this beer to the array of ordered beers*/
									orderedBeers[beerIDIndex - 1] = atoi(input);
								}else{
									printf("We only have %d units of that beer left in stock. Please enter 1 to order all remaining units or anything else to not order this type of beer", beers[beerIDIndex - 1].quantity);
									fgets(input, BUFFER, stdin);
									if(atoi(input) == 1)
										orderedBeers[beerIDIndex - 1] = beers[beerIDIndex - 1].quantity;
								}
							}else{
								printf("This beer has been removed from your order\n");
								orderedBeers[beerIDIndex - 1] = 0;
							}
						}else{
							printf("%s is out of stock\n", beers[beerIDIndex].name);
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
					makeOrder(beers, orderedBeers, numberOfBeers);
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
void makeOrder(Beer *beers, int orderedBeers[], int numberOfBeers){
	/*Declare local variables*/
	int i;

	/*Remove the beers*/
	for(i = 0; i < numberOfBeers; i++){
		beers[i].quantity -=orderedBeers[i];
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
void printOrder(Beer *beers, int numberOfBeers, int orderedBeers[]){
	/*Declare local variables*/
	int i;
	double runningTotal;

	/*Prints out a header for the invoice*/
	printf("Beer\t\tQuantity Ordered\tPrice Per Unit\t\tSubtotal\n");

	/*Print out each beers information*/
	for(i = 0; i < numberOfBeers; i++){
		if(orderedBeers[i]){
			printf("%07ld\t\t%d\t\t\t%.2lf\t\t\t%.2lf\n", beers[i].id, orderedBeers[i], beers[i].price, orderedBeers[i] * beers[i].price);
			runningTotal += orderedBeers[i] * beers[i].price;
		}
	}
	/*Print out the total*/
	printf("\t\t\t\t\t\t\t\tTotal\n");
	printf("\t\t\t\t\t\t\t\t%.2lf\n", runningTotal);
}

/*Returns the index location of a beer in the array of beers + 1 or 0 if no beer with that id exists*/
int findBeerByID(long id, Beer *beers, int numberOfBeers){
	/*Declare local variables*/
	int i;

	/*Check every beer to see if it's ID is a match for the id being checked for*/
	for(i = 0; i < numberOfBeers; i++){
		if(beers[i].id == id)
			/*Return a true value corresponding to the index*/
			return i+1;
	}

	/*Return false*/
	return 0;
}

void searchBeerByID(char input[], Beer *beers, int numberOfBeers){
	/*Declare local variables*/
	int test;

	/*Get user input*/
	do{
		printf("Please enter a beer ID number\n");
		fgets(input, BUFFER, stdin);
		if(test = checkInt(input))
			printf("Please enter an integer number");
	}while(test);

	if(test = findBeerByID(atol(input), beers, numberOfBeers))
		printBeer(beers[test - 1]);
	else{
		printf("We do not have any beers with that ID number");
	}

}
