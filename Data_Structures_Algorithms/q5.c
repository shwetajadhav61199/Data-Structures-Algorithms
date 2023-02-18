//Develop a self-adjusting list using linked list. A self-adjusting list is like a regular list, except that all insertions are performed at the front, and when an element is accessed by the Find, it is moved to the front of the list.

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

void Insert_Beg(int ele)
{

	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=head;
	head=temp;
	
}
void Insert_Before(int sele,int ele)
{
	if(head!=NULL)
	{
		if(head->data==sele)
		{
			
			temp=(struct node *)malloc(sizeof(struct node));
			temp->data=ele;
			temp->next=head;
			head=temp;
		}
		else
		{
			curr=head;
			while(curr->next!=NULL && curr->next->data!=sele)
			{
				curr=curr->next;
			}
			if(curr->next==NULL)
			{
				printf("\nElement not found");
			}	
			else
			{
				
				temp=(struct node *)malloc(sizeof(struct node));
				temp->data=ele;
				temp->next=curr->next;
				curr->next=temp;
				
			}
		}
	}
	else
	{
		printf("\nList is empty");
	}
}

void travel_forward()
{
	curr=head;
	
	while(curr!=NULL)
	{	
		printf("%d ",curr->data);
		curr=curr->next;
	}
}
int main()
{
	int n ,i,sele,ele;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nEnter the Size of the List : ");
	scanf("%d",&n);

	int a[n];

	printf("\nEnter List Elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		Insert_Beg(a[i]);
	}

	printf("\nElements are : ");
	travel_forward(); 
	printf("\n");

	printf("\nEnter Element to Search : ");
	scanf("%d",&sele);

	printf("\nEnter an Element to add Before Searching Element : ");
	scanf("%d",&ele);
	Insert_Before(sele,ele);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nStack Elements are : ");
	travel_forward(); 
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n");
}
