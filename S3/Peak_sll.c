#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
}* start = NULL, *temp;

void insert(){
    struct node * head = (struct node *)malloc(sizeof( struct node ));
    printf("DATA:");
    scanf("%d",&head->data);
    head->link = NULL;
    if(start == NULL){
        start = head;
    }
    else{
        temp = start;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = head;
    }
}

void peak(){
    temp = start;
    if(start == NULL){
        printf("\nNO PEAK ELEMENTS\n");
    }
    else if (temp->link == NULL){
        printf("\n1 PEAK ELEMENT [%d]\n",temp->data);
    }
    else{
        struct node * right, *left = NULL ,*mid;
        while(right != NULL){
        right = temp->link; 
        mid = temp;
        if(left == NULL && mid->data > right->data){
            printf(" [%d] ",mid->data);  
        }
        else if( mid->data > left->data && mid->data > right->data){
            printf(" [%d] ",mid->data);
        }
        else if( mid->data > left->data && right == NULL){
            printf(" [%d] ",mid->data);
        }
        left = mid;
        temp = temp->link;

        }
    }
    }


void main(){
    int a;
    while(1){
        printf("ENTER NUMBER OF ELEMENTS:");
        scanf("%d",&a);
        while(a != 0){
            insert();
            a--;
        }
        if(a == 0){
            break;
        }
    }
    printf("PEAK:");
    peak();
}