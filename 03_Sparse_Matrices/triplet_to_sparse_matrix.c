/*
 * Question:
 * Write a C program to convert a sparse matrix in triplet representation back into its normal matrix form.
 */
#include<stdio.h>
int main()
{
	int spm[10][10],trip[10][3],nze,i,j,r,c;
	printf("enter the total no. of non zero elements\n");
	scanf("%d",&nze);
	for(i=0;i<=nze;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("enter element\n");
			scanf("%d",&trip[i][j]);
		}
	}
	printf("triplet matrix is:\n");
	for(i=0;i<=nze;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d",trip[i][j]);
		}
		printf("\n");
	}
	r=trip[0][0];
	c=trip[0][1];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			spm[i][j]=0;
		}
	}
	for(i=1;i<=nze;i++)
	{
		int ri=trip[i][0];
		int ci=trip[i][1];
		spm[ri][ci]=trip[i][2];
	}
	printf("the sparse matrix is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",spm[i][j]);
		}
		printf("\n");
	}
	return 0;
}
