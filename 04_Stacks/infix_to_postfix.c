/*
 * Question: Write a C program using a stack to convert an infix expression to a postfix expression.
 */
#include<stdio.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
void push(char x)
{
	stack[++top]=x;
}
char pop()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
	return stack[top--];
	}
}
int prcd(char c)
{
	if(c=='(')
	{
		return 0;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else if(c=='*' || c== '/')
	{
		return 2;
	}
	else if(c=='^')
	{
		return 3;
	}
	return -1;
}
void infixpost(char infix[max],char post[max])
{
	char temp,x;
	int i=0,j=0;
	while(infix[i]!='\0')
	{
		temp=infix[i];
		if(isalnum(temp))
		{
			post[j++]=temp;
		}
	else if(temp == '(')
	{
		push(temp);
	}
	else if(temp== ')')
	{
		while((x=pop())!='(')
		{
			post[j++]=x;
		}
	}
	else
	{
		while(top!=-1 && prcd(stack[top])>=prcd(temp))
		{
			post[j++]=pop();
		}
		push(temp);
	}
	i++;
	}
	while(top!=-1)
	{
		post[j++]=pop();
	}
	post[j]='\0';
}
int main()
{
	char infix[max];
	char post[max];
	printf("enter the infix expression\n");
	scanf("%s",infix);
	infixpost(infix,post);
	printf(" Resultant postfix expression is: %s\n",post);
	return 0;
}


