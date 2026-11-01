/*
 * Question: Write a C program to search for an element in an array using recursive linear search.
 */
#include<stdio.h>
int linear(int arr[],int n, int x);
int main()
{
	int n,i,x;
	printf("enter n,x\n");
	scanf("%d %d",&n,&x);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("enter a no.\n");
		scanf("%d",&a[i]);
	}
	int p=linear(a,n,x);
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
int linear(int arr[],int n, int x)
{
	if(n==0)
	{
		return -1;
	}
	else if(arr[n-1]==x)
	{
		return n-1;
	}
	else
	{
		return linear(arr,n-1,x);
	}
}



