/*Nathan Burdzel
 *11/28/18
 *Lab 11
 *Problem 1
 */

/*Preprocessor directives*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Defined constants*/
#define BUFFER 256

/*Structures*/
typedef struct movie{
	char name[BUFFER];
	char type[BUFFER];
	int rating;
	int releaseDate;
}Movie;

/*Function stubs*/
void menu(Movie * movies, int numberOfMovies, char input[]);
void searchByName(Movie * movies, int numberOfMovies, char input[]);
void printSortedMovies(Movie * movies, int numberOfMovies, char input[]);
int loadFile(FILE *filePath, Movie **movies, char input[BUFFER]);
void freeMemory(Movie **movies);
void printAllMovies(Movie *movies, int numberOfMovies);
void printMovie(Movie movie, int movieNumber);
int compareStrings(const void * a, const void * b);
int compareInts(const void * a, const void * b);

int main(/*int argc, char *argv[]*/void){
	/*Declare variables*/
	int i;
	char input[BUFFER];
	FILE *fp;
	int numberOfMovies;

  /*Initialize the array of movies*//////
	Movie *movies = malloc(0);

	/*Open the file*/
	fp = fopen("movies.txt", "r");

  /*Load the file*/
	numberOfMovies = loadFile(fp, &movies, input);

	/*Close the file*/
	fclose(fp);

	/*Print the information on every movie*/
	menu(movies, numberOfMovies, input);

	/*Free the memory*/
	freeMemory(&movies);
}

void menu(Movie * movies, int numberOfMovies, char input[]){
	/*Declare local variables*/
	int selection;

	/*Menu loop*/
	do{
		/*Get input from the user and convert it to an int*/
		printf("Enter 1 to search for a movie, 2 to view all movies, or 3 to quit:\n");
		fgets(input, BUFFER, stdin);
		selection = atoi(input);

		/*Perform the requested operation*/
		switch(selection){
			/*Search for a movie*/
			case 1:
				searchByName(movies, numberOfMovies, input);
				break;
			/*Print all the movies n a sorted order*/
			case 2:
				printSortedMovies(movies, numberOfMovies, input);
				break;
			/*Invalid input*/
			default:
				printf("Invalid selection");
			/*Quit the program*/
			case 3:
				break;
		}
	}while (selection != 3);
}

void searchByName(Movie * movies, int numberOfMovies, char input[]){
	/*Declare local variables*/
	int i;

	/*Get input from the user*/
	printf("Enter the name of the movie you would like to find:\n");
	fgets(input, BUFFER, stdin);
	input[strlen(input) - 1] = '\0';

	/*Search all the movies for that movie*/
	for(i = 0; i < numberOfMovies; i++){
		/*If name is a match for the movies name print out the movies information and return*/
		if(!strcmp(movies[i].name, input)){
			printMovie(movies[i], i);
			return;
		}
	}
	/*If the movie was not found inform the user*/
	printf("Movie not found\n");
}

void printSortedMovies(Movie * movies, int numberOfMovies, char input[]){
	/*Declare local variables*/
	int selection;

	/*Loop to ensure a valid selection was chosen*/
	do{
		/*Get input from the user and convert it to an int*/
		printf("Enter 1 to view all movies by name, 2 to view all movies by rating, or 3 to cancel:\n");
		fgets(input, BUFFER, stdin);
		selection = atoi(input);

		/*Perform the requested operation*/
		switch(selection){
			/*Sort by name and print all movies*/
			case 1:
				qsort(movies, numberOfMovies, sizeof(Movie), compareStrings);
				printAllMovies(movies, numberOfMovies);
				break;
			/*Sort by rating and print all movies*/
			case 2:
				qsort(movies, numberOfMovies, sizeof(Movie), compareInts);
				printAllMovies(movies, numberOfMovies);
				break;
			/*Invalid input*/
			default:
				selection = 0;
				printf("Invalid selection");
			/*Go back to the menu*/
			case 3:
				break;
		}
	}while(!selection);
}

/*Loads from file filepath to the array of structures movies*/
int loadFile(FILE *filePath, Movie **movies, char input[BUFFER]){
	/*Declare local variables*/
	int numberOfMovies, i;

	/*Retrieve the number of movies from the file*/
	fgets(input, BUFFER, filePath);
	numberOfMovies = atoi(input);

	/*Allocate the right amount of memory*/
	(*movies) = realloc((*movies), sizeof(Movie) * numberOfMovies);

	/*Fill the structure array*/
	for(i = 0; i < numberOfMovies; i++){
		/*Get and copy the name of the movie*/
		/*Get the name*/
		fgets(input, BUFFER, filePath);
		/*Strip the newline*/
		input[strlen(input) - 1] = 0;
		/*Copy it into (*movies)[i].name*/
		strcpy((*movies)[i].name, input);

		/*Get and copy the type of the movie*/
		/*Get the type*/
		fgets(input, BUFFER, filePath);
		/*Strip the newline*/
		input[strlen(input) - 1] = 0;
		/*Copy it into (*movies)[i].type*/
		strcpy((*movies)[i].type, input);

		/*Get the rating and set the movies rating to it*/
		fgets(input, BUFFER, filePath);
		(*movies)[i].rating = atoi(input);

		/*Get the releaseDate and set the movies rating to it*/
		fgets(input, BUFFER, filePath);
		(*movies)[i].releaseDate = atoi(input);
	}

	/*Return the number of movies for use in iterating through the full array*/
	return numberOfMovies;
}

/*Frees the memory*/
void freeMemory(Movie **movies){
	/*Free the whole array*/
	free((*movies));
}

/*Prints information on every movie*/
void printAllMovies(Movie *movies, int numberOfMovies){
	/*Declare local variables*/
	int i;

	/*While there are still more movies print the current movie*/
	for(i = 0; i < numberOfMovies; i++){
		printMovie(movies[i], i + 1);
	}
}

/*Prints the information on a single movie*/
void printMovie(Movie aMovie, int movieNumber){
	printf("Movie %d:\n", movieNumber);
	printf("The name of the movie is: %s\n", aMovie.name);
	printf("This movie has the tye of: %s\n", aMovie.type);
	printf("This movie has a rating of %d/5 stars\n", aMovie.rating);
	printf("This movie was released in %d\n\n", aMovie.releaseDate);
}

int compareStrings(const void * a, const void * b){
	return strcmp((*(Movie*)a).name, (*(Movie*)b).name);
}

int compareInts(const void * a, const void * b){
	if((*(Movie*)a).rating < (*(Movie*)b).rating)
		return -1;
	if((*(Movie*)a).rating > (*(Movie*)b).rating)
		return 1;
	return 0;
}
