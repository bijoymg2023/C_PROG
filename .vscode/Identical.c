#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node * start = NULL, *start1 = NULL, *start2 = NULL;

void insert(struct node **start, int a){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * ptr = *start;
    head->data = a;
    head->link = NULL;
    if(ptr == NULL){
        *start = head;
    }
    else{
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link =  head;

    }
}

void Check_Identical(struct node *start1, struct node *start2){
    struct node * ptr1 =  start1;
    struct node * ptr2 =  start2;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data != ptr2->data){
            printf("\nLL1 NOT IDENTICAL TO LL2");
            break;
        }
        else{
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
    }
    if((ptr1 != NULL && ptr2 == NULL)||(ptr2 != NULL && ptr1 == NULL)){
            printf("\nLL1 NOT IDENTICAL TO LL2");
    }
    else{
        printf("\nL1 IDENTICAL TO L2");
    }
}   

void display(struct node* ptr){
    if( ptr == NULL){
        printf("EMPTY.....");
    } 
    else{
        while(ptr != NULL){
            printf("[%d]",ptr->data);
            ptr = ptr->link;
        }
    }
}


void main(){
    int n, d;
    printf("\nLL1 SIZE:");
    scanf("%d",&n);
    for(int i = 0; i<n ; i++){
        printf("DATA:");
        scanf("%d",&d);
        insert(&start1,d);
    }
    
    printf("\nLL2 SIZE:");
    scanf("%d",&n);
    for(int i = 0; i<n ; i++){
        printf("DATA:");
        scanf("%d",&d);
        insert(&start2,d);
    }
    printf("\nLL1: ");
    display(start1);
    printf("\nLL2: ");
    display(start2);
    Check_Identical(start1,start2);


}