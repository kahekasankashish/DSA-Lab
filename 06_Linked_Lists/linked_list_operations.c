/*
 * Question: Write a C program to perform creation, insertion, deletion, sorting, searching, and merging operations on singly linked lists.
 */
#include<stdio.h>
#include<stdlib.h>
int pos,count=0,i=1;
struct node
{
	int data;
	struct node *next;
};
struct node *head,*head2,*temp,*newnode,*temp1;
void creatll()
{
	head=NULL;
	//int n;
	//printf("Enter the no. of linked list to be created(1 or 2)\n");
	//scanf("%d"
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
		//n--;
	}
//	}while(n);

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
	if(temp==NULL)
	{
		head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
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
	else if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
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
	struct node *temp1;
	if(head== NULL)
	{
		printf("linked list is empty\n");
	}
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
		count--;
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
		temp1->next=NULL;
		count--;
	}
}
void deleteatpos()
{
	i=1;
	int pos;
	temp=head;
	printf("enter the position from whch node has to be deleted\n");
	scanf("%d",&pos);
	if(head==NULL || pos<1 || pos>count)
	{
		printf("invalid position\n");
	}
	else if(pos==1)
	{
		deleteatbegin();
	}
	else
	{
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		free(temp1);
		count--;
	}
}
void display();
void sort()
{
	int e;
	temp=head;
	temp1=NULL;
	while(temp!=NULL)
	{
		temp1=temp->next;
		while(temp1!=NULL)
		{
			if(temp->data>temp1->data)
			{
				e=temp->data;
				temp->data=temp1->data;
				temp1->data=e;
			}
			temp1=temp1->next;
		}
		temp=temp->next;
	}
	printf("the sorted linked list is\n");
	display();
}
void linearsearch()
{
	int v,flag=0;
	printf("enter the value to be searched\n");
	scanf("%d",&v);
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data == v)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag)
	{
		printf("element is present\n");
	}
	else
	{
		printf("element is not present\n");
	}
}
void merge()
{
	struct node *second_head=NULL,*second_temp=NULL;
	int choice=1;
	if(head==NULL)
	{
		creatll();
	}
	while(choice)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(second_head==NULL)
			second_head=second_temp=newnode;
		else
		{
			second_temp->next=newnode;
			second_temp=newnode;
		}
		printf("press 1 to continue and 0 to exit\n");
		scanf("%d",&choice);
	}
	if(head==NULL)
		head=second_head;
	else
	{
		temp=head;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=second_head;
	}
	printf(" The merged linked list is\n");
	display();
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
	printf("Linked list operation\n1.create a linked list\n2.insert at beginning\n3.insert at end\n4.insert at specific position\n5.delete at beginning\n6.delete at end\n7.display\n8.delete at specific position\n9.sort the linked list\n10.linear search\n11.merge\n12.exit\n");
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
	       deleteatpos();
	       break;
	       case 9:
	       sort();
	       break;
	       case 10:
	       linearsearch();
	       break;
	       case 11:
	       merge();
	       break;
	       case 12:
	       exit(0);
	       default:
	       printf("invalid choice\n");
       }
       return 0;
}

	


