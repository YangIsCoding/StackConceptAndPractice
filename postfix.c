#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eval(char *ptr);

int main(){
	char input[1000];	

	while(fgets(input,1000,stdin)){
		eval(input);
	}
}

void eval(char *postfix){

	double stack[1000]={0.0};
	char temp[100];
	char token;
	int top=0;
	int i=0;
	
	while(1){
		token = postfix[i];
		switch(token){
			case '\0':
				printf("%f\n",stack[top-1]);
				return ;
			case '\n':
				printf("%f\n",stack[top-1]);
				return ;
			case '+':
				stack[top-2] = stack[top-1]+stack[top-2];
				top--;
				break;
			case '-':
				stack[top-2] = stack[top-1]-stack[top-2];
				top--;
				break;
			case '*':
				stack[top-2] = stack[top-1]*stack[top-2];
				top--;
				break;;
			case '/':
				stack[top-2] = stack[top-1]/stack[top-2]; 
				top--;
				break;
			case ' ':
				break;
			default:
				stack[top] = token-'0';
				top++;
				break;
		}
		i++;
	}
	
}


