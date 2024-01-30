#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
} *start = NULL, *temp, *prev;

void ins_begin(){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("MEMORY ALLOCATION FAILED\n");
    }
    printf("ENTER DATA:");
    scanf("%d",&head->data);
    head->link = NULL;
    if(start == NULL){
        start = head;
    }
    else{
        head->link = start;
        start = head;

}
}
void ins_end(){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA:");
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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ins_pos(){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    int pos = 1, i = 1;
    printf("ENTER DATA:");
    scanf("%d",&head->data);
    printf("ENTER POSITION FOR INSERTION:");
    scanf("%d",&pos);
    head->link = NULL;
    if(start == NULL || pos == 1){
        head->link = start;
        start = head;
    }
    else{
        temp = start;
        while(temp != NULL && i<pos){
            prev = temp;
            temp = temp->link;
            i++;
        }
        prev->link = head;
        head->link = temp;    
}    

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void del_begin(){
    temp = start;
    if(temp == NULL){
        printf("EMPTY LINKLIST");
    }
    else{
        start = temp->link;
        free(temp);
    }    
}
void del_end(){ 
    int count = 0;    
    temp = start;
    if(temp == NULL){
        printf("EMPTY LINKLIST");
    }
    else{
        while(temp->link != NULL){
            prev = temp;
            temp = temp->link;
            count++;
        }
        if(count == 0){
            del_begin();
        }
        else{
        prev->link = NULL;
        free(temp);
        }
    }    
}
//________________________________________________________________________
void del_pos(){
    int pos = 1, i = 1;
    if(start == NULL){
        printf("EMPTY LINKLIST");
    }
    else{
        temp = start;
        printf("ENTER POSITION FOR DELETION:");
        scanf("%d",&pos);
        if(pos == 1){
            start = start->link;
            free(temp);
            printf("NODE DELETED AT POSITION 1\n");
        }
        else{
            while(temp != NULL && i<pos){
                prev = temp;
                temp = temp->link;
                i++;
            }
            if(temp == NULL){
                printf("INVALID POSITION\n");
            }
            else{
            prev->link = temp->link;
            free(temp);
            printf("NODE DELETED AT POSITION %d\n",pos);
            }
        }
        
    
    }    
}
//____________________________________________________________________________
void traverse(){
temp = start;
while(temp != NULL){
    printf("[%d] ",temp->data);
    temp = temp->link;
}
printf("\n");   
}

void main(){
    int a, b;
    while(1){
    printf("1.INSERTION 2.DELETION 3.TRAVERSE 4.EXIT:");
    scanf("%d",&a);
    switch(a){
    case 1: 
    case 2:
            switch(a){
            case 1: printf("1.BEGINNING 2.POSITION 3.END\n");
                    printf("OPERATION:");
                    scanf("%d",&b);
                    switch(b){
                    case 1: ins_begin();
                            break;
                    case 2: ins_pos();
                            break;
                    case 3: ins_end();
                            break;
                    }
                    break;
            case 2: if(start == NULL){
                    printf("\n__________________ERROR________________\n");
                    break;
                    }
                    else{
                    printf("1.BEGINNING 2.POSITION 3.END\n");
                    printf("OPERATION:");
                    scanf("%d",&b);
                    switch(b){
                    case 1: del_begin();
                            break;
                    case 2: del_pos();
                            break;
                    case 3: del_end();
                            break;
                    }
                    }
                    break;        
            }
            break;
    case 3: if (start == NULL){
                printf("ERROR__EMPTY LINKLIST\n");
                }
            else traverse();
            break;
    case 4: printf("EXITING");
            exit(0); 
            break;
            }
        }
}