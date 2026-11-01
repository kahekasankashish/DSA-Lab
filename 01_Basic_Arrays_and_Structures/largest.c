/*
 * Question:
 * Write a C program to find the largest element in an array.
 */

#include<stdio.h>
void larg(int n, int a[n]);
int main()
{
	int i,n;
	printf("emter n\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("enter an element\n");
		scanf("%d",&a[i]);
	}
	larg(n,a);
	return 0;
}
void larg(int n, int a[n])
{
	int i, max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	printf("largest element is %d\n",max);
}




