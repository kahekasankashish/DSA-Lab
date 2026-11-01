/*
 * Question: Write a C program to create and display a singly linked list using dynamic memory allocation.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head,*temp,*newnode;
void createlinkedlist()
{
	int choice=1;
	head= NULL;
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data\n");
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
		printf("type 1 to continue or 0 to exit\n");
		scanf("%d",&choice);
	}
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
		if(temp!=NULL)
			printf("->");

	}
}
int main()
{
	createlinkedlist();
	display();
	return 0;
}

