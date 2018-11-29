/*Nathan Burdzel
 *11/28/18
 *Lab 11
 *Problem 1
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER 256

typedef struct movie{
	char name[BUFFER];
	char type[BUFFER];
	int rating;
	int releaseDate;
}Movie;


int loadFile(FILE *filePath, Movie **movies, char input[BUFFER]);
void printAllMovies(Movie *movies, int numberOfMovies);
void printMovie(Movie movie, int movieNumber);

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

	printAllMovies(movies, numberOfMovies);
}

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
		fgets(input, BUFFER, filePath);
		input[strlen(input) - 1] = 0;
		strcpy((*movies)[i].name, input);

		/*Get and copy the type of the movie*/
		fgets(input, BUFFER, filePath);
		input[strlen(input) - 1] = 0;
		strcpy((*movies)[i].type, input);

		/*Get the rating and set the movies rating to it*/
		fgets(input, BUFFER, filePath);
		(*movies)[i].rating = atoi(input);

		/*Get the releaseDate and set the movies rating to it*/
		fgets(input, BUFFER, filePath);
		(*movies)[i].releaseDate = atoi(input);
	}
	return numberOfMovies;
}

// void findMovieByName(){
//
// }

void printAllMovies(Movie *movies, int numberOfMovies){
	/*Declare local variables*/
	int i;

	/*While there are still more movies print the current movie*/
	for(i = 0; i < numberOfMovies; i++){
		printMovie(movies[i], i + 1);
	}
}

void printMovie(Movie aMovie, int movieNumber){
	printf("Movie %d:\n", movieNumber);
	printf("The name of the movie is: %s\n", aMovie.name);
	printf("This movie has the tye of: %s\n", aMovie.type);
	printf("This movie has a rating of %d/5 stars\n", aMovie.rating);
	printf("This movie was releasied in %d\n\n", aMovie.releaseDate);
}

// void sortByRating(){
////

// }
//
// void sortByName(){
//
// }
