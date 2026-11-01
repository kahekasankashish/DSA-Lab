/*
 * Question: Write a C program to insert a new node after a specified node number in a circular linked list.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
}*head,*temp,*newnode;
void insert()
{
	int i,pos,count=1;
	printf("enter the node(no.) after which new node has to be inserted\n");
	scanf("%d",&i);
	if(head==NULL || i<1)
	{
		printf("invalid node number\n");
		return;
	}
	temp=head;
	while(temp->next!=head)
	{
		count++;
		temp=temp->next;
	}
	if(i>count)
	{
		printf("invalid node number\n");
		return;
	}
	pos=i+1;
	newnode=(struct node*) malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&newnode->data);
	temp=head;
	while(--pos>1)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
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
	insert();
	printf("the elements are :\n");
	temp=head;
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
	return 0;
}

