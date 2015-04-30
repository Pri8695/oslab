#include<stdio.h>

int main()
{
	int n,avwt=0,avtt=0,i,j;
    printf("\n Enter the total number of process");
    scanf("%d",&n);
	int bt[n],wt[n],tt[n];
	printf("\n Enter the Process Burst Time \n");
    for(i=0;i<n;i++)
    {
		printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    //wait time calculation
    for(i=1;i<n;i++)
    {
		wt[i]=0;
        for(j=0;j<i;j++)
		{
            wt[i]+=bt[j];
		}
    }

	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    //turnaround time calculation
    for(i=0;i<n;i++)
    {
        tt[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtt+=tt[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tt[i]);
    }

    avwt/=i;
    avtt/=i;
    printf("\n Average wait time is :%d",avwt);
    printf("\n Average turnaround time is :%d",avtt);

    return 0;

}
