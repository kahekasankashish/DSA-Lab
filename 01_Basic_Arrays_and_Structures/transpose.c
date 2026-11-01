/*
 * Question:
 * Write a C program to find the transpose of a matrix.
 */

#include<stdio.h>
void tran(int r,int c, int a[r][c]);
int main()
{
	int i,j,r,c;
	printf("enter r,c \n");
	scanf("%d %d",&r,&c);
	int a[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		printf("enter an element\n");
		scanf("%d",&a[i][j]);
		}
	}
	tran(r,c,a);
	return 0;
}
void tran(int r, int c, int a[r][c])
{
	int t[c][r],i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			t[j][i]=a[i][j];
		}
	}
	printf(" the transpose is\n");
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}

