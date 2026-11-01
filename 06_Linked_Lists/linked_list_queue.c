/*
 * Question: Write a C program to implement a queue using a linked list.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*f=NULL,*r=NULL,*newnode,*temp;
void insert(int val)
{
	newnode=(struct node*) malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(f==NULL)
	{
		f=r=newnode;
	}
	else
	{
		r->next=newnode;
		r=newnode;
	}
}
void delete()
{
	if(f==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		temp=f;
		f=f->next;
		if(f==NULL) r=NULL;
		free(temp);
	}
}
void display()
{
	temp=f;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int choice;
	while(1)
	{
		int val;
	printf("queue operations\n1.insert\n2.delete\n3.display\n4.exit\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("enter data to be inserted\n");
			scanf("%d",&val);
			insert(val);
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("invalid choice\n");
	}
	}
	return 0;
}



