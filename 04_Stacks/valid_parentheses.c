/*
 * Question: Write a C program using a stack to check whether an expression has balanced parentheses, braces and square brackets.
 */
#include<stdio.h>
#define max 50
int top=-1;
char stack[max];
int val(char exp[])
{
	int i;
	for (i=0;exp[i]!='\0';i++)
	{
		char ch=exp[i];
		if(ch== '(' || ch== '{' || ch== '[')
		{
			if(top==max-1)
			{
				printf("stack overflow\n");
				return 0;
			}
			stack[++top]=ch;
		}
		else if(ch== ')' || ch== '}' || ch== ']')
		{
			if(top==-1)
			{
				printf("stack underflow\n");
				return 0;
			}
			char last=stack[top--];
			if((ch == ')' && last!='(') || (ch== '}' && last!='{') || (ch== ']' && last!='['))
			{
				return 0;
			}
		}
	}
	return (top==-1);
}
int main()
{
	char exp[50];
	printf("enter the expression\n");
	scanf("%s",exp);
	if(val(exp))
	{
		printf("valid\n");
	}
	else
	{
		printf("not valid\n");
	}
	return 0;
}
