/*
 * Question:
 * Write a menu-driven C program to create a sparse matrix, generate its triplet representation, find its transpose, and check whether it is sparse.
 */
#include<stdio.h>
#include<stdlib.h>
void createspm();
void triplet();
void transpose();
void checkspm();
int spm[20][20];
int trip[20][3];
int tran[20][3];
int r,c;
int main()
{
	int ch;
	while(1)
	{
		printf("Sparse matrix operation\n");
		printf("------------------------\n");
		printf("1: create spm\n2:triplet matrix\n3:transpose matrix\n4:check spm\n5:exit\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("case1:\n");
				createspm();
				break;
			case 2:
				printf("case2:\n");
				triplet();
				break;
			case 3:
				printf("case 3:\n");
				transpose();
				break;
			case 4:
				printf("case 4:\n");
				checkspm();
				break;
			case 5:
				exit(0);
			default:
				printf("invalid choice\n");
		}
	}
}
void createspm()
{
	int i,j;
	printf("enter rows and columns no.\n");
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("enter an element\n");
			scanf("%d",&spm[i][j]);
		}
	}
	printf("the sparse matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",spm[i][j]);
		}
		printf("\n");
	}
}
void triplet()
{
	int i,j,l=0;
        printf("enter rows and columns no.\n");
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf("enter an element\n");
                        scanf("%d",&spm[i][j]);
			if(spm[i][j]!=0)
			{
				l++;
			}
                }
        }
trip[0][0]=r;
trip[0][1]=c;
trip[0][2]=l;
int k=1;
for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{
		if(spm[i][j]!=0)
		{
			trip[k][0]=i;
			trip[k][1]=j;
			trip[k][2]=spm[i][j];
			k++;
		}
	}
}
printf("triplet matrix is\n");
for(i=0;i<=l;i++)
{
	for(j=0;j<3;j++)
	{
		printf("%d\t",trip[i][j]);
	}
	printf("\n");

}
}
void transpose()
{
	int i,j,n;
	printf("enter total no. of non zero nos.\n");
	scanf("%d",&n);
	printf("enter the elements of triplet matrix\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&trip[i][j]);
		}
	}
	tran[0][0]=trip[0][1];
	tran[0][1]=trip[0][0];
	tran[0][2]=trip[0][2];
	n=trip[0][2];
	int k=1;
	for(i=0;i<trip[0][1];i++)
	{
		for(j=1;j<=n;j++)
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
	printf("transpose matrix is:\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",tran[i][j]);
		}
		printf("\n");
	}
}
			
void checkspm()
{
	  int i,j,l=0;
        printf("enter rows and columns no.\n");
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf("enter an element\n");
                        scanf("%d",&spm[i][j]);
			if(spm[i][j]==0)
			{
				l++;
			}
                }
        }
	if(l>((r*c)/2))
	{
		printf("sparse\n");
	}
	else
	{
		printf("not sparse\n");
	}
}


