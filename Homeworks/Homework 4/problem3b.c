/*Nathan Burdzel
  *CIS 190
  *Homework 4
  *Problem 3
  *Recursive solution for the map distance problem printing only the best route
  *11/15/19
  */

/*Preprocessor directives*/
#include <stdio.h>
#include <stdlib.h>

/*Defined constants*/
#define NUMBER_OF_CITIES 14
#define MAP_FILE_PATH "map.txt"
#define LONGEST_CITY_NAME 16
#define BUFFER 128

/*Function stubs*/
void loadFile(int map[NUMBER_OF_CITIES][NUMBER_OF_CITIES], int row, int col, FILE* fp);
void getInputs(char userInput[BUFFER], char names[NUMBER_OF_CITIES][LONGEST_CITY_NAME], int* fromCity, int* toCity);
void findPaths(int* bestDistance, int* bestNumberVisited, int bestVisited[], int currentCity, int nextCity, int goalCity, int distance, int cityCount, int visitedCities[NUMBER_OF_CITIES], int map[NUMBER_OF_CITIES][NUMBER_OF_CITIES], char cityNames[NUMBER_OF_CITIES][LONGEST_CITY_NAME]);
void printPath(int visitedCities[NUMBER_OF_CITIES], int toPrint, int cityCount, int distance, char cityNames[NUMBER_OF_CITIES][LONGEST_CITY_NAME]);
int findValueInArray(int array[NUMBER_OF_CITIES], int index, int value);

int main(void){
  /*Declare variables*/
  int map[NUMBER_OF_CITIES][NUMBER_OF_CITIES] = {{0}};
  int visitedCities[NUMBER_OF_CITIES] = {0};
  int bestVisited[NUMBER_OF_CITIES] = {0};
  int bestDistance = 32767;
  int bestNumberVisited = 0;
  int fromCity = 1;
  int toCity = 2;
  char names[NUMBER_OF_CITIES][LONGEST_CITY_NAME] = {"Seattle\0", "San Francisco\0", "Los Angeles\0", "Dallas\0", "New Orleans\0", "Miami\0", "Washington D.C.\0", "New York City\0", "Milwaukee\0", "Chicago\0", "Minneapolis\0", "Oklahoma City\0", "Phoenix\0", "Las Vegas\0"};
  FILE *fp;
  char userInput[BUFFER];

  /*Load the map from file*/
  fp = fopen(MAP_FILE_PATH, "r");
  loadFile(map, 0, 0, fp);
  fclose(fp);

  /*Get input from the user on which two cities they are traveling between*/
  getInputs(userInput, names, &fromCity, &toCity);

  /*Find the best path between the two cities, then print the best path*/
  findPaths(&bestDistance, &bestNumberVisited, bestVisited, fromCity - 1, 0, toCity - 1, 0, 1, visitedCities, map, names);
  printPath(bestVisited, 0, bestNumberVisited, bestDistance, names);

  return 0;
}

/*Recursively fills the map with data from the map file*/
void loadFile(int map[][NUMBER_OF_CITIES], int row, int col, FILE* fp){
  /*If the last row was checked return*/
  if (row >= NUMBER_OF_CITIES)
    return;
  /*If the last item in the column was checked load the next row*/
  if (col >= NUMBER_OF_CITIES)
    loadFile(map, row + 1, 0, fp);
  /*Otherwise load the item then the rest of the row*/
  else{
  fscanf(fp, "%d", &map[row][col]);
  loadFile(map, row, col + 1, fp);
  }
}

/*Gets input on the city the user is travling from and to*/
void getInputs(char userInput[BUFFER], char names[][LONGEST_CITY_NAME], int* fromCity, int* toCity){
  /*Declare local variables*/
  int i;
  /*Get the number of the first city*/
  do{
    printf("Please enter the number corresponding to your desired starting city\n");
    for(i = 0; i < NUMBER_OF_CITIES; i++){
      printf("%d: %s\n", i + 1, names[i]);
    }
    fgets(userInput, BUFFER, stdin);
    *fromCity = atoi(userInput);

    /*Validate input*/
    if(*fromCity <= 0 || (*fromCity >= NUMBER_OF_CITIES))
      printf("Please choose a city in the range");
  }while (*fromCity <= 0 || (*fromCity >= NUMBER_OF_CITIES));

  /*Get the number for the second city*/
  do{
    printf("Please enter the number corresponding to your desired ending city\n");
    for(i = 0; i < NUMBER_OF_CITIES; i++){
      printf("%d: %s\n", i + 1, names[i]);
    }
    fgets(userInput, BUFFER, stdin);
    *toCity = atoi(userInput);

    /*Validate input*/
    if(*toCity <= 0 || (*toCity >= NUMBER_OF_CITIES))
      printf("Please choose a city in the range");
  }while (*toCity <= 0 || (*toCity >= NUMBER_OF_CITIES));

}

/*Finds the best path between the two cities entered by the user*/
void findPaths(int* bestDistance, int* bestNumberVisited, int bestVisited[], int currentCity, int nextCity, int goalCity, int distance, int cityCount, int visitedCities[], int map[][NUMBER_OF_CITIES], char cityNames[][LONGEST_CITY_NAME]){
  /*If this is the goal city and the current distance is the best so far update the records to match the current state*/
  if(currentCity == goalCity && distance < *bestDistance){
    visitedCities[currentCity] = cityCount;
    *bestDistance = distance;
    *bestNumberVisited = cityCount;
    int i;
    for(i = 0; i < NUMBER_OF_CITIES; i++)
      bestVisited[i] = visitedCities[i];
    visitedCities[currentCity] = 0;
    return;
  }

  /*If the next city to visit was not already visited and there is a route to the next city try again with the next  next city*/
  if(visitedCities[nextCity] == 0 && map[currentCity][nextCity]){
    /*Add this city to the list of visited cities*/
    visitedCities[currentCity] = cityCount;
    /*Move on to the next city*/
    findPaths(bestDistance, bestNumberVisited, bestVisited, nextCity, 0, goalCity, distance + map[currentCity][nextCity], cityCount + 1, visitedCities, map, cityNames);
    /*Remove this city from the list of visited cities*/
    visitedCities[currentCity] = 0;
  }
  /*If there are more cities that can be visited from this city visit them*/
  if(nextCity < NUMBER_OF_CITIES){
    /*Add this city to the list of visited cities*/
      visitedCities[currentCity] = cityCount;
    /*Move on to the next possible next city*/
      findPaths(bestDistance, bestNumberVisited, bestVisited, currentCity, nextCity + 1, goalCity, distance, cityCount, visitedCities, map, cityNames);
    /*Remove this city from the list of visited cities*/
      visitedCities[currentCity] = 0;
  }
}

/*Prints the order that the cities were visited in*/
void printPath(int visitedCities[], int toPrint, int cityCount, int distance, char cityNames[][LONGEST_CITY_NAME]){
  /*If no cities have been printed, print out an introductory message then print the rest*/
  if(toPrint == 0){
    printf("To complete your trip you can visit %d cities over a distance of %d miles.\n", cityCount - 1, distance);
    printPath(visitedCities, 1, cityCount, distance, cityNames);
    return;
  }
  /*Otherwise print out which city you visited*/
  printf("City number %d in your trip is %s.\n", toPrint, cityNames[findValueInArray(visitedCities, 0, toPrint + 1)]);
  /*Print the rest of the cities*/
  if(toPrint < cityCount - 1)
    printPath(visitedCities, toPrint + 1, cityCount, distance, cityNames);
}

/*Returns the index of a value in an array given that the value exists in the array*/
int findValueInArray(int array[], int index, int value){
  /*If the value was found return it*/
  if(array[index] == value)
    return index;
  /*Check the rest of the array*/
  return findValueInArray(array, index + 1, value);
}
