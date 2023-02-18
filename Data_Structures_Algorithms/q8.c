//Create a Stack ADT using linked list implementation.

#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};

struct stack *head;
struct stack *temp;
struct stack *top;

void Push(int a)
{
	temp=(struct stack *)malloc(sizeof(struct stack));
	temp->data=a;
	temp->next=NULL;
	head=temp;
	
	if(temp==NULL)
	{
		printf("\nStack Overflow!\n");
		exit(1);
	}
	temp->next=top;
	top=temp;
}

int Pop()
{
	struct stack *curr;
	curr=top;
	int x=curr->data;
	top=top->next;
	free(curr);
	curr=NULL;
	return x;
}

void Display()
{
	struct stack *curr;
	curr=top;
	while(curr)
	{
		printf("%d ",curr->data);
		curr=curr->next;
	}
}

void Peek()
{
	printf("%d",top->data);
}
		
int main()
{
	int i,n,choice;
	int a;
	while(1)
	{
		printf("\n~~~~~~~~~~~~~~~~~~~~~");
		printf("\nCHOICES YOU HAVE!");
		printf("\n~~~~~~~~~~~~~~~~~~~~~");
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Display");
		printf("\n 4. Peek");
		printf("\n 5. Exit");
		printf("\n~~~~~~~~~~~~~~~~~~~~~");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\nEnter Stack Elements(Push()) : ");
				scanf("%d",&a);
				Push(a);
				break;
				
			case 2: printf("\n~~~~~~~~~~~~~~~~~~~~~");
				printf("\nPopped Element(Pop()) is : %d",Pop());
				break;
			
			case 3: printf("\n~~~~~~~~~~~~~~~~~~~~~");
				printf("\nStack Elements are(Display()) : ");
				Display();
				break;
			
			case 4: printf("\n~~~~~~~~~~~~~~~~~~~~~");
				printf("\nTop Most of the Stack(Peek()) is : ");
				Peek();
				break;
				
			default:printf("\n~~~~~~~~~~~~~~~~~~~~~");
				printf("\nExit Successfully!");
				printf("\n~~~~~~~~~~~~~~~~~~~~~\n");
				exit(1);
				return 0;
		}
	}
}
