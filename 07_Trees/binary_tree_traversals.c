/*
 * Question: Write a C program to create a binary tree and display its
 * preorder, inorder, and postorder traversals.
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int element;
	struct node *left;
	struct node *right;
};
struct node *create(int val)
{
	struct node *node=(struct node*) malloc(sizeof(struct node));
	node->element=val;
	node->left=NULL;
	node->right=NULL;
	return (node);
}
void preorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->element);
	preorder(root->left);
	preorder(root->right);
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
int main()
{
	struct node *root=create(36);
	root->left=create(26);
	root->right=create(46);
	root->left->left=create(21);
	root->left->right=create(31);
	root->left->left->left=create(11);
	root->left->left->right=create(24);
	root->right->left=create(41);
	root->right->right=create(56);
	root->right->right->left=create(51);
	root->right->right->right=create(66);
	printf("\npreorder traversal is\n");
	preorder(root);
	printf("\ninorder traversal is\n");
	inorder(root);
	printf("\npostorder traversal is\n");
	postorder(root);
	return 0;
}
