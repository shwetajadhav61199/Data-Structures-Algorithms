//Given two sorted lists, L1 and L2, write a procedure to merge L1 and L2 and generate a third list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void Insert(struct node **head,int data)
{
	struct node *curr,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=data;
	
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	
	curr=*head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=temp;
}

void Display(struct node *head)
{
	struct node *curr;
	curr=head;
	printf("\nLinked List : ");
	while(curr!=NULL)
	{
		printf(" [%d | %x] ",curr->data,curr->next);
		curr=curr->next;
	}
	printf("\n");
}

void MergeList(struct node *head1,struct node *head2)
{
	struct node *merged_list=NULL;
	struct node *curr,*curr1;
	
	curr=head1;
	curr1=head2;
	while(curr!=NULL && curr1!=NULL)
	{
		if(curr->data < curr1->data)
		{
			Insert(&merged_list,curr->data);
			curr=curr->next;
		}
		else if(curr->data == curr1->data)
		{
			Insert(&merged_list,curr->data);
			Insert(&merged_list,curr1->data);
			curr1=curr1->next;
			curr=curr->next;
		}
		else
		{
			Insert(&merged_list,curr1->data);
			curr1=curr1->next;
		}
	}
	while(curr!=NULL)
	{
		Insert(&merged_list,curr->data);
		curr=curr->next;
	}
	while(curr1!=NULL)
	{
		Insert(&merged_list,curr1->data);
		curr1=curr1->next;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nSorted Merged Linked List : \n");
	Display(merged_list);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n");
}

int main()
{
	int data,count,total;
	struct node *head1,*head2;
	head1=NULL;
	head2=NULL;
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nEnter the Size of the List 1 : ");
	scanf("%d",&total);
	printf("\nEnter Elements in Sorted Order : ");
	for(count=0; count < total; count++)
	{
		scanf("%d",&data);
		Insert(&head1,data);
	}
	Display(head1);
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nEnter the Size of the List 2 : ");
	scanf("%d",&total);
	printf("\nEnter Elements in Sorted Order : ");
	for(count=0; count < total; count++)
	{
		scanf("%d",&data);
		Insert(&head2,data);
	}
	Display(head2);
	
	MergeList(head1,head2);
	return 0;
}
