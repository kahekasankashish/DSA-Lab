/*
 * Question:
 * Write a C program using dynamic memory allocation to store n integers and search for a given element.
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
	int x,flag=0;
	printf("enter the no. to be searched\n");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(*(ptr+i) == x)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		printf("present\n");
	}
	else
	{
		printf("not present\n");
	}
	return 0;
}

