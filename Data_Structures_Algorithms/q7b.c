//Evaluation of postfix expression.

#include<stdio.h>
#include<ctype.h>
int stack[20];
int top=-1;

int Push(int x)
{
	return stack[++top]=x;
}

int Pop()
{
	return stack[top--];
}

int main()
{
	char exp[20];
	char *e;
	int n1,n2,n3,num;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nEnter an Expression : ");
	scanf("%s",exp);
	e=exp;
	
	while(*e!='\0')
	{
		if(isdigit(*e))
		{
			num=*e-48;
			Push(num);
		}
		else
		{
			n1=Pop();
			n2=Pop();
			switch(*e)
			{
				case '+':n3=n2+n1;
					 break;
				
				case '-':n3=n2-n1;
					 break;
					 
				case '*':n3=n2*n1;
					 break;
				
					 
				case '/':n3=n2/n1;
					 break;
			}
			Push(n3);
		}
		e++;
	}
	printf("\nThe result of Expression %s is : %d\n",exp,Pop());
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 0;
}

