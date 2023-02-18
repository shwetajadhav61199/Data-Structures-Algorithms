 //Implement Deque ADT using doubly inked list. Deque is a data structure in which insertions and deletions are performed only at the ends.

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *temp;
struct node *head;
struct node *curr;
struct node *front;
struct node *rear;

void Insert_End(int ele)
{
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=ele;
	temp->prev=NULL;
	
	if(head==NULL)
	{
		head=temp;
		front=rear=temp;
		return;
	}
	curr=head;
	
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	
	if(curr->next==NULL)
	{
		temp->next=NULL;
		temp->prev=curr;
		curr->next=temp;
		rear=temp;
	}
}

int Delete_End()
{
	int a;
	if(head==NULL)
	{
		return -1;
	}
	curr=head;
	
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	if(curr->next==NULL)
	{
		a=curr->data;
		if(curr->prev!=NULL)
		{
			curr->prev->next=NULL;
		}
		front--;
		free(curr);

	}
	return a;
}

void Display()
{
	curr=head;
	printf("[ HEAD ]");
	while(curr!=NULL)
	{
		printf("-->[ %d ]",curr->data);
		curr=curr->next;
	}
}

int main()
{
	int m,n,choice;
	while(1)
	{
		printf("\n.___________________________________.");
		printf("\n|   !!--CHOICES YOU HAVE--!!");printf("	    |");
		printf("\n|-----------------------------------|");
		printf("\n|  1. Insert at End");printf("	            |");
		printf("\n|  2. Delete at End");printf("      	    |");
		printf("\n|  3. Display");printf("            	    |");
		printf("\n|  4. Exit");printf("                          |");
		printf("\n|___________________________________|");
		printf("\n\n    Enter Your Choice : ");
		scanf("%d",&choice);//		      printf("|                                   |");
		//printf("\n|-----------------------------------|");
		
		switch(choice)
		{
			case 1: printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				printf("\n Enter an Element to Insert at End : ");
				scanf("%d",&m);
				Insert_End(m);
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				break;
				
			case 2: Delete_End();
				break;
				
			case 3:	printf("\n------------------------------------------------------------------------------");
				printf("\n Linked List Elements are : ");
				Display();
				printf("\n------------------------------------------------------------------------------");
				printf("\n");
				break;
			
			default:printf("\n----------------------------------------");
				printf("\n    	  EXIT SUCCESSFULLY!");
				printf("\n----------------------------------------\n");
				exit(1);
				return 0;
		}
	}
}
