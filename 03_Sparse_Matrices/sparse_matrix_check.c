/*
 * Question:
 * Write a C program to check whether a given matrix is a sparse matrix.
 */
#include<stdio.h>
int main()
{
	int i,j,r,c;
	printf("enter rows and columns no.\n");
	scanf("%d %d",&r,&c);
	int spm[r][c],count=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("enter a no.\n");
			scanf("%d",&spm[i][j]);
			if(spm[i][j]==0)
			{
				count++;
			}
		}
	}
	if(count>((r*c)/2))
	{
		printf("sparse\n");
	}
	else
	{
		printf("not sparse\n");
	}
	return 0;
}

	
