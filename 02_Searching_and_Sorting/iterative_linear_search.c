/*
 * Question: Write a C program to search for an element in an array using iterative linear search.
 */
#include<stdio.h>
int linear(int arr[],int n,int x);
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
	if(p==0)
	{
		printf("position is:%d\n",p);
	}
	else if(p<0)
	{
		printf("array does not exist\n");
	}
	else
	{
		printf("not found\n");
	}
	return 0;
}
int linear(int arr[],int n,int x)
{
	int i,flag=-1;
	if(n==0)
	{
		flag=-1;
		return flag;
	}
	else
	{
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			flag=i;
			break;
		}

	}
	return flag;
	}
}

