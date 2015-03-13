#include<stdio.h>

void main()
{

int p,r,i,j;

printf("Enter the number of processes");
scanf("%d",&p);
printf("Enter the number or resources");
scanf("%d",&r);


//Current Allocation Matrix

int curr[p][r];

printf("Enter the current allocation matrix\n");
for (i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	scanf("\n %d",&curr[i][j]);
	}
}

printf("\nthe current allocation matrix\n");
for ( i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	printf("%d \t" ,curr[i][j]);
	}
	printf("\n");
}


//Maximum Allocation Matrix

int max[p][r];

printf("Enter the maximum allocation matrix\n");
for (i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	scanf("\n %d",&max[i][j]);
	}
}

printf("\nthe maximum allocation matrix \n");
for ( i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	printf("%d \t" ,max[i][j]);
	}
	printf("\n");
}


//Total resources

int total[r];

printf("\nEnter the total available resources\n");
for(i=0; i<r; i++)
{
	scanf("%d",&total[i]);
}

printf("\nThe total available resources\n");
for(i=0; i<r; i++)
{
	printf("%d \n",total[i]);
} 


//Available resources 

int avail[r];

printf("\nEnter the available resources\n");
for(i=0; i<r; i++)
{
	scanf("%d",&avail[i]);
}

printf("\nThe available resources\n");
for(i=0; i<r; i++)
{
	printf("%d \n",avail[i]);
}


//Need matrix

int need[p][r];

for ( i=0; i<p; i++)
{

	for (j=0; j<r; j++)
	{

	need[i][j]= max[i][j]-curr[i][j];
	}
	printf("\n");
}
printf("\nThe need matrix is\n");
for ( i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{

	printf("%d \t",need[i][j]);
	}
	printf("\n");
}


//intialization

int cnt=0;
int a=0;
int k,b;
int safe[p];
int dead[p];


//making the deadlock matrix zero


for(i=0;i<p;i++)
{
	dead[i] = 0;
}


//figuring out deadlock and safe states

for(i=0;i<p;i++)
{
	cnt=0;
	for(j=0;j<r;j++)
	{ 
		if(need[i][j]<=avail[j])
		cnt++;
	}
	if(cnt==r)
	{
	safe[a]=i+1;	
	a++;
	for(k =0; k<r; k++)
	{
		avail[k] = avail[k] + curr[i][k];
		need[i][k] = 0;
	}
	}
	else
	{
	dead[b]=i+1;
	b++;
	}
}

int cnt1=0;

if(b!=0 && b!=1)
{
	while(b>1)
	{
		for(i=0;i<b;i++)
		{
			if(j<0)
			{
			i++;
			j=dead[i]-1;
			}
			else
			j=dead[i]-1;
	
			for(k=0;k<r;k++)
			{
				if(need[j][k]<=avail[k])
				cnt++;
			}
		
			if(cnt==r)
			{
				safe[a]=j+1;
				a++;
		
				for(k =0; k<r; k++)
				{
					avail[k] = avail[k] + curr[i][k];
					need[i][k] = 0;
				}
				dead[i]=0;
			}
		
			else
			{
				cnt1++;
				dead[i]=j+1;	
			}
		}
		b=cnt1;
	}
}

else if(b==1)
{
	printf("\nThe safe states are:\n");
	for(k =0; k<a; k++)
	{
		printf("%d \t",safe[k]);
	}

	printf("\nThe state creating deadlock is %d \n",dead[0]);
}

else if(b==0)
{
	for(k =0; k<a; k++)
	{
		printf("\nSafe state order %d \t",safe[k]);
	}
}


}


