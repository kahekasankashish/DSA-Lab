/*
 * Question:
 * Write a C program to find the transpose of a sparse matrix represented in triplet form.
 */
#include<stdio.h>
int main()
{
	int trip[10][3],tran[10][3],i,j,nze;
	printf("enter no. of non zero element\n");
	scanf("%d",&nze);
	for(i=0;i<=nze;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("enter\n");
			scanf("%d",&trip[i][j]);
		}
	}
	//int tran[nze+1][3];
	tran[0][0]=trip[0][1];
	tran[0][1]=trip[0][0];
	tran[0][2]=trip[0][2];
	int k=1;
	for(i=0;i<trip[0][1];i++)
	{
		for(j=1;j<=trip[0][2];j++)
		{
			if(trip[j][1]==i)
			{
				tran[k][0]=i;
				tran[k][1]=trip[j][0];
				tran[k][2]=trip[j][2];
				k++;
			}
		}
	}
	printf("the transpose is:\n");
	for(i=0;i<=trip[0][2];i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",tran[i][j]);
		}
		printf("\n");
	}
	return 0;
}

