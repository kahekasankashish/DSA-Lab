/*
 * Question: Write a C program to search for an element in a doubly linked list and report its position.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
}*newnode,*head,*temp;
int main()
{
	int ch=1,p=0,x,flag=0;
	printf("enter the element to be searched\n");
	scanf("%d",&x);
	head=NULL;
	while(ch)
	{
		newnode=(struct node*) malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&newnode->data);
		if(head== NULL)
		{
		newnode->next=NULL;
	newnode->prev=NULL;
	temp=newnode;
	head=newnode;
		}
		else
		{
			newnode->prev=temp;
			temp->next=newnode;
			temp=newnode;
		}
		printf("to continue press 1 and to exit press 0\n");
		scanf("%d",&ch);
	}
	temp=head;
	while(temp!=NULL)
	{
		p++;
		if(temp->data==x)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag)
	{
	printf("element found at %d",p);
	}
	else
	{
		printf("element not found\n");
	}
	return 0;
}
		




