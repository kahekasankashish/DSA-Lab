/*
 * Question: Write a C program to implement stack operations using a linked list.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void push();
void pop();
void display();
int main()
{
	int choice;
	while(1)
	{
		printf("stack operations\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default
				:printf("invalid choice\n");
		}
	}
	return 0;
}
void push()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	if(top==NULL)
	{
		newnode->next=top;
		top=newnode;
		printf("insertion is succesful\n");
	}
	else
	{
		newnode->next=top;
		top=newnode;
		printf("insertion is succesful\n");
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		struct node *temp=top;
		printf("deleted element: %d\n",temp->data);
		top=temp->next;
		free(temp);
	}
}
void display()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		struct node *temp=top;
		while(temp->next!=NULL)
		{
			printf("%d----->",temp->data);
			temp=temp->next;
		}
		printf("%d----->NULL",temp->data);
	}
}
