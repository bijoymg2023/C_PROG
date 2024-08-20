#include<stdio.h>
#include<stdlib.h>
void fcfs(int request[],int head,int n){
    int total_distance=0;
    int curr_pos=head;
    printf("DISK REQUESTS SEQUENCE\n");
    for(int i=0;i<n;i++){
        printf("%d ",request[i]);
        total_distance+=abs(curr_pos-request[i]);
        curr_pos=request[i];
    }
    printf("\nTOTAL HEAD MOVEMENT:%d\n",total_distance);
}
int main(){
    int head,n;
    printf("ENTER NO. OF DISK REQUESTS\n");
    scanf("%d",&n);
    int request[n];
    printf("ENTER REQUEST REQUESTS\n");
    for(int i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    printf("ENTER HEAD POSITION\n");
    scanf("%d",&head);
    fcfs(request,head,n);
    return 0;
}