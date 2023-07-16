
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define Maxlen 5

void refreah(char *ptr){
    while(*ptr!='\0'){
            if(*ptr=='\n'){
                *ptr='\0';
            }
            ptr++;
        }
}

void push(int *Stack,int *ptop,char *line){
    char *ptr = line;
    char num[10];
    int numIdx=0;

    while(!isdigit(*ptr)){
        ptr++;
    }
    while(isdigit(*ptr)){
        num[numIdx] = *ptr;
        numIdx++;
        ptr++;
    }
//      printf("%d is input\n",atoi(num));

    if(*ptop == Maxlen-1){
        printf("Is full!\n");
    }
    else{
        *ptop=*ptop +1;
        Stack[*ptop] = atoi(num);
  //    printf("%d is in Stack now\n",Stack[*ptop]);
    }
}

void pop(int *Stack,int *ptop){
    if(*ptop==-1){
        printf("Is empty!\n");
    }
    else{
        printf("Pop %d\n",Stack[*ptop]);
        *ptop = *ptop -1;
    }
}

void myprintf(int *Stack,int *ptop){
    printf("Stack:");
    for(int i=0;i<=*ptop;i++){
        printf(" %d",Stack[i]);
    }
    printf("\n");
}


int main(){
    int Stack[Maxlen];
    int top =-1;
    int *ptop = &top;
    for(int i=0;i<Maxlen;i++){
        Stack[i]='\0';
    }
    char line[100];
    char *ptr;
    while(fgets(line,100,stdin))
    {
        ptr= line;
        refreah(ptr);
	while(isspace(*ptr)){
		ptr++;
	}
        if(*(ptr+1)=='r'){
           myprintf(Stack,ptop);
    //     printf("STACK[0] = %d\n",Stack[0]);
        }
        else if(*(ptr+1)=='o'){
//	   printf("int to pop\n");
            pop(Stack,ptop);
        }
        else if (*(ptr+1)=='u'){
            push(Stack,ptop,line);
        }
    }

}

