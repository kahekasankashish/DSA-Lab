/*
 * Question: Write a C program using a stack to convert an infix expression to a postfix expression.
 */
#include<stdio.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
int prcd(char key);
void push(char x);
char pop();
int Isempty();
char conversion(char inf[max],char post[max] );
int main()
{
char inf[max], post[max];
printf("enter infix expression\n");
scanf("%[^\n]",inf);
conversion(inf,post);
return 0;
}
void push(char x)
{
++top;
stack[top]=x;
}
char pop()
{
return stack[top--];
}
int prcd(char key)
{
if(key == '^')
{
return 3;
}
else if(key == '/' || key == '*')
{
return 2;
}
else if( key == '+' || key == '-')
{
return 1;
}
return -1;
}
char conversion(char inf[max],char post[max])
{
int i=0,j=0;
char ch,symb,key;
while(inf[i]!='\0')
{
symb = inf[i];
if(symb >= 'A' && symb <= 'Z' || symb>= 'a' && symb <= 'z')
{
post[j] = symb;
j++;
}
else if(symb == '(')
{
push('(');
}
else if( symb == ')')
{
while ((ch = pop())!='(')
{
post[j]=ch;
j++;
}
}
else
{
while( Isempty() == 0 && prcd(symb) <= prcd(stack[top]) )
{
key=pop();
post[j]=key;
j++;
}
push(symb);
}
//push(symb);
i++;
}
while(!Isempty())
{
key=pop();
post[j] = key;
j++;
}
post[j] = '\0';
printf("The postfix expression is : %s \n",post);
return '\0';
}
int Isempty()
{
if(top == -1)
{
return 1;
}
else
{
return 0;
}
}







