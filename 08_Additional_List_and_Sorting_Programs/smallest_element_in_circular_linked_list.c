/*
 * Question: Write a C program to create a circular linked list and find its smallest element.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
}*head,*temp,*newnode;
void smallest()
{
	int min;
	min=head->data;
	temp=head->next;
	while(temp!=head)
	{
		if(temp->data<min)
		{
			min=temp->data;
		}
		temp=temp->next;
	}
	printf("Smallest element is : %d\n",min);
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
		smallest();
		return 0;
}

