/*
Nathan Burdzel
*/

#define JAGUAR_PRICE 249.00
#define REMOTE_PRICE 49.59
#define CDI_PRICE 1000.00
#define DO_PRICE 699.99
#define BETAMAX_PRICE 1300.00
#define SALES_TAX .0525
#define INPUT_FILE "INPUT.txt"
#define OUTPUT_FILE "OUTPUT.txt"

#include <stdlib.h>
#include <stdio.h>

int main(void){
	/*Declare variables*/
	float subtotal = 0;
	float tax = 0;
	float total = 0;	
	int jaguar_quantity = 0;
	int cdi_quantity = 0;
	int remote_quantity = 0;
	int do_quantity = 0;
	int betamax_quantity = 0;

	float jaguar_total = 0;
	float cdi_total = 0;
	float remote_total = 0;
	float do_total = 0;
	float betamax_total = 0;

	/*Open read file*/
	FILE *input;
	input = fopen(INPUT_FILE, "r");

	/*Get user input*/
	fscanf(input, "%d", &jaguar_quantity);
	fscanf(input, "%d", &cdi_quantity);
	fscanf(input, "%d", &remote_quantity);
	fscanf(input, "%d", &do_quantity);
	fscanf(input, "%d", &betamax_quantity);	
	
	/*Close read file*/
	fclose(input);

	/*Calculate prices*/
	jaguar_total = jaguar_quantity * JAGUAR_PRICE;
	cdi_total = cdi_quantity * CDI_PRICE;
	remote_total = remote_quantity * REMOTE_PRICE;
	do_total = do_quantity * DO_PRICE;
	betamax_total = betamax_quantity * BETAMAX_PRICE;
	subtotal = jaguar_total + cdi_total + remote_total + do_total + betamax_total;
	tax = subtotal * SALES_TAX;
	total = subtotal + tax;	

	/*Open write file*/
	FILE *output;
	output = fopen(OUTPUT_FILE, "w");
	

	/*Print bill to file*/
	fprintf(output, "QTY\tDESCRIPTION\tUNITPRICE\tTOTALPRICE\n");
	fprintf(output, "___\t___________\t_________\t__________\n");
	fprintf(output, "%2d\tJAGUAR\t\t%9.2f\t%10.2f\n", jaguar_quantity, JAGUAR_PRICE, jaguar_total);
	fprintf(output, "%2d\tCDI\t\t%9.2f\t%10.2f\n", cdi_quantity, CDI_PRICE, cdi_total);
	fprintf(output, "%2d\tREMOTE CTRLR\t%9.2f\t%10.2f\n", remote_quantity, REMOTE_PRICE, remote_total);
	fprintf(output, "%2d\t3DO\t\t%9.2f\t%10.2f\n", do_quantity, DO_PRICE, do_total);
	fprintf(output, "%2d\tBETAMAX\t\t%9.2f\t%10.2f\n", betamax_quantity, BETAMAX_PRICE, betamax_total);
	fprintf(output, "\t\t\t\t\t__________\n");
	fprintf(output, "\t\t\tSUBTOTAL\t%10.2f\n", subtotal);
	fprintf(output, "\t\t\tTAX\t\t%10.2f\n", tax);
	fprintf(output, "\t\t\tTOTAL\t\t%10.2f\n", total);

	/*Close file*/	
	fclose(output);
	return 0;
}
