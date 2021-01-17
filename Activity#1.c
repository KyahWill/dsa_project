#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
*Will Vincent Parrone
*Carl Vinas
*
*
*/
#define BOOL int
#define TRUE  1
#define FALSE 0
BOOL check(char* pattern, char* text, int counter, int size){
	int i;
	for(i = 0; i<size ;i++){
		if(pattern[i] != text[counter+i])
			return FALSE;
	}	
	return TRUE;
}

int solution(char* pattern, char* text, int size){
	int x = 0;
	int counter = 0;
	int string_length = strlen(text)- size+1;
	for(counter = 0; counter < string_length; counter++)
		if(check(pattern, text, counter,size) == TRUE)
			x++;
	return x;
}

int main(){
	char ch;
	do{
		FILE *fp;
		char filename_input[64];
		char pattern_input[64];
		char *file_content;
		int file_size;
		//Asks for the filename
		printf("Enter filename:");
		scanf("%s",filename_input);
		
		//Fills in the input 
		fp = fopen(filename_input,"r"); 
		if(fp==NULL){
			printf("Error in reading the file:");
			return 0;
		}else{
			printf("\nTEXT \n");
			//Determines the length of the entire string in test
			while((ch = fgetc(fp))!=EOF)
				file_size++;
				
			//Reads the character within the file and appends them to the file content
			file_content = (char*)malloc(file_size);
			rewind(fp);
			fscanf(fp,"%s",file_content);	
			printf("%s\n", file_content);
			
			//Asks for the pattern:
			printf("Enter Pattern: ");
			scanf("%s",pattern_input);
			
			int output = solution(pattern_input, file_content, strlen(pattern_input));
			if(output == 0)
				printf("\nNo Matches found!\n\n");
			else
				printf("\nTotal Number of Matches: %d\n\n", output);
			
			fclose(fp);		
			//closing any garbage bytes
			free(file_content);
			memset(filename_input,0,strlen(filename_input));
			memset(pattern_input,0,strlen(pattern_input));
		}
		printf("Again(y/n)");
		scanf("%s",&ch);	
	}while( ch == 'Y' || ch == 'y');
	return 0;
	
}
