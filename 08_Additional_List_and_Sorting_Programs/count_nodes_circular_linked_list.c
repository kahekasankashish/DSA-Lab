/*
 * Question: Write a C program to create a circular linked list, display its elements, and count its nodes.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
}*head,*temp,*newnode;
void count_disp()
{
	int c=0;
	temp=head;
	printf("the elements are\n");
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
		c++;
	}
	c++;
	printf("%d",temp->data);
	printf("\nthe total no. of nodes is %d\n",c);
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
	count_disp();
	return 0;
}

