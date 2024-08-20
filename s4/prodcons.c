#include<stdio.h>
#include<stdlib.h>
int max=5,mutex=1,f=-1,current=-1;
void producer(){
    if(mutex==1&&current!=(max-1)){
    mutex--;
    if(f==-1&&current==-1)
    f=0;
    ++current;
    printf("\nPRODUCER PRODUCED %d",current+1);
    mutex++;
    }
    else{
        printf("\nBUFFER FULL");
    }

}
void consumer(){
    if(mutex==1&&current!=(max-1)){
        mutex--;
        printf("\nCONSUMER CONSUMED %d",f+1);
        if(f==current){
            f=-1;
            current=-1;
        }
        else{
            f++;
            mutex++;
        }
        }
    else{
        printf("\nBUFFER EMPTY");
        }
}

int main(){
int ch;

while(1){
printf("\n1.PRODUCER 2.CONSUMER 3.EXIT\n");
scanf("%d",&ch);
switch(ch){
    case 1: producer();
            break;
    case 2: consumer();
            break;
    case 3: exit(0);
}
}
}