/*
 * Question:
 * Write a C program to find the sum of all elements of an array.
 */

#include<stdio.h>
void sum(int n,int a[n]);
int main()
{
	int n,i;
	printf("enter n\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("enter an element\n");
		scanf("%d",&a[i]);
	}
	sum(n,a);
	return 0;
}
void sum(int n, int a[n])
{
	int i, s=0;
	for(i=0;i<n;i++)
	{
		s=s+a[i];
	}
	printf("the sum of the elements is: %d\n",s);
}



