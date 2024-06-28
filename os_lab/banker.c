/*
#include<stdio.h>
int main(){
    int n,m,p,k,i,j,flag;
    int status[n],reg[n];
    printf("\nENTER NO. OF PROCESSES:");
    scanf("%d",&n);
    printf("\nENTER NO. OF RESOURCES");
    scanf("%d",&m);
    int max[n][m],alloc[n][m],avail[m],need[n][m];
    printf("\nENTER MAX MATRIX");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++){
        scanf("%d",&max[i][j]);
    }
    printf("\nENTER ALLOCATION MATRIX");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++){
        scanf("%d",&alloc[i][j]);
    }
    printf("\nENTER AVAILABLE MATRIX");
    for(j=0;j<m;j++){
        scanf("%d",&avail[j]);
    }
    printf("\nNEED MATRIX");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++){
        need[i][j]=max[i][j]-alloc[i][j];
    }
    
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
        if(need[i][j]<=avail[j]){
                avail[j]+=alloc[i][j];
                status[i]=1;
                reg[k]=i;
                k++;
            }
            else{
                int flag=0;
            }
        }
    for(i=0;i<n;i++){
        if(status[i]==0){
            if(need[i][j]<=avail[j]){
                 for(i=0;i<n;i++)
                 for(j=0;j<m;j++){
                    if(need[i][j]<=avail[j]){
                    avail[j]+=alloc[i][j];
                    status[i]=1;
                    reg[k]=i;
                    k++;
            }
                 }
        }
    } 
    
    if (flag==0){
        printf("NO SAFE SEQUENCE");
    }
    else{
        for(i=0;i<n;i++){
            printf("P%d ",reg[i]);
        }

    }     
    }
        
return 0;   
}

#include <stdio.h>

int main() {
    int n, m, i, j, k = 0, flag = 1;
    printf("\nENTER NO. OF PROCESSES: ");
    scanf("%d", &n);
    printf("\nENTER NO. OF RESOURCES: ");
    scanf("%d", &m);
    
    int max[n][m], alloc[n][m], avail[m], need[n][m], status[n], reg[n];

    printf("\nENTER MAX MATRIX:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nENTER ALLOCATION MATRIX:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nENTER AVAILABLE MATRIX:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    printf("\nNEED MATRIX:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++) {
        status[i] = 0; // Initialize all processes as not finished
    }

    int count = 0;
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(status[i] == 0) { // Process is not finished
                flag = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 0; // If need is greater than available, break
                        break;
                    }
                }
                if(flag == 1) {
                    for(j = 0; j < m; j++) {
                        avail[j] += alloc[i][j]; // Releasing the resources
                    }
                    reg[count++] = i;
                    status[i] = 1; // Mark process as finished
                    found = 1;
                }
            }
        }
        if(found == 0) {
            printf("NO SAFE SEQUENCE\n");
            return 0;
        }
    }

    printf("SAFE SEQUENCE: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", reg[i]);
    }
    printf("\n");

    return 0;
}
*/
#include <stdio.h>

int main() {
    int n, m, i, j, k = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int max[n][m], alloc[n][m], avail[m], need[n][m], status[n], reg[n];

    printf("Enter max matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter available resources:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    for(i = 0; i < n; i++) 
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i = 0; i < n; i++)
        status[i] = 0; // All processes are initially unfinished

    int count = 0;
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(!status[i]) { // Process is not finished
                int canAllocate = 1;
                for(j = 0; j < m; j++)
                    if(need[i][j] > avail[j]) {
                        canAllocate = 0;
                        break;
                    }
                if(canAllocate) {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    reg[count++] = i;
                    status[i] = 1;
                    found = 1;
                }
            }  
        }
        if(!found) {
            printf("No safe sequence\n");
            return 0;
        }
    }

    printf("Safe sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", reg[i]);
    printf("\n");

    return 0;
}