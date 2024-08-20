
#include<stdio.h>
 
struct process{
int pid,bt,at,ct,tat,wt,status;
};

int main(){
   struct process p[100];
   int n,i,j,completed=0,min_bst,index,curr_time=0;
   float t_tat=0,t_wt=0,avg_tat,avg_wt;
   printf("Enter the no of process \n");
   scanf("%d",&n);
   for(i=0;i<n;i++){
     p[i].pid=i+1; 
     printf("Enter the arrival time and burst time \n%d ",p[i].pid);
     scanf("%d%d",&p[i].at,&p[i].bt);
     p[i].status=0;
   }
   while(completed!=n){
     min_bst=32765;
     index=-1;
     for(i=0;i<n;i++){
     if((p[i].at<=curr_time)&&(p[i].status==0)){
       if(min_bst>p[i].bt){
        min_bst=p[i].bt;
        index=i;
     }}
     }
      if(index==-1){
       curr_time++;
   }
   else{
    curr_time=curr_time+p[index].bt;
    p[index].ct=curr_time;
    p[index].status=1;
    completed++;
    }
   }
   for(i=0;i<n;i++){
     p[i].tat=p[i].ct-p[i].at;
     t_tat+=p[i].tat;
     p[i].wt=p[i].tat-p[i].bt;
     t_wt+=p[i].wt;
     }
     avg_tat=t_tat/n;
     avg_wt=t_wt/n;
     printf("The process details are \n");
     printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
     for(i=0;i<n;i++){
     printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
     }
     printf("Total TAT is %f\n",t_tat);
     printf("Average TAT is %f\n",avg_tat);
     printf("Average WT is %f\n",avg_wt);
     printf("Total WT is %f\n",t_wt);
     printf("\n");
     printf("Gantt chart\n");
     for (int i = 0; i < n; i++) {
     for (int j = 0; j < n - i - 1; j++) {
     if (p[j].ct > p[j+1].ct) {
       struct process temp = p[j];
       p[j] = p[j+1];
       p[j+1] = temp;
     }
    }
    }
    for (i = 0; i < n; i++) {
    printf(" P%d|  ", p[i].pid);
   }
   printf("\n");
   printf("%d ", p[0].at);
   for (i = 0; i < n; i++) {
   printf("  %d  ", p[i].ct);
   }
  
  }