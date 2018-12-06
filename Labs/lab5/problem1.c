/*Nathan Burdzel
Lab 5
Problem 1*/

/*Preprocessor Directives*/
#include <math.h>
#include <stdio.h>

int main(void) {
 
    /*Define variables*/
    int menu_choice;
    float num1, num2 = -1;
 
    /*Get menu option*/
    printf("\nPlease enter the number corresponding to your desired operation:\n1: Square Root\n2: Absolute Value\n3: Exponent\n4: Natural Logarithm\nAnything Else: Log Base Ten\n");
    scanf("%d", &menu_choice);

    /*Perform the operation for the menu choice*/
    switch(menu_choice) {
 
        /*Prints the square root of a user number*/
        case (1):
 
            /*Get a positive number from the user*/
            do {
                printf("Please enter the number that you want the square root of:\n");
                scanf("%f", &num1);
 
                /*If the user entered a negative number print a new prompt*/
                if(num1 < 0)
                    printf("Please enter a positive number\n");
            }while (num1 < 0);

            /*Return the square root of the users number*/
            printf("The square root of %f is %.3lf\n",  num1, sqrt((double) num1));
            break;
 
        /*Prints the absolute value of a user entered number*/
        case (2):
 
            /*Get user number*/
            printf("Please enter the number that you want the absolute value of:\n");
            scanf("%f", &num1);
 
            /*Print the absolute value of the users number*/
            printf("The absolute value of %f is %f\n",  num1, (float) fabs((double) num1));
            break;
 
        /*Prints the result of a number raised to the exponent of another number*/
        case (3):
 
            /*Get numbers from the user*/
            printf("Please enter the number that you want raised to a power:\n");
            scanf("%f", &num1);
            printf("Please enter the power you want %f raised too:\n", num1);
            scanf("%f", &num2);
 
            /*Print the result*/
            printf("%f raised to the %f power is %.3f\n",  num1, num2, (float) pow((double) num1, (double) num2));
            break;
 
        /*Prints the natural log of a user entered number*/
        case (4):
 
            /*Get a positive number from the user*/
            do {
                printf("Please enter the number that you want the natural log of:\n");
                scanf("%f", &num1);
 
                /*If it is a negative number print a new prompt*/
                if(num1 < 0)
                    printf("Please enter a positive number\n");
            }while (num1 < 0);
 
            /*Print the result*/
            printf("The natural log of %f is %.3lf\n",  num1, log((double) num1));
            break;
 
        /*Prints the log base ten of a user entered number*/
        default:
 
            /*Get a positive number from the user*/
            do {
                printf("Please enter the number that you want the log base ten:\n");
                scanf("%f", &num1);
 
                /*If the user entered a negative number print a new prompt*/
                if(num1 < 0)
                    printf("Please enter a positive number\n");
            }while (num1 < 0);
 
            /*Print the result*/
            printf("Log base ten of %f is %.3lf\n",  num1, log10((double) num1));
    }
}
