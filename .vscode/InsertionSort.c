#include<stdio.h>

void main(){
    int i , A[20], n;
    printf("ENTER SIZE:");
    scanf("%d",&n);
    printf("\nENTER ARRAY:\n");
    for( i=0 ; i<n ; i++){
        scanf("%d",&A[i]);
    }
    i = 1;
    while(i < n){
        int temp = A[i];
        int j = i - 1;
        while(j>=0 && A[j]>temp ){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
        i++;
    }
    printf("\nSORTED ARRAY:");
    for( int i = 0 ; i < n ; i++){
        printf(" %d ",A[i]);
    }
}