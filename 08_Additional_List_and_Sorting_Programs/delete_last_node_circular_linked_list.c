/*
 * Question: Write a C program to create a circular linked list, delete its last node, and display the remaining list.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*temp,*newnode,*temp2;
void deletelast();
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
		if(head==NULL)
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
	temp->next=head;
	deletelast();
	temp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
	return 0;
	}
}
void deletelast()
{
	temp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		if(temp->next==head)
		{
			head=NULL;
			free(temp);
		}
		else
		{
	while(temp->next!=head)
	{
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=head;
	free(temp);
		}
		printf("Deletion successful\n");
	}
}




