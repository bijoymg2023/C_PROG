#include<stdio.h>

int top = -1, max_s = 100;
char stk[100];

void push(char a) {
    if (top >= max_s - 1) {
        printf("STACK OVERFLOW");
    } else {
        stk[++top] = a;
    }
}

void pop() {
    if (top <= -1) {
        printf("STACK UNDERFLOW");
    } else {
        top--;
    }
}

int isEmpty() {
    return top == -1;
}

int main() {
    int indx;
    char str[] = "[ABC[23]][89]";
    printf("\nENTER STARTING INDEX:");
    scanf("%d", &indx);

    for (int i = indx; i < max_s && str[i] != '\0'; i++) {
        if (str[i] == '[') {
            push(str[i]);
        } else if (str[i] == ']') {
            while (!isEmpty() && stk[top] != '[') {
                pop();
            }
            
            if (!isEmpty()) {
                pop();
            } else {
                printf("Mismatched brackets: No corresponding opening bracket for index %d", i);
                break;
            }
        }
    }

    if (isEmpty()) {
        printf("All brackets are matched.");
    } else {
        printf("Mismatched brackets: No corresponding closing bracket for some opening brackets.");
    }

    return 0;
}
