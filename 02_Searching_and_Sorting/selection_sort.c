/*
 * Question: Write a C program to sort an array of integers using selection sort.
 */
#include<stdio.h>
void sort(int n, int a[n]);
int main()
{
	int n,k;
	printf("enter n\n");
	scanf("%d",&n);
	int a[n];
	for(k=0;k<n;k++)
	{
		printf("enter a no.\n");
		scanf("%d",&a[k]);
	}
	sort(n,a);
	return 0;
}
void sort(int n, int a[n])
{
	int i,j,min,temp;
	for(i=0;i<(n-1);i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	printf("the new array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}

}


