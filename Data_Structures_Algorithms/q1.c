//Given a matrix A of size m x n, write a function that returns the sum of elements below the main diagonal, i.e those elements a ij for which i>j

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,m,n,sum=0,dsum=0;
	printf("\nEnter the size of Row : ");
	scanf("%d",&m);
	
	printf("\nEnter Size of Column : ");
	scanf("%d",&n);
	
	int **a=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	{
		a[i]=(int*)malloc(n*sizeof(int));
	}
	
	//Enter Matrix Elements
	printf("\nEnter an Array : ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}	
	}
	
	//Printing Matrix Elements
	//printf("\n-------------------------------------");
	printf("\n-----------Matrix Elements-----------\n\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("      %d   ",a[i][j]);
			if(i==j)
			{
				dsum=dsum+a[i][j];
			}
			if(i>j)
			{
				sum=sum+a[i][j];
			}
		}
		printf("\n");
	}
	printf("\n-------------------------------------");
	printf("\nSum of Elements Below Diagonal : %d",sum);
	printf("\n-------------------------------------\n\n");
	return 0;
}
