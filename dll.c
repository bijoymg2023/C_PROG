#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *llink,*rlink;
};
struct node *start = NULL,*last = NULL,*temp;
void insertbegin(){
struct node *head = malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&head->data);
head->llink = NULL;
head->rlink = NULL;
if(start==NULL && last==NULL){
start = head;
last = head;
}
else{
head->rlink = start;
head->llink = NULL;
start->llink = head;
start = head;
}
}
void insertend(){
struct node *head = malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&head->data);
head->llink = NULL;
head->rlink = NULL;
if(start==NULL && last==NULL){
start = head;
last = head;
}
else{
head->llink = last;
head->rlink = NULL;
last->rlink = head;
last = head;
}
}
void insertpos(){
int pos,i=1;
struct node *head = malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&head->data);
head->llink = NULL;
head->rlink = NULL;
printf("Enter the postion:");
scanf("%d",&pos);
temp = start;
if(start==NULL && last==NULL){
start = head;
last = head;
}
else{
if(pos==1)
{
head->rlink = start;
head->llink = NULL;
start->llink = head;
start = head;
}
else
{
while(i < pos){
temp = temp->rlink;
i++;
}
head->llink = temp->llink;
head->rlink = temp;
temp->llink->rlink = head;
temp->rlink->llink = head;

}}}
void deletebegin(){
temp = start;
if(start==NULL && last==NULL){
printf("List is Empty");
}
else{
temp = start;
start = temp->rlink;
free(temp);

}
}
void deleteend(){
temp = last;
if(start==NULL && last==NULL){
printf("List is Empty");
}
else{
temp = last;
last = temp->llink;
free(temp);
}
}
void deletepos(){
int ind,i=1;
printf("Enter the position:");
scanf("%d",&ind);
temp = start;
if(start==NULL && last==NULL){
printf("List empty");
}
else{
while(i < ind){
temp = temp->rlink;
i++;
}
if(temp->rlink==NULL){
temp->llink->rlink = NULL;
free(temp);
}
else{
temp->llink->rlink = temp->rlink;
temp->rlink->llink = temp->llink;
free(temp);}
}
}
void traversef(){
if(start!=NULL){
temp = start;
while(temp!=NULL){
printf("[%d] ",temp->data);
temp = temp->rlink;
}
printf("[%d]-->",temp->data);}
else{
printf("Empty");
}
}
void traverseb(){
if(last!=NULL){
temp = last;
while(temp!=NULL){
printf("[%d]--> ",temp->data);
temp = temp->llink;
}
printf("[%d]",temp->data);}
else{
printf("Empty");
}
}
void main(){
int op,op1,op2,op3;
while(1){
printf("\n1.INSERT 2.DELETE 3.TRAVERSE 4.EXIT:");
scanf("%d",&op);
switch(op){
case 1:
printf("1.BEGIN 2.END 3.POSITION:");
scanf("%d",&op1);
switch(op1){
case 1:
insertbegin();
break;
case 2:
insertend();
break;
case 3:
insertpos();
break;
}
break;
case 2:
printf("1.BEGIN 2.END 3.POSITION:");
scanf("%d",&op2);
switch(op2){
case 1:
deletebegin();
break;
case 2:
deleteend();
break;
case 3:
deletepos();
break;
}
break;
case 3:
printf("1.FORWARD 2.BACKWARD:");
scanf("%d",&op3);
switch(op3){
case 1:
traversef();
break;
case 2:
traverseb();
break;
}
break;
case 4:
exit(0);
break;
}
}
}