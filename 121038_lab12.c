#include<stdio.h>

void main()
{

int i;
int pr,prwait;

printf("\n Enter the number of processes:");
scanf("%d",&pr);

int exc[pr],strt[pr],ddline[pr];
int flag[pr];

for(i=0;i<pr;i++)
    flag[pr] = 0;

prwait = 0;

for(i=0;i<pr;i++)
{
    printf("\n Enter absolute start time, execution time and absolute deadline for process %d:",i+1);
 	scanf("%d %d %d",&strt[i],&exc[i],&ddline[i]);
}

int tquatum=0;
int efalse=1;
int ndeadline=10000;
int ind=-1;
int cnt=0;

while(efalse)
{
	for(i = 0;i< pr;i++)
	{
		if(strt[i]==tquatum || exc[ind]==0)
		{
			if(flag[i]!=1)
			{
				if((ddline[i]-tquatum)<ndeadline)
				{
                    ndeadline=(ddline[i]-tquatum);
					ind=i;
				}
			}
		}


	}

    if(exc[ind]==0)
    {
        ndeadline = 10000;
        ind=-1;
    }

	if(ind!=-1)
	{
        printf("\n from time quantum %d to %d, proc %d",tquatum,tquatum+1,ind+1);
        exc[ind]--;

        if(exc[ind]==0)
        {
            flag[ind]=1;
            cnt++;
        }
	}

	if(cnt == pr)
		efalse=0;

    tquatum++;
 }
}
