/*
Nathan Burdzel
*/

#define JAGUAR_PRICE 249.00
#define REMOTE_PRICE 49.59
#define CDI_PRICE 1000.00
#define DO_PRICE 699.99
#define BETAMAX_PRICE 1300.00
#define SALES_TAX .0525


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

	/*Get user input*/
	printf("How many Jaguars were sold?");
	scanf("%d", &jaguar_quantity);
	printf("How many CDIs were sold?");
	scanf("%d", &cdi_quantity);
	printf("How many Remotes were sold?");
	scanf("%d", &remote_quantity);
	printf("How many 3DOs were sold?");
	scanf("%d", &do_quantity);
	printf("How many Betamax Players were sold?");
	scanf("%d", &betamax_quantity);	
	
	/*Calculate prices*/
	jaguar_total = jaguar_quantity * JAGUAR_PRICE;
	cdi_total = cdi_quantity * CDI_PRICE;
	remote_total = remote_quantity * REMOTE_PRICE;
	do_total = do_quantity * DO_PRICE;
	betamax_total = betamax_quantity * BETAMAX_PRICE;
	subtotal = jaguar_total + cdi_total + remote_total + do_total + betamax_total;
	tax = subtotal * SALES_TAX;
	total = subtotal + tax;	

	/*Print bill*/
	printf("QTY\tDESCRIPTION\tUNITPRICE\tTOTALPRICE\n");
	printf("___\t___________\t_________\t__________\n");
	printf("%2d\tJAGUAR\t\t%9.2f\t%10.2f\n", jaguar_quantity, JAGUAR_PRICE, jaguar_total);
	printf("%2d\tCDI\t\t%9.2f\t%10.2f\n", cdi_quantity, CDI_PRICE, cdi_total);
	printf("%2d\tREMOTE CTRLR\t%9.2f\t%10.2f\n", remote_quantity, REMOTE_PRICE, remote_total);
	printf("%2d\t3DO\t\t%9.2f\t%10.2f\n", do_quantity, DO_PRICE, do_total);
	printf("%2d\tBETAMAX\t\t%9.2f\t%10.2f\n", betamax_quantity, BETAMAX_PRICE, betamax_total);
	printf("\t\t\t\t\t__________\n");
	printf("\t\t\tSUBTOTAL\t%10.2f\n", subtotal);
	printf("\t\t\tTAX\t\t%10.2f\n", tax);
	printf("\t\t\tTOTAL\t\t%10.2f\n", total);
	return 0;
}
