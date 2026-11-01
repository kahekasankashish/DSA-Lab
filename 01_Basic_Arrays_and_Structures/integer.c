/*
 * Question:
 * Write a C program using dynamic memory allocation to input and display 10 integers.
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr,s=0;
	ptr=(int *) malloc(10* sizeof(int));
	int i;
	if (ptr == NULL)
	{
		printf("insufficient memory\n");
	}
	else
	{

	for(i=0;i<10;i++)
	{
		printf("enter an element\n");
		scanf("%d",(ptr+i));
	}
	printf("all the elements are:\n");
	for(i=0;i<10;i++)
	{
	printf("%d\n",*(ptr+i));
	}
	}
	return 0;
}
