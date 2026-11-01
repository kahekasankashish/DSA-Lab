/*
 * Question: Write a C program to implement a circular queue using an array with insertion, deletion and display operations.
 */
#include<stdio.h>
#include<stdlib.h>
#define max 50
int q[max],f=-1,r=-1;
void enqueue(int v);
void dequeue();
void traverse();
int main()
{
	int v,ch;
	printf("circular queue operations\n1.insert an element\n2.delete an element\n3.display the elements\n4.exit\n");
	while(1)
	{
	printf("enter choice\n");
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
	if((r+1)%max==f)
	{
		printf("queue is overflowing\n");
	}
	else if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		q[r]=v;
	}
	else
	{
		r=(r+1)%max;
		q[r]=v;
	}
}
void dequeue()
{
	if(f==-1 && r==-1)
	{
		printf("queue is underflowing\n");
		return;
	}
	else if(f==r)
	{
		printf("the element getting deleted is:%d\n",q[f]);
		f=-1;
		r=-1;
	}
	else 
	{
	printf("the element getting deleted is:%d\n",q[f]);
	f=(f+1)%max;
	}
}
void traverse()
{
	int i;
	if(f==-1 && r==-1)
	{
		printf("queue is empty\n");
		return;
	}
	for(i=f;i<=r;i++)
	{
		printf("%d \t",q[i]);
	}
	if(f>r)
	{
		for(i=f;i<max;i++)
		{
			printf("%d\t",q[i]);
		}
		for(i=0;i<=r;i++)
		{
			printf("%d\t",q[i]);
		}
	}
}


