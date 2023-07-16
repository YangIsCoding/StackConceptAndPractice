#include <stdio.h> 
#include <stdlib.h> 
#include<string.h>
#define MAX 5000

int priority(char op);
void inToPostfix(char* infix,char* postfix);

int main(void) { 
    char infix[MAX] = {'\0'}; 
    char postfix[MAX]= {'\0'}; 
    while(fgets(infix,MAX,stdin)){
        infix[strlen(infix)-1]='\0';
        inToPostfix(infix, postfix);
        for(int i=0;postfix[i]!='\0';i++) {
            if(postfix[i+1]=='+'||postfix[i+1]=='-'||postfix[i+1]=='*'||postfix[i+1]=='/'){
                printf("%c ",postfix[i]);
            }else{
                printf("%c", postfix[i]);
            }
        }
        printf("\n");
        memset(postfix,'\0',strlen(postfix));
    }
    return 0; 
} 

int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    } 
} 

void inToPostfix(char* infix, char* postfix) { 
    char stack[MAX] = {'\0'};
    int i, j, top;
    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++) switch(infix[i]) { 
        case '(':
            stack[++top] = infix[i]; 
            break; 
        case '+': case '-': case '*': case '/': 
            while(priority(stack[top]) >= priority(infix[i])) { 
                postfix[j++] = stack[top--];
            } 
            postfix[j++]=' ';
            stack[++top] = infix[i];
            break; 
        case ')':
            while(stack[top] != '(') {
                postfix[j++] = stack[top--];
            } 
            top--;
            break; 
        default:
            postfix[j++] = infix[i];
    }
    while(top > 0) { 
        postfix[j++] = stack[top--];
    }
}
