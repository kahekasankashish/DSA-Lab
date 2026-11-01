/*
 * Question: Write a C program to create a doubly linked list and display it in reverse order.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
}*head,*newnode,*temp;
int main()
{
	int ch=1;
	head=NULL;
        while(ch)
        {
                newnode=(struct node*) malloc(sizeof(struct node));
                printf("enter data\n");
                scanf("%d",&newnode->data);
                if(head== NULL)
                {
                newnode->next=NULL;
        newnode->prev=NULL;
        temp=newnode;
        head=newnode;
                }
                else
                {
                        newnode->prev=temp;
                        temp->next=newnode;
                        temp=newnode;
                }
                printf("to continue press 1 and to exit press 0\n");
                scanf("%d",&ch);
        }
	temp=head;
	printf("NULL<-----");
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d<----",temp->data);
		temp=temp->prev;
	}
	printf("NULL\n");
	return 0;
}



