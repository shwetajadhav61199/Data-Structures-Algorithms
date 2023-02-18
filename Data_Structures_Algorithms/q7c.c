//Infix to Postfix

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ch,infix[100],j;
int tos=-1,p,flag,i,len;
char postfix[15];

int isempty()
{
	if(tos==-1)
	{
		//printf("\nStack is Empty!\n");
		return 1;
	}
	return 0;
}

int isfull()
{
	if(tos==len-1)
	{
		printf("\nStack is Full!\n");
		return 1;
	}
	return 0;
}

void push(int a)
{
	if(!isfull())
	{
		tos++;
		infix[tos]=a;
	}
	return;
}

int pop()
{	
	int x=-1;;
	if(isempty())
	{
		return x;
	}
	x=infix[tos];
	tos--;
	return x;
}
char peek()
{
	char x=-1;
	if(!isempty())
	{
		x=infix[tos];	
	}
	else
	{
		printf("stack is empty");
	}
	return x;
}
int prec(char ch)
{
	switch(ch)
	{
		case '*':
		case '/':
		           return 3;
		case '+':
		case '-':
			  return 2;
		case '(':
		case '[':
		case '{':
			  return 1;  
	}		
	return 0;        
}

void Display()
{
	int i;
	if(isempty())
	{
		return;
	}
	printf("Postfix : ");
	
	for(i=0;i<=tos;i++)
	{
		printf("%d",postfix[i]);
	}
}

int main()
{
	char n[100];
	int count=0,size,j=0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nEnter an Expression : ");
	scanf("%s",infix);
	
	len=strlen(infix);
	
	for(i=0;i<len;i++)
	{
		ch=infix[i];
	
		switch(ch)
		{
			case '(':push(ch);
				 break;
				 
			case '[':push(ch);
				 break;
				 
			case '{':push(ch);
				 break;
				
			case ')':
			case ']':
			case '}':
				while(!isempty())
				{
					p=pop();
					
					if(p =='('|| p =='['|| p =='{')
					{
						break;
					}
					postfix[j++]=p;
				}
				break;	
				
			case '*':			
			case '/':	   
			case '+':
			case '-':  		
				while(!isempty() && prec(peek())<=prec(ch))
				{
					postfix[j++]=pop();
				}	
				push(ch);
				break;
			
			default:postfix[j++]=ch;
				break;				
		}
	}
	while(!isempty())
	{
		postfix[j++]=pop();
	}
	postfix[j++]='\0';
	Display();
	
	printf("\nPostfix Expression is : %s",postfix);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 0;
}

