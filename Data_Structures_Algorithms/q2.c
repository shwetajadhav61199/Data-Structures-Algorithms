//Create a linked list ADT with functions for insertion, deletion, traverse forward, traverse reverse, searching for an element, reversing a list and also test the above functionality.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;
struct node *curr;
struct node *temp;

void Insert_Beg(int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=head;
	head=temp;
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

int Insert_End(int data)
{
	struct node *curr;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	if(head==NULL)
	{
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

void Insert_After(int searchelem,int elem)
{
	struct node *curr;
	if(head!=NULL)
	{
		curr=head;
		
	while(curr!=NULL && curr->data!=searchelem)
	{
		curr=curr->next;
	}
	if(curr==NULL)
	{
		printf("\nNode Doesen't Exists!\n");
	}
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=elem;
	temp->next=curr->next;
	curr->next=temp;
	}
	else
	{
		printf("\nList is Empty!\n");
	}
}

void Insert_Before(int element,int searchelem)
{
	if(head!=NULL)
	{
		if(head->data==searchelem)
		{
			struct node *temp;
			temp=(struct node *)malloc(sizeof(struct node));
			temp->data=element;
			temp->next=head;
			head=temp;
		}
		else
		{
			curr=head;
			while(curr->next!=NULL && curr->next->data!=searchelem)
			{
				curr=curr->next;
			}
			if(curr->next==NULL)
			{
				printf("\nElement Not Found!\n");
			}
		}
	}
	else
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=element;
		temp->next=curr->next;
		curr->next=temp;
	}
}

int Delete_Beg()
{
	int x=-1;
	struct node *temp;
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

void Delete_End()
{
	int x=-1;
	struct node *temp;
	struct node *curr;
	if(head!=NULL)
	{
		if(head->next==NULL)
		{
			temp=head;
			x=temp->data;
			head=NULL;
			free(temp);
		}
		else
		{
			curr=head;
			while(curr->next->next!=NULL)
			{
				curr=curr->next;
			}
			temp=curr->next;
			x=temp->data;
			curr->next=NULL;
			free(temp);
		}
	}
	else
	{
		printf("\nList is Empty!\n");
	}	
}

void Delete_Spec(int elem)
{
	if(head!=NULL)
	{
		if(head->data==elem)
		{
			temp=head;
			head=temp->next;
			free(temp);
		}
		else
		{
			curr=head;
			while(curr->next!=NULL && curr->next->data!=elem)
			{
				curr=curr->next;
			}
			if(curr->next==NULL)
			{
				printf("\nElement not Found!\n");
			}
			else
			{
				temp=curr->next;
				curr->next=temp->next;
				free(temp);
			}
		}
	}
	else
	{
		printf("\nList is Empty!\n");
	}
}

int show(struct node *curr)
{
	if(curr==NULL)
	{
		return 0;
	}
	show(curr->next);
	printf("%d ",curr->data);
}

void Traverse_Backward()
{
	if(head!=NULL)
	{
		show(head);
	}
	
	else
	{
		printf("\nList is Empty!\n");
	}
}

void Reverse()
{
	struct node *rev;
	rev=NULL;
	while(head!=NULL)
	{
		curr=head;
		head=curr->next;
		curr->next=rev;
		rev=curr;
		printf("%d ",rev->data);
	}
	head=rev;
}

void main()
{
	int n1,n2,x,y,choice,p,q,e;
	int a[n1],m,i;
	
	while(1)
	{
		printf("\n--------------------------------");
		printf("\n     CHOICES YOU HAVE!");
		printf("\n--------------------------------");
		printf("\n  1. Insert at Beginning");
		printf("\n  2. Traverse Backward");
		printf("\n  3. Traverse Forward");
		printf("\n  4. Delete Beginning");
		printf("\n  5. Delete Specific");
		printf("\n  6. Delete at End");
		printf("\n  7. Insert at End");
		printf("\n  8. Insert Before");
		printf("\n  9. Insert After");
		printf("\n 10. Reverse");
		printf("\n 11. Exit");
		printf("\n--------------------------------");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		printf("\n--------------------------------");
		printf("\n");
		
		switch(choice)
		{
			case 1: printf("\nEnter Size of Linked List : ");
				scanf("%d",&n1);
		
				printf("\nEnter a Data to be Inserted at First : ");
				for(i=0;i<n1;i++)
				{
					scanf("%d",&a[i]);
					Insert_Beg(a[i]);
				}
				break;
				
			case 2: printf("\nLinked List Elements after Traverse Backward are : ");
				Traverse_Backward();
				break;
			
			case 3: printf("\nLinked List Elements after Traverse Forward are : ");
				Traverse_Forward();
				break;
				
			case 4: Delete_Beg();
				break;
			
			case 5: Delete_End();
				break;
				
			case 6: printf("\nEnter an Element from List to Delete : ");
				scanf("%d",&p);
				Delete_Spec(p);
				break;
				
			case 7: printf("\nEnter Element to Insert at the End : ");
				scanf("%d",&p);
				Insert_End(p);
				break;
			
			case 8: printf("\nEnter an Element to be Search : ");
				scanf("%d",&p);
				
				printf("\nEnter an Element to be Inserted before : ");
				scanf("%d",&q);
				
				printf("\nLinked List Elements After Inserting an Element :  ");
				Insert_Before(p,q);
				
				printf("\n");
				break;
				
			case 9: printf("\nEnter an Element to be Search and Enter another Element to be Inserted : ");
				scanf("%d %d",&x,&y);		
				
				printf("\nLinked List Elements After Inserting an Element :  ");
				Insert_After(x,y);
				printf("\n");
				break;
				
			case 10: printf("\nLinked List Elements after Reverse are : ");
				Reverse();
				break;
					
			default:printf("\nExit Successfully!\n");
				exit(1);
				break;
		}
	}
}
