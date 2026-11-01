/*
 * Question: Write a C program to create a circular linked list and find its largest and smallest elements.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*newnode,*temp,*head=NULL;
int main()
{
	int max,min,ch=1;
	while(ch)
	{
		newnode=(struct node*) malloc(sizeof(struct node));
		printf("enter data\n");
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
		printf("enter 1 to continue and 0 to exit\n");
		scanf("%d",&ch);
	}
		temp->next=head;
		temp=head->next;
		max=head->data;
		min=head->data;
		while(temp!=head)
		{
			if((temp->data)>max)
			{
				max=temp->data;
			}
			if((temp->data)<min)
			{
				min=temp->data;
			}
			temp=temp->next;
		}
		printf("largest element is %d and smallest element is %d\n",max,min);
		return 0;
}
		



