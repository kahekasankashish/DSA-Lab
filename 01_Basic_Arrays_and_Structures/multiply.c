/*
 * Question:
 * Write a C program to multiply two matrices after checking whether matrix multiplication is possible.
 */

#include<stdio.h>
void mult( int r1, int c1,int r2,int c2, int a[r1][c1], int b[r2][c2]);
int main()
{
	int r1,c1,r2,c2,i,j;
	printf("enter r1,c1,r2,c2\n");
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	if(c1!=r2)
	{
		printf("not possible\n");
	}
	else
	{
	int a[r1][c1], b[r2][c2];
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
		printf("enter the element of 1rst array\n");
		scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("enter the element of 2nd array\n");
			scanf("%d",&b[i][j]);
		}
	}
	mult(r1,c1,r2,c2,a,b);
	}
	return 0;
}
void mult( int r1, int c1,int r2,int c2, int a[r1][c1], int b[r2][c2])
{
	int c[r1][c2],i,j,k;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			c[i][j]=0;
			for(k=0;k<c1;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf(" the resultant matrix is:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d \t",c[i][j]);
		}
		printf("\n");
	}
}


