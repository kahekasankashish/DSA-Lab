/*
 * Question: Write a C program to perform basic insertion and deletion operations on a singly linked list.
 */
#include<stdio.h>
#include<stdlib.h>
int pos,count=0,i=1;
struct node
{
	int data;
	struct node *next;
};
struct node *head,*temp,*newnode;
void creatll()
{
	int choice=1;
	head=NULL;
	while(choice)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
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
		count++;
		printf("press 1 to continue and 0 to exit\n");
		scanf("%d",&choice);
	}
}
void insertatbegin()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&newnode->data);
	newnode->next= NULL;
	newnode->next=head;
	head=newnode;
}
void insertatend()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter data to be inserted\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	temp=head;
	if(temp==NULL) { head=newnode; return; }
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
void insertatpos()
{
	printf("enter the position at which new node has to be inserted\n");
	scanf("%d",&pos);
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter data to be inserted\n");
	scanf("%d",&newnode->data);
	temp=head;
	if(pos<1 || pos>count+1)
	{
		printf("invalid position\n");
	}
	else if(pos==1)
	{
		free(newnode);
		insertatbegin();
		count++;
	}
	else
	{
		i=1;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		count++;
	}
}
void deleteatbegin()
{
	if(head== NULL)
	{
		printf("linked list is empty\n");
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
		count--;
	}
}
void deleteatend()
{
	struct node *temp1=NULL;
	if(head== NULL)
	{
		printf("linked list is empty\n");
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}
		free(temp);
		if(temp1!=NULL) temp1->next=NULL;
		else head=NULL;
		count--;
	}
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int ch;
	printf("Linked list operation\n1.create a linked list\n2.insert at beginning\n3.insert at end\n4.insert at specific position\n5.delete at beginning\n6.delete at end\n7.dsiplay\n8.exit\n");
	printf("enter your choice\n");
       scanf("%d",&ch);	
       switch(ch)
       {
        case 1:
	       creatll();
	       break;
	       case 2:
	       insertatbegin();
	       break;
	       case 3:
	       insertatend();
	       break;
	       case 4:
	       insertatpos();
	       break;
	       case 5:
	       deleteatbegin();
	       break;
	       case 6:
	       deleteatend();
	       break;
	       case 7:
	       display();
	       break;
	       case 8:
	       exit(0);
	       default:
	       printf("invalid choice\n");
       }
       return 0;
}

	

