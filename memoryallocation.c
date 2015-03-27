#include<stdio.h>

void main()
{
	int i,j,p,m,ch,a,k;
	int flag=0,bst=0,wst=0,frag=0,total=0;

	printf("\n Enter the number of processes ");
	scanf("%d",&p);
	printf("\n Enter the number of memory blocks ");
	scanf("%d",&m);
	
	int memr[m];
	int prc[p];
	
	for(i=0;i<m;i++)
	{
		printf("\nEnter size of memory block %d ",i);
		scanf("%d",&memr[i]);
	}
	
	for(i=0;i<p;i++)
	{
		printf("\nEnter size of process %d ",i);
		scanf("%d",&prc[i]);
	}
	
	for(i=0;i<m;i++)
	{
		total=total+memr[i];
	}
	
	printf("\n Choose the algorithm you want to apply");
	printf("\n 1.First Fit");
	printf("\n 2.Best Fit");
	printf("\n 3.Worst Fit");
	printf("\n 4.Quit \n");
	scanf("%d",&ch);
		
	switch(ch)
	{
		
		//first fit//
		case 1:
		for(i=0;i<p;i++)
		{
		flag=0;
			for(j=0;j<m;j++)
			{
				if(prc[i]<=memr[j])
				{
					memr[j]=memr[j]-prc[i];
					flag=1;
					break;
				}
			}
			if(flag==1)
			printf("\nProcess %d is allocated to memory block %d",i,j);
		}
		
		//best fit//
		case 2:
		for(i=0;i<p;i++)
		{
		flag=0;
			for(j=0;j<m;j++)
			{
				if(prc[i]<=memr[j])
				{
					if(flag==0)
					bst=memr[j];
					
					if(memr[j]<=bst)
					{
						flag=1;
						bst=memr[j];
						k=j;
					}
					
				}
	
			}
			
			if(flag==0)
			printf("\nProcess %d cannot be allocated",i);	
		
			else
			{
				memr[k]=memr[k]-prc[i];
				printf("\nProcess %d is allocated to memory block %d \n",i,k);		
			}
		
		}
		
		
		//worst fit//	
		case 3:
		for(i=0;i<p;i++)
		{
		flag=0;
			for(j=0;j<m;j++)
			{
				if(prc[i]<=memr[j])
				{
					if(flag==0)
					wst=memr[j];
					
					if(memr[j]>=wst)
					{
						flag=1;
						wst=memr[j];
						k=j;
					}
					
				}
	
			}
			
			if(flag==0)
			printf("\nProcess %d cannot be allocated",i);	
		
			else
			{
				memr[k]=memr[k]-prc[i];
				printf("\nProcess %d is allocated to memory block %d \n",i,k);		
			}
		
		}
		
			
		case 4:
		return 0;
			
		default:
		printf("\nWrong choice. Please enter again");
		
	}
	
	//fragmentation//
	for(i=0;i<m;i++)
	{
		frag = memr[i]+frag;
	}
	
	printf("\nTotal memory : %d ",total);
	printf("\nFragmentation : %d ",frag);
	
	return 0;
}
