#include<stdio.h>
 
struct process{
    int pid,bt,at,ct,tat,wt,status,pt;
};

int main(){
    struct process p[100];
    int n,i,j,completed=0,min_pt,index,curr_time=0;
    float t_tat=0,t_wt=0,avg_tat,avg_wt;
    printf("Enter the no of process \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter the arrival time,burst time and priority\n");
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
        p[i].status=0;
    }
    while(completed!=n){
        min_pt=32767;  
        index=-1;
        for(i=0;i<n;i++){
            if((p[i].at<=curr_time)&&(p[i].status==0)){
                if(min_pt>p[i].pt){ 
                    min_pt=p[i].pt;
                    index=i;
                }
            }
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
    printf("Pid\tAT\tBT\tPT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("\n");
    printf("GANTT CHART\n");
    printf(".................................................................\n");
    printf("|\t");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].pt > p[j+1].pt) {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("P%d|\t", p[i].pid);
    }
    printf("\n");
    printf("%d\t ", p[0].at);
    for (i = 0; i < n; i++) {
        printf("%d\t", p[i].ct);
    }
    printf("Total turnaround time %f\n",t_tat);
    printf("Average turnaround time %f\n",avg_tat);
    printf("Total waiting time %f\n",t_wt);
    printf("Average waiting time %f\n",avg_wt);

   
}