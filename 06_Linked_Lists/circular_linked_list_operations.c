/*
 * Question: Write a C program to perform creation, insertion, deletion, and traversal operations on a circular linked list.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void create()
{
	struct node *newnode,*temp;
	int ch=1;
	head=NULL;
	while(ch)
	{
		newnode=(struct node*) malloc(sizeof(struct node));
		printf("enter the data\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			temp=head=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		temp->next=head;
		printf("continue---->1");
		scanf("%d",&ch);
	}
}
void insert_begin()
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("no memory allocation\n");
	}
	else
	{
	printf("enter the data\n");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
	}
	else
	{
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	newnode->next=head;
	temp->next=newnode;
	head=newnode;
	}
	}
}
void insert_end()
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("no memory allocation\n");
	}
	else
	{
		printf("enter the data\n");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=head;
		}
	}
}
void insert_pos()
{
	struct node *newnode,*temp;
	int pos;
	printf("enter the data\n");
	newnode=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	printf("enter the position to be inserted\n");
	scanf("%d",&pos);
	if(head==NULL && pos==1)
	{
		newnode->next=newnode;
		head=newnode;
	}
	else if(head==NULL || pos<1)
	{
		printf("cannot enter element at this place\n");
		free(newnode);
	}
	else if(pos==1)
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		newnode->next=head;
		temp->next=newnode;
		head=newnode;
	}
	else
	{
		temp=head;
		while(pos>2 && temp->next!=head)
		{
			temp=temp->next;
			pos--;
		}
		if(pos>2)
		{
			printf("cannot enter element at this place\n");
			free(newnode);
		}
		else
		{
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
}
void delete_begin()
{
	struct node *temp=head,*last=NULL;
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
				temp=temp->next;
			}
			last=temp;
			temp=head;
			head=head->next;
			free(temp);
			last->next=head;
		}
		printf("deletion successful\n");
	}
}
void delete_end()
{
	struct node *temp1=head,*temp2;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		if(temp1->next==head)
		{
			head=NULL;
			free(temp1);
		}
		else
		{
			while(temp1->next!=head)
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			temp2->next=head;
			free(temp1);
		}
		printf("deletion successful\n");
	}
}
void delete_pos()
{
	struct node *temp,*temp1;
	int pos;
	printf("enter the position from which element has to be deleted\n");
	scanf("%d",&pos);
	if(head==NULL || pos<1)
	{
		printf("list is empty or invalid position\n");
		return;
	}
	if(pos==1)
	{
		delete_begin();
		return;
	}
	temp=head;
	while(pos>2 && temp->next!=head)
	{
		temp=temp->next;
		pos--;
	}
	if(pos>2 || temp->next==head)
	{
		printf("invalid position\n");
		return;
	}
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
}
void traverse()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list empty\n");
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\ncircular linked list operations\n1.creation\n2.insertion at beginning\n3.insertion at end\n4.insertion at a speicic position\n5.delete the first node\n6.delete the last node\n7.deletion from any location\n8.traversal\n9.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				insert_begin();
				break;
			case 3:
				insert_end();
				break;
			case 4:
				insert_pos();
				break;
			case 5:
				delete_begin();
				break;
			case 6:
				delete_end();
				break;
			case 7:
				delete_pos();
				break;
			case 8:
				traverse();
				break;
			case 9:
				exit(0);
			default:printf("invalid operation\n");
		}
	}
	return 0;
}






