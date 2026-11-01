/*
 * Question:
 * Write a C program to convert a sparse matrix into its triplet representation.
 */
#include<stdio.h>
int main()
{
	int r,c,i,j;
	printf("enter size of sparse matrix\n");
	scanf("%d %d",&r,&c);
	int spm[r][c],count=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("enter an element\n");
			scanf("%d",&spm[i][j]);
			if(spm[i][j]!=0)
			{
				count++;
			}
		}
	}
	printf("sparse matrix is:\n");
	 for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf("%d\t",spm[i][j]);
                 }
		printf("\n");
	}

	int trip[count+1][3];
	trip[0][0]=r;
	trip[0][1]=c;
	trip[0][2]=count;
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
	printf("the triplet representation is:\n");
	for(i=0;i<=count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",trip[i][j]);
		}
		printf("\n");
	}
	return 0;
}

