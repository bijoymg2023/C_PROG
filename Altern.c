#include<stdio.h>
#include<stdlib.h>
//
struct node {
    int data;
    struct node * link;
};
struct node *start = NULL, *start1 = NULL, *start2 = NULL;
void insert(struct node **start, int a){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * ptr = *start;
    head->link = NULL;
    head->data = a;
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




void display(struct node * ptr){
    if (ptr == NULL){
        printf("EMPTY.....");
    }
    else{
        while(ptr != NULL){
            printf(" [%d] ",ptr->data);
            ptr = ptr->link;
        }
    }
}
void AlternatingSplit(struct node *start){
    struct node * ptr = start;
    while (ptr != NULL){
            insert(&start1,ptr->data);
            ptr = ptr->link;
            if(ptr != NULL){
            insert(&start2,ptr->data);
            ptr = ptr->link;
            }
        }
    
       
    

}

void main(){
    int n, data;
    printf("ENTER SIZE:");
    scanf("%d",&n);
    for(int i=0; i<n ; i++){
        printf("DATA:");
        scanf("%d",&data);
        insert(&start,data);
    }
    printf("\nORIGINAL LL:");
    display(start);
    AlternatingSplit(start);
    printf("\nLL 1:");
    display(start1);
    printf("\nLL 2:");
    display(start2);
    

}