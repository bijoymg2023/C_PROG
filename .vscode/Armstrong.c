#include<stdio.h>
#include<math.h>

void armstrong(int a){
    int rem, result = 0, temp, count = 0; 
    temp = a;
    printf("%d \n",temp);
    while(temp != 0){
        temp = temp / 10;
        count++;
    }
    temp = a;
    while(temp != 0){
         rem = temp % 10;
         result += pow(rem,count);
         temp = temp / 10;
    }
    printf("%d \n",result);

    if (a == result){
        printf("%d IS AN ARMSTRONG NUMBER",result);
    }
    else{
        printf("%d IS NOT ARMSTRONG NUMBER",result);
    }

}
void main(){
    int a;
    printf("ENTER A NUMBER");
    scanf("%d",&a);
    armstrong(a);

}
