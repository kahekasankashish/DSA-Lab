/*
 * Question: Write a C program to insert a new node before a specified element in a singly linked list.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*newnode,*temp,*temp2,*temp3;
int main()
{
	int ch=1;
	head=NULL;
	while(ch)
	{
		newnode=(struct node*) malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		printf("to continue press 1 and to exit press 0\n");
		scanf("%d",&ch);
	}
	int x,flag=0;
	printf("enter the element before which data has to be inserted\n");
	scanf("%d",&x);
	temp=head;
	if(temp!=NULL && temp->data==x)
	{
		newnode=(struct node*) malloc(sizeof(struct node));
		printf("enter the data to be inserted\n");
		scanf("%d",&newnode->data);
		newnode->next=head;
		head=newnode;
		flag=1;
	}
	else
	{
		while(temp!=NULL && temp->next!=NULL)
		{
			if(temp->next->data==x)
			{
				newnode=(struct node*) malloc(sizeof(struct node));
				printf("enter the data to be inserted\n");
				scanf("%d",&newnode->data);
				newnode->next=temp->next;
				temp->next=newnode;
				flag=1;
				break;
			}
			temp=temp->next;
		}
	}
	if(flag)
	{
		printf("the modified linked list is\n");
		temp=head;
		while(temp!=NULL)
		{
			printf("%d---->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
	else
	{
		printf("the entered element %d was not found and thus inserion was not possible\n",x);
	}
	return 0;
}


