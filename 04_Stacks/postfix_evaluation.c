/*
 * Question: Write a C program using a stack to evaluate a postfix expression.
 */
#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 100
char pf[max];
int top=-1;
int stack[max];
void push(int x);
int pop();
void post_eva()
{
	int i,a,b;
	for(i=0;i<strlen(pf);i++)
	{
		if(pf[i]>='0' && pf[i]<='9')
		{
			push(pf[i]-'0');
		}
		else
		{
			a=pop();
			b=pop();
			switch(pf[i])
			{
				case '+':
					push(b+a);
					break;
				case '-':
					push(b-a);
					break;
				case '*':
					push(b*a);
					break;
				case '/':
					push(b/a);
					break;
				case '^':
					push(pow(b,a));
					break;
				default:
					printf("invalid operation\n");
			}
		}
	}
}
void push(int x)
{
	if(top==(max-1))
	{
		printf("overflow condition / stack is full\n");
		return;
	}
	top++;
	stack[top]=x;
}
int pop()
{
	if(top==-1)
	{
		printf("underflow condition / stack is empty\n");
		return '\0';
	}
	return stack[top--];
}
int main()
{
	printf("enter the postfix expression\n");
	scanf("%s",pf);
	post_eva();
	printf("result is: %d",stack[top]);
	return 0;
}






