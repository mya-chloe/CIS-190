/*Nathan Burdzel
 *10/3/18
 *Lab 5 Problem 2
 */

/*Defined constants*/
#define HIGHEST_CARD 13
#define LOWEST_CARD 1

/*Preprocessor Directives*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function stubs*/
void printCardName(int drawn);
int drawPlayerCard();
int drawDealerCard(int dealerTotal);
int determineWinner(int dealer, int player);
void playGame();
int increaseScore(int card);

int main(){
    /*Run the game then return*/
    playGame();
    return 0;
}

/*Runs the game operations*/
void playGame(){
    /*Variable declarations*/
    int playerTotal = 0, dealerTotal = 0, drawnCard = 0, faceDrawn = 0, userInput, reset = 0;

    /*Initialize srand for random numbers*/
    srand(time(NULL));

    /*Loop for player turn*/
    do{
        /*Check to see if this is not the first game*/
        if(reset){
          reset = 0;
          playerTotal = 0;
          dealerTotal = 0;
          faceDrawn = 0;
        }

        /*If it's the players first turn give them an opening hand*/
        if(!playerTotal){

            /*Draw first card*/
            printf("Your first card is ");
            drawnCard = drawPlayerCard();

            /*If a face card is drawn set faceDrawn to a true value*/
            if(drawnCard > 10)
              faceDrawn = 1;

            /*Increase the players score*/
            playerTotal += increaseScore(drawnCard);

            /*Draw second card*/
            printf("Your second card is ");
            drawnCard = drawPlayerCard();

            /*If a face card is drawn set faceDrawn to a true value*/
            if(drawnCard > 10)
              faceDrawn++;

            /*Increase the players score*/
            playerTotal += increaseScore(drawnCard);

            /*Check for blackjack*/
            if(faceDrawn && (playerTotal == 11 || playerTotal == 21)){
              printf("You got a blackjack, you win! Play again?(0 to play again, anything else to quit)");
              reset = 1;

              /*If the user wants to play again restart the game loop, otherwise exit the game loop*/
              scanf("%d", &userInput);
              if(!userInput)
                continue;
              break;
            }


        }

        /*Player turn*/
        /*Find out if the user want to hit or stay*/
        printf("Your score is now %d.\nWhat would you like to do?(0 to hit, anything else to stay)\n", playerTotal);
        scanf("%d", &userInput);

        /*If the player chose to hit*/
        if(userInput == 0){
            /*Draw a card and increase the score*/
            printf("You drew ");
            drawnCard = drawPlayerCard();
            playerTotal += increaseScore(drawnCard);

            /*Check for a bust*/
            if(playerTotal > 21){

                /*Print loss message*/
                printf("You busted, try again?(0 to play again, anything else to quit)");

                /*Prepare game to reset if the player chooses to play again*/
                reset = 1;

                /*Find out if the user wants to play again*/
                scanf("%d", &userInput);
                if(!userInput)
                  continue;
                break;
            }
        }

        /*If the player chose to stay*/
        else{

            /*Dealer turn*/
            /*Draw an opening hand*/
            printf("The dealers first card is ");
            drawnCard = drawDealerCard(dealerTotal);
            dealerTotal += increaseScore(drawnCard);
            printf("The dealers second card is ");
            drawnCard = drawDealerCard(dealerTotal);
            dealerTotal += increaseScore(drawnCard);

            /*While the dealer has under 17 keep giving the dealer cards*/
            while(dealerTotal < 17){
              printf("The dealers score is now %d\n", dealerTotal);
              printf("The dealer drew ");
              drawnCard = drawDealerCard(dealerTotal);
              dealerTotal += increaseScore(drawnCard);
            }

            /*Prepare game to reset if the player chooses to play again*/
            reset = 1;
        }


        /*Loop exit condition: if the game finished running and the player chose to end the game or the player busted and chose to end the game*/
    }while (determineWinner(dealerTotal, playerTotal) == 0 || userInput == 0);
    return;
}

/*Draws a card for the player, having them choose whether it's a 1 or 11*/
int drawPlayerCard(){
    int card, userInput;

    /*Get a random number for the card and tell the user what they drew*/
    card = (rand() % (HIGHEST_CARD - LOWEST_CARD)) + LOWEST_CARD;
    printCardName(card);

    /*If the card is an ace have the user choose if it should be an ace, 1 represents a low ace, and 0 represents a high ace*/
    if(card == 1){
        printf("Aces can be one or eleven, would you like it to be 1 or 11(1 for a 1, anything else for 11)\n");
        scanf("%d", &userInput);
        if(userInput != 1)
            card = 0;
    }
    return card;
}

/*Draws a card for the dealer without determining the value the ace should have*/
int drawDealerCard(int dealerTotal){
  int card, userInput;

  /*Get a random number for the card and tell the user what they drew*/
  card = (rand() % (HIGHEST_CARD - LOWEST_CARD)) + LOWEST_CARD;
  printCardName(card);

  if(card > 1)
    return card;

  /*If the card is an ace have the user choose if it should be an ace*/
  if(dealerTotal > 10)
      return 1;
  return 14;
}

//print the cards name that you drew
void printCardName(int drawn){
    switch(drawn){
        case(0):
            printf("an Ace\n");
            break;
        case(1):
            printf("an Ace\n");
            break;
        case(2):
            printf("a Two\n");
            break;
        case(3):
            printf("a Three\n");
            break;
        case(4):
            printf("a Four\n");
            break;
        case(5):
            printf("a Five\n");
            break;
        case(6):
            printf("a Six\n");
            break;
        case(7):
            printf("a Seven\n");
            break;
        case(8):
            printf("an Eight\n");
            break;
        case(9):
            printf("a Nine\n");
            break;
        case(10):
            printf("a Ten\n");
            break;
        case(11):
            printf("a Jack\n");
            break;
        case(12):
            printf("a Queen\n");
            break;
        case(13):
            printf("a King\n");
            break;
    }
    return;
}

/*Determines the winner, prints a win or loss message, and finds out if the player wants to play another round, returns 0 if the player wants to keep playing and 1 if the player chooses to quit the program*/
int determineWinner(int dealer, int player){
    int choice;

    /*If the dealer took their turn determine the winner, otherwise run the game loop again*/
    if(dealer!=0){
        printf("Dealer Hand Total: %d\nPlayer Hand Total: %d\n", dealer, player);

        /*If the dealer busted print a win statement*/
        if(dealer > 21)
          printf("The dealer busted, you win! Play again?(0 to play again, anything else to quit)");

        /*If the dealer has a higer score or tied the player print a loss statement*/
        else if(dealer >= player)
            printf("You lose, try again?(0 to play again, anything else to quit)");

        /*If the player has the higher score print a win message*/
        else printf("You win, play again?(0 to play again, anything else to quit)");

        /*Get user input on whether or not they want to play a new game*/
        scanf("%d", &choice);
        return choice;
    }else{
      return 0;
    }
}

/*Increases the score based on the card passed in, face value for number cards, 10 for face cards, and 11 for a high ace(passed in as a 14)*/
int increaseScore(int card){

    /*If the card is a high ace it's worth 11*/
    if(card == 0)
      return 11;

    /*If the card is not a high ace and isn't a face card it's worth it's face value*/
    if(card <= 10){
        return card;
    }

    /*Only other option is a face card, face cards are worth ten*/
    return 10;
}
