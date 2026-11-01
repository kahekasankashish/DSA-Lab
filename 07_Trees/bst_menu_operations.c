/*
 * Question: Write a C program to perform insertion, searching, finding the
 * minimum and maximum elements, preorder/inorder/postorder traversal, and
 * deletion of nodes in a Binary Search Tree (BST) using a menu.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int element;
	struct node *left;
	struct node *right;
};
struct node *create(int val);
struct node *insert(struct node *node,int data);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node *search(struct node *root,int key);
struct node *findmax(struct node *root);
struct node *findmin(struct node *root);
struct node *deletelf(struct node *root,int key);
struct node *create(int val)
{
	struct node *newnode=(struct node*) malloc(sizeof(struct node));
	newnode->element=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node *insert(struct node *node,int data)
{
	if(node==NULL)
	{
		return create(data);
	}
	if(data<node->element)
	{
		node->left=insert(node->left,data);
	}
	else if(data>node->element)
	{
		node->right=insert(node->right,data);
	}
	return node;
}
void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->element);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if(root ==NULL)
	{
		return;
	}
	printf("%d ",root->element);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->element);
}
struct node *search(struct node *root,int key)
{
	while(root!=NULL)
	{
		if(key==root->element)
		{
			return root;
		}
		else if(key<root->element)
		{
			root=root->left;
		}
		else
		{
			root=root->right;
		}
	}
	return NULL;
}
struct node *findmax(struct node *root)
{
	if(root ==NULL)
	{
		return NULL;
	}
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}
struct node *findmin(struct node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
struct node *deletelf(struct node *root,int key)
{
	struct node *temp;
	if(root==NULL)
	{
		printf("Key element not found\n");
		return NULL;
	}
	if(key<root->element)
	{
		root->left=deletelf(root->left,key);
	}
	else if(key>root->element)
	{
		root->right=deletelf(root->right,key);
	}
	else
	{
		if(root->left==NULL)
		{
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			temp=findmin(root->right);
			root->element=temp->element;
			root->right=deletelf(root->right,temp->element);
		}
	}
	return root;
}

int main()
{
	struct node *root=NULL,*s,*min,*max;
	int data,ch=1,key;
	char input='y';
	printf("BST operations\n1.insert\n2.search\n3.Find max\n4.Find min\n5.preorder traversal\n6.inorder traversal\n7.postorder traversal\n8.delete a node\n9.exit\n");
	while(1)
	{
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			 input='y';
			 printf("enter data to insert into the BST:\n");
                       while(input=='y' || input=='Y')
                       {
                printf("enter a no.\n");
                scanf("%d",&data);
                root=insert(root,data);
                printf("continue adding nodes?(y/n):\n");
                scanf(" %c",&input);
	}
	break;
		case 2:
	printf("enter the element to be searched\n");
	scanf("%d",&key);
	s=search(root,key);
	 if(s==NULL)
        {
                printf("element noi found\n");
        }
        else
        {
                printf("Element found\n");
        }
	break;
		case 3:
	max=findmax(root);
	if(max==NULL) printf("BST is empty\n");
	else printf("largest element is %d\n",max->element);
	break;
		case 4:
	min=findmin(root);
	if(min==NULL) printf("BST is empty\n");
	else printf("smallest element is %d\n",min->element);
	break;
		case 5:
	printf("preorder traversal is\n");
	preorder(root);
	break;
		case 6:
	printf("inorder traversal is\n");
	inorder(root);
	break;
		case 7:
	printf("postorder traversal is\n");
	postorder(root);
	break;
		case 8:
	printf("Enter the element to be deleted\n");
	scanf("%d",&key);
	root=deletelf(root,key);
	break;
		case 9:
	exit(0);
		default:printf("invalid choice\n");
	}
		if(root==NULL)
		{
			printf("root is NULL\n");
		}
}
	return 0;
}


