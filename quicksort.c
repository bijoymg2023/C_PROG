
#include<stdio.h>
void quicksort(int A[25],int low,int high)
{
   int i, j, pivot, temp;
   if(low<high){
      pivot=low;
      i=low;
      j=high;
      while(i<j){
         while(A[i]<=A[pivot]&&i<high)
         i++;
         while(A[j]>A[pivot])
         j--;
         if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
         }
      }
      temp=A[pivot];
      A[pivot]=A[j];
      A[j]=temp;
      quicksort(A,low,j-1);
      quicksort(A,j+1,high);
   }
}
int main(){
   int i, n, A[25];
   printf("How many elements are u going to enter?: ");
   scanf("%d",&n);
   printf("Enter elements");
   for(i=0;i<n;i++)
   scanf("%d",&A[i]);
   quicksort(A,0,n-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
   printf(" %d",A[i]);
   return 0;
}