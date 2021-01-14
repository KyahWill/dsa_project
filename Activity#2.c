#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Digit{
	int value;
	struct Digit* next;	
};
struct Digit* pop(struct Digit* stack){
	struct Digit* temp = stack->next;
	free(stack);
	return temp;
}
struct Digit* push(char c, struct Digit* stack){
	struct Digit* temp = (struct Digit*) malloc (sizeof(struct Digit));
	temp->value = c - '0';
	temp->next = stack;
	return temp;
}

int top(struct Digit* stack){
	int value; 
	if(stack == NULL)
		value = 0;
	else{
		struct Digit* temp = stack;
		value = stack->value;
	}
	return value;
}

int main(){
	
	char num1[100];
	char num2[100];
	int i = 0;
	int carry = 0;
	//Establishes Stacks
	struct Digit *top_stack1 = NULL;
	struct Digit *top_stack2 = NULL;
	struct Digit *solution = NULL;
	
	printf("Enter First Digit to Add: ");
	scanf("%s",&num1);	
	
	for(i = 0; i < strlen(num1);i++)
		top_stack1 = push(num1[i],top_stack1);
	
	printf("Enter Second Digit to Add: ");
	scanf("%s",&num2);
	
	for(i = 0; i < strlen(num2);i++)
		top_stack2 = push(num2[i],top_stack2);
		
	struct Digit *temp = top_stack1;	

	while(top_stack1 != NULL || top_stack2 != NULL){
		printf("\n %d + %d = ",top(top_stack1),top(top_stack2));
		int ans = top(top_stack1) + top(top_stack2) + carry;
		printf("%d ", ans );
		carry = ans/10;
		ans = ans % 10;
		solution = push((char)ans + '0',solution);
		if(top_stack1 != NULL)
			top_stack1 = pop(top_stack1);
		if(top_stack2 != NULL)
			top_stack2 = pop(top_stack2);
	}
	if(carry > 0){
		solution = push((char)carry + '0',solution);
	}
	
	printf("\n");
	while(solution!= NULL){
		printf("%d",top(solution));
		solution = solution->next;
	}
	return 0;
}
