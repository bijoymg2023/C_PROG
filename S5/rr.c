#include<stdio.h>
struct process
{
int id,at,bt,ct,tat,wt,rt;
}k;
struct pro
{
int id,st,ct;
};
int main()
{
int n,i,j,sum=0,completed=0,ct=0,l=0,qt;
float ttat=0,twt=0;
printf("Enter the number of processes:");
scanf("%d",&n);
struct process p[n];
printf("Enter the time quantum:");
scanf("%d",&qt);
struct pro pp[100];
for(i=0;i<n;i++)
{
printf("Enter process id:");
scanf("%d",&p[i].id);
printf("Enter arrival time:");
scanf("%d",&p[i].at);
printf("Enter burst time:");
scanf("%d",&p[i].bt);
p[i].rt=p[i].bt;


}
for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(p[j].at>p[j+1].at)
{
k=p[j];
p[j]=p[j+1];
p[j+1]=k;
}
}
}
i=0;
while(completed<n)
{
if(ct<p[i].at)
{
ct=p[i].at;
pp[l].ct=ct;
pp[l].st=1;
pp[l].id=-1;
l++;
}
else
{
if(p[i].rt!=0)
{
if(p[i].rt>qt)
{
ct=ct+qt;
p[i].rt=p[i].rt-qt;
p[i].ct=ct;
pp[l].ct=ct;
pp[l].st=0;
pp[l].id=p[i].id;
l++;
}
else
{
ct=ct+p[i].rt;
p[i].rt=0;
completed++;
p[i].ct=ct;
pp[l].ct=ct;
pp[l].st=0;
pp[l].id=p[i].id;
l++;
}
}
i=(i+1)%n;
}
}
for(i=0;i<n;i++)
{
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
ttat=ttat+p[i].tat;
twt=twt+p[i].wt;
}
printf("\n");
printf("\nTable\n|\tProcess|\tAT|\tBT|\tCT|\tTAT|\tWT  |\n");
for(i=0;i<n;i++)
{
 
 printf("\tP%d\t\t%d\t%d\t%d\t%d\t%d  \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}
printf("\n");
printf("\nAverage TAT %f",ttat/n);
printf("\nAverage WT %f",twt/n);

printf("\n");
printf("GANTT CHART\n|");
for(i=0;i<l;i++)
{
if(pp[i].st==1)
{

printf("Idle\t|");
}
else
{

printf("P%d\t|",pp[i].id);
}
}
printf("\n0\t");
for(i=0;i<l;i++)
printf("%d\t",pp[i].ct);
for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(p[j].id>p[j+1].id)
{
k=p[j];
p[j]=p[j+1];
p[j+1]=k;
}
}
}

}