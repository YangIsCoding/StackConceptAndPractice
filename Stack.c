#include <stdio.h>
#include <stdlib.h>
#define MAXELEMENT 100


void push(int n,int *ptr,int ptop);
int pop(int *ptr,int ptop);
void printfStack(int *ptr,int ptop);

int main(){
	int choice = 0,n;
	int stack[MAXELEMENT];
	int index = 0;
	
	while(choice!=-1){
		printf("1)push  2)pop  3)print stack\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("what do you want to push?\n");
				scanf("%d",&n);
				//push(n,stack,top);
				stack[index] = n;
				index++;
				break;
			case 2:printf("%d was poped from the stack.\n",stack[index-1]);
				index--;
				break;
			case 3:for(int i=index-1;i>=0;i--){
					printf("%d ",stack[i]);
				}
				printf("\n");
				break;;
		}
	}
}

void push(int n,int *stack,int top){
	if(top==MAXELEMENT-1){
		printf("too many!\n");
		exit(1);
	}
	else{
		top++;
		stack[top] = n;
	}
}

int pop(int *stack,int top){
	if(top==-1){
		printf("the stack is empty\n");
		exit(1);
	}
	return stack[top];
}

void printfStack(int *stack,int top){
	if(top==-1){
		printf("stack is empty\n");
	}
	else{
		for(int i = top;i>=0;i--){
			printf("%d",stack[i]);
		}
		printf("\n");
	}

