#include <stdio.h>

/*
* Activity 4: 	President's Advisors
*Created by:	Will Vincent Parrone
*				Carl Vinas
*/
int main(){
	while(1){
	int i;
	int j;
	int interval;
	int counter;	
	int array[13];
	for(i = 0; i <13; i++) // initializes the value of the arrays in cases of multiple uses.
		array[i]= i+1;
	printf("Start: ");
	scanf("%d", &counter);
	if(counter == 0) // ends the program if the starting advisor is 0
		return 0;

	printf("Interval: ");
	scanf("%d", &interval);
	counter = (counter + 11)%13;
	
	printf("Chosen Advisors: ");
	for(i = 0; i < 5; i++){
		for(j = 0; j < interval; j++){
			counter++;
			while(array[counter % 13] == 0) //Basically determines whether the advisor is chosen and skips if they are 
				counter++;	
		}
		printf("%d ",array[counter % 13]);
		array[counter % 13 ] = 0;
	}
	printf("\n");	
	}
}
