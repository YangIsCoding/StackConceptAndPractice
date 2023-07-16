#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int Stack[64];
int top = -1;

char *getword(char *line,char *word){
	
	char *ptr = line;
	char *qtr=word;	

	while(*ptr && isspace(*ptr)){
		ptr++;
	}
	while(*ptr && isalpha(*ptr)){
		*qtr++=*ptr++;
	}
	*qtr='\0';
	if(qtr-word==0){
		return NULL;
	}
	return ptr;
}

void push(int num){
	
	if(top>=63){
		printf("Is full!\n");
	}
	else{
		top++;
		Stack[top] = num;
	}
}

void pop(){
	
	if(top==-1){
		printf("Is empty!\n");	
	}
	else{
		printf("Pop %d\n",Stack[top]);
		Stack[top]='\0';
		top--;
	}
}

void Print(){
	printf("Stack:");
	for(int i =0;i<=top;i++){
		printf(" %d",Stack[i]);
	}
	printf("\n");
}

int main(){
	char line[1024];
	char word[100];
	char *ptr;
	while(fgets(line,1024,stdin)){
		ptr = line;
		while(ptr=getword(ptr,word)){
			if(strcmp(word,"pop")==0){
				pop();
			}
			else if(strcmp(word,"push")==0){
				push(atoi(ptr));
			}
			else if(strcmp(word,"print")==0){
				Print();
			}
		}	
	}

}
