#include<stdio.h>
void main(){
    int i,n,m,page[100],frame[10],flag,count=0,l,index,f[10],k=0,min,j;
    printf("Enter frame size");
    scanf("%d",&n);
    printf("Enter reference size");
    scanf("%d",&m);
    printf("Enter refrence string");
    for(i=0;i<m;i++){
        scanf("%d",&page[i]);

    }
    for(i=0;i<m;i++)
    {
        flag=0;
        for(l=0;l<count;l++)
        {
            if(page[i]==frame[l])
            {
                flag=1;
                index=l;
                break;
            }
        }
        if(flag==1)
        {
            printf("Page already \n");
            f[index]=i;
        }
        else
        {
            if(count<n)
            {
                frame[count]=page[i];
                f[count++]=i;
                for(j=0;j<count;j++)
                    printf("%d ",frame[j]);
                printf("\n");
            }
            else
            {
                min=m+1;
                for(j=0;j<n;j++)
                {
                    if(min>f[j])
                    {
                        min=f[j];
                        index=j;
                    }
                }
                frame[index]=page[i];
                f[index]=i;
                 for(j=0;j<count;j++)
                    printf("%d ",frame[j]);
                printf("\n");
            }
            k++;
        }

    }
    printf("Page fault is %d",k);
}