/*
 * Question:
 * Write a C program using dynamic memory allocation to find the maximum and minimum elements among n integers.
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr,n;
	printf("enter n\n");
	scanf("%d",&n);
	ptr= (int *) malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter a no.\n");
		scanf("%d",(ptr+i));
	}
	int max=*ptr,min=*ptr;
	for(i=1;i<n;i++)
	{
		if(*(ptr+i)>max)
		{
			max=*(ptr+i);
		}
		if(min>*(ptr+i))
		{
			min= *(ptr+i);
		}
	}
	printf("max is %d and min is %d",max,min);
	return 0;
}
