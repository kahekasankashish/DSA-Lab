/*
 * Question: Write a C program to sort an array of integers using the Quick Sort algorithm.
 */
#include<stdio.h>
#include<stdlib.h>
int start=0,end,n;
//int a[50];
void quicksort(int arr[],int start, int end);
int partition(int arr[],int start,int end);
void swap(int *x, int *y);
void input(int a[]);
void display(int b[]);
void input(int a[])
{
	int i;
	//printf("enter the size of array\n");
	//scanf("%d",&n);
	//int a[n];
	for(i=0;i<n;i++)
	{
		printf("enter an element\n");
		scanf("%d",&a[i]);
	}
}
void display(int b[])
{
	printf("The sorted array is\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",b[i]);
	}
}
void quicksort(int arr[],int start, int end)
{
	if(start<end)
	{
		int p=partition(arr,start,end);
		quicksort(arr,start,p-1);
		quicksort(arr,p+1,end);
	}
}
int partition(int arr[],int start,int end)
{
	int pivot=arr[start];
	int i=start;
	int j=end;
	while(i<j)
	{
		while(i<=end && arr[i]<=pivot)
		{
			i++;
		}
		while(j>start && arr[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[start],&arr[j]);
	return j;
}
void swap(int *x, int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int main()
{
	int i;
	printf("enter size of array\n");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("array size must be positive\n");
		return 1;
	}
	int a[n];
	/*for(i=0;i<n;i++)
	{
		printf("enter element\n");
		scanf("%d",&a[i]);
	}*/
	end=n-1;
	input(a);
	quicksort(a,start,end);
	display(a);
	  /*printf("The sorted array is\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t",a[i]);
        }*/

	return 0;
}


