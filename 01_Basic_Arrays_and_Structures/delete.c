/*
 * Question:
 * Write a C program to delete an element from a specified position in an array.
 */

#include<stdio.h>
int main()
{
	int n,p,i;
	printf("enter n,p\n");
	scanf("%d %d",&n,&p);
	int a[n];
	if(p>n || p<1)
	{
		printf("not possible\n");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf("enter an element\n");
			scanf("%d",&a[i]);
		}
		for(i=p-1;i<n-1;i++)
		{
			a[i]=a[i+1];
		}
		n--;
		printf("modified array is:\n");
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}
