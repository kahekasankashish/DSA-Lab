/*
 * Question:
 * Write a C program to merge two arrays into a single array.
 */

#include<stdio.h>
int main()
{
	int i,j,m,n;
	printf("enter the sizes of two arrays\n");
	scanf("%d %d",&n,&m);
	int a[n],b[m],c[m+n];
	for(i=0;i<n;i++)
	{
		printf("enter the element of 1rst array\n");
		scanf("%d",&a[i]);
	}
	for(j=0;j<m;j++)
	{
		printf("enter the element of 2nd array\n");
		scanf("%d",&b[j]);
	}
	for(i=0;i<n;i++)
	{
		c[i]=a[i];
	}
	for(j=0;j<m;j++,i++)
	{
		c[i]=b[j];
	}
	printf("the resultant array is:\n");
	for(i=0;i<(m+n);i++)
	{
		printf("%d\n",c[i]);
	}
	return 0;
}


