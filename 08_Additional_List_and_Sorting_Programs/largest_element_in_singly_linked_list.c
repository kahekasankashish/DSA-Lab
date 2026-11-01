/*
 * Question: Write a C program to create a singly linked list and find its largest element.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*temp,*newnode;
void largest()
{
	int max=head->data;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data>max)
		{
			max=temp->data;
		}
		temp=temp->next;
	}
	printf("the largest element is : %d\n",max);
}
int main()
{
	int ch=1;
	head=NULL;
	while(ch)
	{
		newnode=(struct node *) malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head ==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
		printf("to continue press 1 or press 0 to exit\n");
		scanf("%d",&ch);
	}
		largest();
		return 0;
}

