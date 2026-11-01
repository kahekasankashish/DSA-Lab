/*
 * Question:
 * Write a C program to insert an element at a specified position in an array.
 */

#include<stdio.h>
int main()
{
	int n,i,x,p,a[30];
	printf("enter n,x,p\n");
	scanf("%d %d %d",&n, &x, &p);
	if(p>n || p<1)
	{
		printf(" insertion not possible\n");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf("enter an element\n");
			scanf("%d",&a[i]);
		}
		for(i=n;i>=p;i--)
		{
			a[i]=a[i-1];
		}
		a[p-1]=x;
		n++;
		printf("the modified array is:\n");
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}
