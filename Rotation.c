#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node* start = NULL;
void insert(struct node** start, int a){
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




void Rotation(struct node* start, int k){
    for( int i=0 ; i<k ; i++){
        struct node* ptr = start;
        struct node* temp = NULL;
        int temp1;    
        temp = ptr;
        temp1 = temp->data;
        ptr = ptr->link;
        temp->link = NULL;
        free(temp);

        while(ptr->link !=NULL){
            ptr = ptr->link;
        }
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = temp1;
        newNode->link = NULL;
        ptr->link = newNode;      
    }
}


void traverse(struct node* ptr){
    ptr = start;
    if(ptr == NULL){
        printf("EMPTY....");
    }
    else{
        while(ptr != NULL){
            printf("[%d]",ptr->data);
            ptr = ptr->link;
        }
    }
}
void main(){
    int n, d, k;
    printf("\nENTER NO. OF ELEMENTS:");
    scanf("%d",&n);
    for(int i = 0 ; i<n ; i++){
        printf("\nDATA:");
        scanf("%d",&d);
        insert(&start,d);
    }
    printf("\nENTER NO. OF ROTATIONS:");
    scanf("%d",&k);
    Rotation(start,k);
    traverse(start);


}
