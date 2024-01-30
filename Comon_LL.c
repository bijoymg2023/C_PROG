#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node * start = NULL, *start1 = NULL, *start2 = NULL;
void insert(struct node **start, int a){
    struct node * head = (struct node *)malloc(sizeof(struct node));
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
        ptr->link = head;
    }
}
void Common(struct node *start1, struct node *start2){
    struct node * ptr1 = start1;
    struct node * ptr2 = start2;
    while(ptr1 != NULL && ptr2 != NULL){
        if( ptr1->data == ptr2->data){
            insert(&start,ptr1->data);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->data > ptr2->data){
            ptr2 = ptr2->link;
        }
        else{
            ptr1 = ptr1->link;
        }
    }
}



void display(struct node* ptr){
    if(ptr == NULL){
        printf("EMPTY......");
    }
    else{
        while(ptr != NULL){
            printf("[%d]",ptr->data);
            ptr = ptr->link;
        }
    }
}
void main(){
    int n, a;
    printf("\nLL1____ ");
    printf("\nSIZE:");
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        printf("DATA:");
        scanf("%d",&a);
        insert(&start1,a);
    }
    printf("\nLL2____");
    printf("\nSIZE:");
    scanf("%d",&n);
    for(int i=0 ; i<n; i++){
        printf("DATA:");
        scanf("%d",&a);
        insert(&start2,a);
       
    }

    printf("\nLL1:");
    display(start1);
    printf("\nLL2:");
    display(start2);
    Common(start1,start2);   
    printf("\nCOMMON LL:");
    display(start);
}