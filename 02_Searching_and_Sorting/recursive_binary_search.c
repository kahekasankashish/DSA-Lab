/*
 * Question: Write a C program to search for an element in a sorted array using recursive binary search.
 */
#include<stdio.h>
int binary(int l,int r,int arr[],int n, int x);
int main()
{
	int n,x,l=0;
	printf("enter n,x\n");
	scanf("%d %d",&n,&x);
	int a[n],i,r=n-1;
	for(i=0;i<n;i++)
	{
		printf("enter a no,\n");
		scanf("%d",&a[i]);
	}
	int p=binary(l,r,a,n,x);
	if(p<-1)
	{
		printf("not found\n");
	}
	else
	{
		printf("%d",p);
	}
	

	return 0;
}
int binary(int l,int r,int arr[],int n, int x)
{
	if(l>r)
	{
		return -1;
	}
	int mid=(l+r)/2;
	if(arr[mid]==x)
	{
		return mid;
	}
	else if(arr[mid]<x)
	{
		l=mid+1;
		return binary(l,r,arr,n,x);
	}
	else
	{
		r=mid-1;
		 return binary(l,r,arr,n,x);
	}
	
	return -1;
}
