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
int loadFile(FILE *filePath, Movie **movies, char input[BUFFER]);
void printAllMovies(Movie *movies, int numberOfMovies);
void printMovie(Movie movie, int movieNumber);
void freeMemory(Movie **movies);

int main(/*int argc, char *argv[]*/void){
	/*Declare variables*/
	int i;
	char input[BUFFER];
	FILE *fp;
	int numberOfMovies;

  /*Initialize the array of movies*/
	Movie *movies = malloc(0);

	/*Open the file*/
	fp = fopen("movies.txt", "r");

  /*Load the file*/
	numberOfMovies = loadFile(fp, &movies, input);

	/*Close the file*/
	fclose(fp);

	/*Print the information on every movie*/
	printAllMovies(movies, numberOfMovies);

	/*Free the memory*/
	freeMemory(&movies);
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
	free((*movies));//test
}

// void findMovieByName(){
//
// }

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

// void sortByRating(){
//

// }
//
// void sortByName(){
//
// }
