/*
 * Question: Write a C program to perform creation, insertion, deletion, and display operations on a doubly linked list.
 */
#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *head,*newnode;
void create()
{
	head=NULL;
	struct node *temp;
	int choice=1;
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head == NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		count++;
		printf("to continue---->1\n");
		scanf("%d",&choice);
	}
}
void insert_begin()
{
	struct node *temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		temp=head;
		temp->prev=newnode;
		newnode->next=temp;
		head=newnode;
	}
	count++;
}
void insert_end()
{
	struct node *temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
		count++;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	count++;
}
void insert_pos()
{
	struct node *temp,*temp1;
	int pos;
	temp=head;
	int i=1;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(pos>count+1 || pos<1)
	{
		printf("operation not possible\n");
	}
	else if(pos==1)
	{
		insert_begin();
	}
	else if(pos==count+1)
	{
		insert_end();
	}
	else
	{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	while(i<pos-1)
	{
		temp=temp->next;i++;
	}
	temp1=temp->next;
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next=newnode;
	temp1->prev=newnode;
	count++;
	}
}
void insert_after()
{
	struct node *temp,*temp1;
	temp=head;
	int x;
	printf("enter the element after which data has to be inserted\n");
	scanf("%d",&x);
	while(temp!=NULL && temp->data!=x)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("element not found\n");
		return;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        newnode->prev=temp;
	if(temp->next!=NULL)
	{
		temp1=temp->next;
		temp1->prev=newnode;
	}
        temp->next=newnode;
	count++;
}
void delete_begin()
{
	struct node *temp;
	if(head == NULL)
	{
		printf("underflow\n");
	}
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
		count=0;
		printf("node deleted\n");
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		count--;
		printf("node deleted\n");
	}
}
void delete_end()
{
	struct node *temp;
	if(head== NULL)
	{
		printf("underflow\n");
	}
	else if(head->next== NULL)
	{
		free(head);
		head=NULL;
		count=0;
		printf("node deleted\n");
	}
	else
	{
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
	count--;
	printf("node deleted\n");
	}
}
void delete_pos()
{
	struct node *temp,*temp2;
	int pos;
	temp=head;
	printf("enter the position to delete the node\n");
	scanf("%d",&pos);
	if(pos<1 || pos>count || head==NULL)
	{
		printf("operation not possible\n");
	}
	else if(pos==1)
	{
		delete_begin();
	}
	else if(pos==count)
	{
		delete_end();
	}
	else
	{
	while(pos>1)
	{
		temp=temp->next;
		pos--;
	}
	temp2=temp->prev;
	temp2->next=temp->next;
	temp->next->prev=temp2;
	free(temp);
	count--;
	}
}




void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("double linked list operations\n1.create\n2.insert at beginning\n3.insert at end\n4.insert at specific position\n5.insert after a specific element\n6.display\n7.delete at beginning\n8.delete at end\n9.delete at specific position\n10.exit\n");
		scanf("%d",&ch);
		switch(ch)
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
				insert_after();
				break;
			case 6:
				display();
				break;
			case 7:
				delete_begin();
				break;
			case 8:
				delete_end();
				break;
			case 9:
				delete_pos();
				break;
			case 10:
				exit(0);
			default:
				printf("invalid choice\n");
		}
	}
	return 0;
}






