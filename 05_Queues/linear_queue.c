/*
 * Question: Write a C program to implement a linear queue using an array with insertion, deletion and display operations.
 */
#include<stdio.h>
#include<stdlib.h>
#define max 10
int q[max],f=-1,r=-1;
void enqueue(int v);
void dequeue();
void traverse();
int main()
{
	int v,ch;
	printf(" linear queue operations\n1.insertion of an element\n2.deletion of element\n3.display all the elements\n4.exit\n");
	while(1)
	{
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter the element to be inserted\n");
			scanf("%d",&v);
			enqueue(v);
			break;
		case 2:	
		        dequeue();
			break;
		case 3:
			traverse();
			break;
		case 4:
			exit(0);
		default:
			printf("invalid choice\n");
	}
	}
	return 0;
}
void enqueue(int v)
{
	if(r==max-1)
	{
		printf("queue is overflowing\n");
		return;
	}
	if(f==-1)
	{
		f=0;
	}
	r++;
	q[r]=v;
}
void dequeue()
{
	if(f==-1)
	{
		printf("queue is underflowing\n");
		return;
	}
	printf("the element getting deleted is: %d\n",q[f]);
	if(f==r)
	{
		f=-1;
		r=-1;
	}
	else
	{
		f++;
	}
}
void traverse()
{
	int i;
	if(f==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
	printf("the queue is:\n");
	for(i=f;i<=r;i++)
	{
		printf("%d\t",q[i]);
	}
	}
}

