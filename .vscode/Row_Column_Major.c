#include<stdio.h>
int Top = -1, max_s, stk[100];

void push(int a){
    if(Top >= max_s-1){
        printf("OVERFLOW");
    }
    else{
        stk[++Top] = a;
    }
}



void RowMajor(int r, int c, int arr[10][10]){
    for(int i = 0 ; i<r ; i++){
        for(int j = 0 ; j<c ; j++){
            push(arr[i][j]);
        }
    }
    printf("\nROW MAJOR ORDER\n");
    for(int i = 0 ; i< max_s ; i++){
        printf("\n%d",stk[i]);
    }
}

void ColumnMajor(int r, int c, int arr[10][10]){
    
    for(int j = 0 ; j<c ; j++){
        for(int i = 0 ; i<r ; i++){
            push(arr[i][j]);
        }
    }
    printf("\nCOLUMN MAJOR ORDER\n");
    for(int i = 0 ; i< max_s ; i++){
        printf("\n%d",stk[i]);
    }
}

void main(){
    int arr[10][10], r, c;
    printf("\nENTER NO. OF ROWS AND COLUMNS");
    scanf("%d%d",&r,&c);
    max_s = 100;
    printf("\nENTER ARRAY ELEMENTS:");
    for(int i = 0 ; i<r ; i++){
        for(int j = 0 ; j<c ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    RowMajor(r,c,arr);
    ColumnMajor(r,c,arr);

}