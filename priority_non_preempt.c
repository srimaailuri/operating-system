#include <stdio.h>
#define max 30
void main(){
    int i,n,j,bt[max],wt[max],pr[max],tat[max],pos,t;
    float awt=0,atat=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("Enter burst time of process:");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Enter priority time of process:");
    for(i=0;i<n;i++){
        scanf("%d",&pr[i]);
    }
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(pr[j]<pr[pos]){
                pos=j;
            }
        }
        t=pr[i];
        pr[i]=pr[pos];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;
    }
    wt[0]=0;
    printf("process\tbursttime\tpriority\twaiting time\t\t turnaroundtime\n");
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
                tat[i]=wt[i]+bt[i];
                awt=awt+wt[i];
                atat=atat+tat[i];
                printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],pr[i],wt[i],tat[i]);
            }
            awt=awt/n;
            atat=atat/n;
            printf("Averaage waiting time=%f",awt);
            printf("Average turnaround time=%f",atat);
}