#include<stdio.h>

void BinarySearch(int n,int a[], int b){
    int mid , low , high, flag = 1;
    low = 0;
    high = n-1;
    a[n];
    while(low <= high){
        mid = (low + high)/2;
        if (a[mid] == b){
            flag = 0;
            printf("\nELEMENT FOUND AT POSITION %d",mid+1);
            break;
        }
        else if(a[mid]<b){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    if(flag == 1){
        printf("\nELEMENT NOT FOUND");
    }

}
void main(){
    int n, key;
    printf("\nENTER ARRAY SIZE");
    scanf("%d",&n);
    int arr[n];
    printf("\nENTER ARRAY ELEMENTS:");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nENTER ELEMENT TO SEARCH:");
    scanf("%d",&key);
    BinarySearch(n,arr,key);

}