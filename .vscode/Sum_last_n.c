#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node * start = NULL;
void insert(struct node **start,int a){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = *start;
    head->data = a;
    head->link = NULL;
    if(ptr == NULL){
        *start = head;
    }
    else{
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = head;
    }

}

void Sum_last_n(struct node* ptr,int n, int a){
    int sum = 0;
    if(ptr == NULL){
        printf("\nSUM:0");
    }
    else{
        int pos = a-n;
        while(ptr != NULL && pos<a){
        sum += ptr->data;
        ptr = ptr->link; 
        pos++;
        }
        if(a-n == a){
        sum += ptr->data;
        }
        printf("\nSUM:%d ",sum);
    }
}


void main(){
    int a, b, n;
    printf("\nENTER SIZE:");
    scanf("%d",&a);
    for(int i = 0 ; i<a ; i++){
        printf("\nDATA:");
        scanf("%d",&b);
        insert(&start,b);
    }

    printf("\nENTER N:");
    scanf("%d",&n);
    Sum_last_n(start,n,a);

}