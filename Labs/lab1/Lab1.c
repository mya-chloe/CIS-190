/*Nathan Burdzel
CIS 190 Lab 1
9/5/18
*/

#include <stdio.h>

int main(){
	//Initialize the variables
	int num1, num2, sum, diff, prod, quo;
	//Assign values to the variables
	num1 = 57;
	num2 = 20;
	//Calculate the sum difference product and quotient of the two numbers
	sum = num1 + num2;
	diff = num1 - num2;
	prod = num1 * num2;
	quo = num1 / num2;
	
	//Print Hello World and start a new line
	printf("Hello World\n");
	//Print the rest of the results on seperate lines
	printf("%d + %d = %d\n", num1, num2, sum);
	printf("%d - %d = %d\n", num1, num2, diff);
	printf("%d X %d = %d\n", num1, num2, prod);
	printf("%d / %d = %d\n", num1, num2, quo);
	
	//End the program
	return 0;
}
