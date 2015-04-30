#include<stdio.h>

void main()
{

int n_pr,prwait;
int i;

printf("\n Enter the number of processes:");
scanf("%d",&n_pr);

int exec[n_pr],abs_start[n_pr],abs_deadline[n_pr];
int flag[n_pr];

for(i=0;i<n_pr;i++)
{
    flag[n_pr] = 0;
}

for(i=0;i<n_pr;i++)
{
 	printf("\n Enter absolute absolute start time, exec time and absolute deadline for process %d:",i+1);
    scanf("%d %d %d",&abs_start[i],&exec[i],&abs_deadline[i]);
}

prwait = 0;

int ind=-1;
int cnt=0;

int t_quantum=0;
int small_slack=10000;

int condition_f=1;

while(condition_f)
{
    for(i=0;i<n_pr;i++)
	{
        if(abs_start[i]==t_quantum || exec[ind]==0)
		{
			if(flag[i]!=1)
			{
				if(((abs_deadline[i]-t_quantum)-exec[i])<small_slack)
				{
					small_slack=(abs_deadline[i]-t_quantum);
					ind=i;
				}
			}
		}
	}

	if(exec[ind]==0)
    {
        small_slack=10000;
		ind=-1;
	}

	if(ind!=-1)
	{
        printf("\n From time quantum %d to %d, process %d", t_quantum,t_quantum+1,ind+1);
        exec[ind]--;

        if(exec[ind]==0)
        {
            flag[ind]=1;
            cnt++;
        }
	}

	if(cnt==n_pr)
    condition_f=0;

    t_quantum++;
    }
}
