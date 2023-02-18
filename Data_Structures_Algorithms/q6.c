//Implement doubly linked list ADT.

#include<stdio.h>
#include<stdlib.h>
#define n 100
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *temp;
struct node *head;

void Insert_Beg(int elem)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=elem;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(head!=NULL)
	{
		temp->prev=NULL;
		temp->next=head;
		head=temp;
	}
	head=temp;
}

void Insert_End(int elem)
{
	struct node *curr;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=elem;
	temp->next=NULL;
	
	if(head==NULL)
	{
		temp->prev=NULL;
		head=temp;
	}	
	else
	{
		curr=head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
			
		}
		curr->next=temp;
	}
}

void Insert_Before(int searchelem,int elem)
{
	struct node *curr;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct node *curr;
		curr=head;
		while(curr!=NULL && curr->data!=searchelem)
			curr=curr->next;
		if(curr==NULL)
		{
			printf("Element not found");
		}
		else
		{
			
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->next=curr;
			temp->prev=curr->prev;
			if(curr->prev==NULL)
			{
				head=temp;
			}
			else
			{
				curr->prev->next=temp;
				curr->prev=temp;
			}
		}
	}
	printf("List is Empty");
}

int print(struct node *curr)
{
	if(curr==NULL)
		return 0;
	else
	print(curr->next);
	printf("%d ",curr->data);
}

void Traverse_Forward()
{
	struct node *curr=head;
	while(curr!=NULL)
	{
		printf("%d ",curr->data);
		curr=curr->next;
	}
}

void Traverse_Backward()
{
	if(head!=NULL)
	{
		print(head);
	}
	else
	{
		printf("List is empty");
	}
}

int Delete_Beg()
{
	int x=-1;
	struct node *curr,*temp;
	if(head!=NULL)
	{
		temp=head;
		x=temp->data;
		head=temp->next;
		free(temp);
	}
	else
	{
		printf("\nList is Empty!\n");
		return x;
	}
}

int Delete_Last()
{
	int x=-1;
	struct node *curr,*temp;
	if(head!=NULL)
	{
		if(head->next==NULL)
		{
			temp=head;
			head=NULL;
			free(temp);
		}
		else
		{
			curr=head;
			while(curr->next->next!=NULL)
			curr=curr->next;
			temp=curr->next;
			curr->next=NULL;
			free(temp);	
		}
	}
	else
	{
		printf("List is empty");
	}
}

int main()
{
	int m,i,choice,x,y;
	int a[m];
	while(1)
	{
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n  Choices You Have!");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n 1. Insert Beg");
		printf("\n 2. Insert End");
		printf("\n 3. Delete at Beginning");
		printf("\n 4. Delete at End");
		printf("\n 5. Insert Before");
		printf("\n 6. Traverse_Forward");
		printf("\n 7. Traverse_Backward");
		printf("\n 8. Exit!");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:	printf("\nEnter the size of the List : ");
				scanf("%d",&m);
				
				printf("\nEnter the Element to be Inserted at Beginning : ");
				for(i=0;i<m;i++)
				{
					scanf("%d",&a[i]);
					Insert_Beg(a[i]);
				}
				break;
			
			case 2: printf("\nEnter the Element to be Inserted at End : ");
				scanf("%d",&m);
				Insert_End(m);
				break;
				
			case 3:	Delete_Beg();
				break;
			
			case 4: Delete_Last();
				break;

			case 5: printf("\nEnter an Element to Search : ");
				scanf("%d",&x);
				printf("\nEnter an Element to Insert : ");
				scanf("%d",&y);
				Insert_Before(x,y);
				break;
				
			case 6: printf("\nElements of Linked List are : ");
				Traverse_Forward();
				break;
			
			case 7: printf("\nBackward Elements are : ");
				Traverse_Backward();
				break;
				
			default:printf("\nExit Successfully!\n");
				exit(1);
				return 0;
		}
	}
}
