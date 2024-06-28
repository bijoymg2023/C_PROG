
//ghant chart problem

#include<stdio.h>

struct process{
    int pid,at,bt,ct,tat,wt;
}p[100],k;

void main(){
    int n,i,j,sum=0,t_tat=0,t_wt=0,c;
    printf("Enter No of Processes:");
    scanf("%d",&n);
    printf("Enter pid,at,bt\n");
    for(i=0;i<n;i++){
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
    }
    for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++){
        if(p[j].at>p[j+1].at){
            k=p[j];
            p[j+1]=p[j];
            p[j]=k;
        }
    }
    for(i=0;i<n;i++){
        if(sum==0){
            sum=p[i].bt;
        }
        else{
            sum+=p[i].bt;
        }
        p[i].ct=sum;
    }
    for(i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        t_tat+=p[i].tat;
        t_wt+=p[i].wt;
    }
    printf("TOTAL TAT:%d\n",t_tat);
    printf("AVG TAT:%d\n",t_tat/n);
    printf("TOTAL WT:%d\n",t_wt);
    printf("AVG WT:%d",t_wt/n);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    c=0;
    printf("\nGhantt Chart\n");
    /*
    for(i=0;i<n;i++){
        printf("|");
        while(c<p[i].ct){
            printf(" ");
            c++;
        }
        printf("P%d",p[i].pid);
        if((i+1)==n){
            printf("|");
        }
    }
    printf("\n");
    c=0;
    for(i=0;i<n;i++){
        if(i!=0){
            while(c<p[i].ct){
                printf(" ");
                c++;
            }
            printf("%d",p[i].ct);
        }
        else{
            printf("0");
            while(c<p[0].ct){
                printf(" ");
                c++;
            }
            printf("%d",p[i].ct);

        }
    }
*/
    printf("|");
    for(i=0;i<n;i++){
        printf(" P%d |",p[i].pid);
    }
    printf("\n");
    printf("0");
    for(i=0;i<n;i++){
        printf("    %d",p[i].ct);
    }
}