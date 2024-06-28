#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff, exp;
    struct node * link;
};
struct node *start1 = NULL, *start2 = NULL, *start = NULL, *start3 = NULL;
void insert(struct node **start, int x, int y){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * ptr = *start;
    head->coeff = x;
    head->exp = y;
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
void display(struct node *ptr){
    while(ptr != NULL){
        printf(" %dx^%d ",ptr->coeff,ptr->exp);
        ptr = ptr->link;
    }
}

struct node* addPolynomial(struct node **start1, struct node **start2){
struct node *ptr1 = *start1;
struct node *ptr2 = *start2;
struct node *start3 = NULL;
while(ptr1 != NULL && ptr2 != NULL){
    
if (ptr1->exp == ptr2->exp){
insert(&start3, ptr1->coeff + ptr2->coeff , ptr1->exp);
ptr1 = ptr1->link;
ptr2 = ptr2->link;
}

else if (ptr1->exp > ptr2->exp){
insert(&start3, ptr1->coeff , ptr1->exp);
ptr1 = ptr1->link;
}

else {
insert(&start3, ptr2->coeff , ptr2->exp);
ptr2 = ptr2->link;    
}

}

while (ptr1 != NULL){
insert(&start3, ptr1->coeff , ptr1->exp);
ptr1 = ptr1->link;    
}

while (ptr2 != NULL){
insert(&start3, ptr2->coeff , ptr2->exp);
ptr2 = ptr2->link;    
}
return start3;
}

int main(){
    int n, m, x, y, i;
    printf("\nENTER NO. OF TERMS IN POLYNOMIALS 1:");
    scanf("%d",&n);
    printf("ENTER COEFFICINETS AND EXPONENTS IN POYLNOMIALS 1 \n");
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        insert(&start1,x,y);
    }
    printf("\nENTER NO. OF TERMS IN POLYNOMIALS 2:");
    scanf("%d",&m);
    printf("ENTER COEFFICINETS AND EXPONENTS IN POYLNOMIALS 2 \n");
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        insert(&start2,x,y);
    }
    printf("\nPOLYNOMIAL 1:");
    display(start1);
    printf("\nPOLYNOMIAL 2:");
    display(start2);
    struct node* finalResult = addPolynomial(&start1,&start2);
    printf("\nRESULT:");
    display(finalResult);

    

}