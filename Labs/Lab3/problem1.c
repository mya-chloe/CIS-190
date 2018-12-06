/*Nathan Burdzel*/
#include <stdlib.h>
#include <stdio.h>
/*Defined constants*/
#define OUTPUT_FILE "OUTPUT.txt"

int main(void){
	/*Declare Variables*/
	int userNumber = -1;
	
	/*Create File*/	
	FILE *output;
	
	/*Get User Input*/
	while(userNumber < 0 || userNumber > 32767){
		printf("Please enter a number from 0 to 32,767");
		scanf("%d", &userNumber);		
	}
	/*Open File*/
	output = fopen(OUTPUT_FILE, "w");
	
	/*Print Result To File*/	
	fprintf(output,"%4d",userNumber/10000%10);
	fprintf(output,"%4d",userNumber/1000%10);
	fprintf(output,"%4d",userNumber/100%10);
	fprintf(output,"%4d",userNumber/10%10);
	fprintf(output,"%4d\n",userNumber%10); 
	fprintf(output,"%4d",userNumber/1000%10);
	fprintf(output,"%4d",userNumber/100%10);
	fprintf(output,"%4d",userNumber/10%10);
	fprintf(output,"%4d\n",userNumber%10); 
	fprintf(output,"%4d",userNumber/100%10);
	fprintf(output,"%4d",userNumber/10%10);
	fprintf(output,"%4d\n",userNumber%10); 
	fprintf(output,"%4d",userNumber/10%10);
	fprintf(output,"%4d\n",userNumber%10); 
	fprintf(output,"%4d\n",userNumber%10); 
	
	/*Close File*/
	fclose(output);

	printf("View OUTPUT.txt for results.\n");
		
	return 0;
}
