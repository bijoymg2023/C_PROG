#include<stdio.h>
struct process{
int id,at,bt,ct,tat,wt;
}p[20];
int main()
{
int n,i=0,j=0,temp,flag;
float ttat=0,twt=0;
printf("Enter the number of the process : \n");
scanf("%d",&n);
printf("Enter the details of the process\n");
for(i=0;i<n;i++)
{
p[i].id=i+1;
printf("Enter the Arrival time and Burst time of process %d : ",p[i].id);
scanf("%d%d",&p[i].at,&p[i].bt);
}


for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(p[i].at>p[i+1].at)
{
temp=p[i].id;
p[i].id=p[i+1].id;
p[i+1].id=temp; 

temp=p[i].at;
p[i].at=p[i+1].at;
p[i+1].at=temp;

temp=p[i].bt;
p[i].bt=p[i+1].bt;
p[i+1].bt=temp;

}
}}
p[0].ct=p[0].at+p[0].bt;

for(i=0;i<n;i++)
{
if(p[i].at<p[i-1].ct)
{
p[i].ct=p[i-1].ct+p[i].bt;
}
else
{
p[i].ct=p[i].at+p[i].bt;
}
}

for(i=0;i<n;i++)
{
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
ttat=ttat+p[i].tat;
twt=twt+p[i].wt;
}

printf("\n\nThe deatails of process\n");
printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");

for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);


}
printf("The total turnaround time is %f\n",ttat);
printf("The total waiting time is %f\n",twt);
printf("The average turnaround time is %f\n",ttat/n);
printf("The average waiting time is %f\n",twt/n);
printf("\nGantt chart\n");
printf("\n |");
for(i=0;i<n;i++){
if(p[i].at==0){
flag=1;
}
}
if(flag==1){
for(i=0;i<n;i++)
{
printf(" P%d\t| ",p[i].id);
}
printf("\n 0");
for(i=0;i<n;i++){
printf(" \t%d ",p[i].ct );}
printf("\n");
}
else {
printf("\t|");
for(i=0;i<n;i++) {
printf(" P%d\t| ",p[i].id);
}
printf("\n");
printf(" 0\t%d",p[0].at);
for(i=0;i<n;i++){
printf(" \t%d ",p[i].ct );
}
printf("\n");
}}