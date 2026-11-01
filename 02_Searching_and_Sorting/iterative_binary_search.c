/*
 * Question: Write a C program to search for an element in a sorted array using iterative binary search.
 */
#include<stdio.h>
int binary(int arr[],int n, int x);
int main()
{
	int n,x;
	printf("enter n,x\n");
	scanf("%d %d",&n,&x);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		printf("enter a no,\n");
		scanf("%d",&a[i]);
	}
	int p=binary(a,n,x);
	if(p==-1)
	{
		printf("not found\n");
	}
	else
	{
		printf("position is:%d\n",p);
	}
	return 0;
}
int binary(int arr[],int n, int x)
{
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid]<x)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}

	}
	return -1;
}
