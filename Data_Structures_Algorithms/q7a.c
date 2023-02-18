//a. Balancing symbols.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char ch,arr1[100];
int tos=-1,p,flag,i,len;

int isempty()
{
	if(tos==-1)
	return 1;
	return 0;
}
int isfull()
{
	if(tos==len-1)
	return 1;
	return 0;
}
void push(int ch)
{
	if(!isfull())
	{
		arr1[++tos]=ch;		
	}
}
char pop()
{	
	char x=-1;;
	if(!isempty())
	{
		x=arr1[tos];
		tos--;
	}
	
	return x;
}
char peek()
{
	char x=-1;
	if(!isempty())
	{
		x=arr1[tos];	
	}
	else
	{
		printf("\nStack is Empty!\n");
	}
	return x;
}

int main()
{
	char n[100];
	int count=0,size;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nEnter an Expression : ");
	scanf("%s", n);
	len=strlen(n);
	
	for(i=0;i<len;i++)
	{
		ch=n[i];
		switch(ch)
		{
			case '(':
			case '[':	
			case '{':
				push(ch);
				 break;
				
			case ')':
			case ']':
			case '}':
				if(!isempty())
				{
					p=peek();
					if((ch==')' && p=='(')||(ch==']' && p=='[')||(ch=='}' && p=='{'))
					p=pop();
				}				
				else
				{
					flag=1;
				}
				break;
						
			default:
			break;
		}		
		if(flag==1)
		break;		
	}
	if(i==len && isempty())
	{
		printf("\nGiven expression is balanced!\n");
	}
	else
	{
		printf("\nGiven expression is not balanced!\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
