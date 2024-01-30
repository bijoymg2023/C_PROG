#include<stdio.h>
#include<math.h>

int  maxs = 100, j = 0, top = -1;
char stk[100], op[100];
void push(char c){
    if(top >= maxs-1){
        printf("overflow\n");
    }
    else{
        stk[++top] = c;
    }
}

void pop(){
    if(top == -1){
        printf("underflow\n");
    }
    else{
        op[j++] = stk[top];
        top--;
    }
}
int epop(){
    if(top <= -1){
        printf("underflow\n");
    }
    else{
        int b = stk[top--];
        return b;
    }
}

int priority(char ch){
    switch(ch){
        case '^':return 3;
                 break;
        case '*':
        case '/':return 2;
                 break;
        case '+':
        case '-':return 1;
                 break;
        case '(':return 0;
                 break;
    }
}

void postfix(){
    char inp[100];
    printf("\nENTER INFIX EXRESSION:");
    scanf("%s",&inp);
    for( int i=0; inp[i]!= '\0'; i++){
        if (inp[i] == '('){
            push(inp[i]);
        }
        else if((inp[i] == '+')||(inp[i] == '-')||(inp[i] == '*')||(inp[i] == '/')||(inp[i] == '^')){
            if((top == -1) || (priority(inp[i])>priority(stk[top]))){
                push(inp[i]);
            }
            else{
                pop();
                i--;
            }
        }
        else if(inp[i] == ')'){
            while(stk[top] != '('){
                pop();
            }
            top--;
        }
        else{
            push(inp[i]);
            pop();
        }
    }
    while(top != -1){
        pop();
    }
    op[j] = '\0';
    printf("\nPOSTFIX EXPRESSION:%s\n",op);
}

int operation(char c,int q,int p ){
    switch(c){
        case '^':return pow(q,p);
        case '*':return q*p;
        case '/':return q/p;
        case '+':return q+p;
        case '-':return q-p;
    }
}

void eval(){
    top = -1;
    for(int j=0; op[j]!='\0';j++){
        if(op[j]>='0' && op[j]<='9'){
            push(op[j] -'0'); //covert charecter to integer
        }
        else if((op[j]=='+')||(op[j]=='-')||(op[j]=='*')||(op[j]=='/')||(op[j]=='^')){
            int p = epop();
            int q = epop();
            int result = operation(op[j],q,p);
            push(result);
        }
        else{
            printf("INVALID CHARECTER%c",op[j]);
        }
    }
    int FinalResult = epop();
    printf("\nEVALUATION RESULT:%d",FinalResult);
}

int main(){
    postfix();
    eval();
    return 0;
}
