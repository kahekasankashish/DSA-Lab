/*
 * Question: Write a C program to create a doubly linked list and delete a specified element from it.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
}*newnode,*head,*temp,*temp2;
int main()
{
	int ch=1;
	head=NULL;
	 while(ch)
        {
                newnode=(struct node*) malloc(sizeof(struct node));
                printf("enter data\n");
                scanf("%d",&newnode->data);
                if(head==NULL)
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
	 printf("enter the element which is to be deleted\n");
	 int x,flag=0;
	 scanf("%d",&x);
	 temp=head;
	 while(temp!=NULL)
	 {
		 if(temp->data==x)
		 {
			 temp2=temp;
			 temp->prev->next=temp->next;
			 temp->next->prev=temp;
			 free(temp2);
			 flag=1;
			 printf("the modified double linked list is\n");
			 temp=head;
			 while(temp!=NULL)
			 {
				 printf("%d--->",temp->data);
				 temp=temp->next;
			 }
			 break;
		 }
		 temp=temp->next;
	 }
	 if(flag==0)
	 {
		 printf("element %d not found and thus deletion was not possible\n",x);
	 }
	 return 0;
}



