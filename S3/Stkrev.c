#include<stdio.h>
#include<string.h>

int top = -1, max_s;
int stk[20];

void push(int a){
    if(top >= max_s-1){
        printf("\nOVERFLOW");
    }
    else{
        stk[++top] = a;
        printf("%c",stk[top]);
    }
}

void pop(){
    if(top == -1){
        printf("\nUNDERFLOW");
    }
    else{
        printf("%c",stk[top--]);
    }
}

void main(){
    char str[20];
    max_s = 20;

    printf("\nENTER NUMBER:");
    gets(str);
    printf("\nORIGINAL:\t");
    for(int i=0; i<strlen(str) ; i++){
        push(str[i]);
    }
    printf("\nREVERSED:\t");
    for(int i=0; i<strlen(str) ; i++){
        pop();
    }


}