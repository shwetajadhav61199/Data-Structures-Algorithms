//Develop a program to add two polynomials using linked list implementation for polynomials.

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int expo;
	struct node *next;
};

struct node *Insert(struct node *head,int co,int ex)
{
	struct node *temp;
	struct node *ptr=malloc(sizeof(struct node));
	ptr->coeff=co;
	ptr->expo=ex;
	ptr->next=NULL;
	
	if(head==NULL || ex > head->expo)
	{
		ptr->next=head;
		head=ptr;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL && temp->next->expo>=ex)
			temp=temp->next;
		ptr->next=temp->next;
		temp->next=ptr;
	}
	return head;
}

struct node *Create(struct node *head)
{
	int i,n;
	int expo;
	int coeff;
	
	printf("\nEnter the Number of Terms : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter the Coefficient for term %d : ",i+1);
		scanf("%d",&coeff);
		
		printf("\nEnter the Exponent(^) for term %d : ",i+1);
		scanf("%d",&expo);
		
		head=Insert(head,coeff,expo);
	}
	return head;
}

void Print(struct node *head)
{
	if(head==NULL)
	{
		printf("\nNo Polynomial!\n");
	}
	else
	{
		struct node *temp=head;
		while(temp!=NULL)
		{
			printf("(%dx^%d)",temp->coeff,temp->expo);
			temp=temp->next;
			if(temp!=NULL)
			{
				printf("+");
			}
			else
			{
				printf("\n");
			}
		}
	}
}

void Polynomial(struct node *head1,struct node *head2)
{
	struct node *ptr1=head1;
	struct node *ptr2=head2;
	struct node *head3=NULL;
	
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->expo == ptr2->expo)
		{
			head3=Insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->expo > ptr2->expo)
		{
			head3=Insert(head3, ptr1->coeff, ptr1->expo);
			ptr1=ptr1->next;
		}
		else if(ptr1->expo < ptr2->expo)
		{
			head3=Insert(head3, ptr2->coeff, ptr2->expo);
			ptr2=ptr2->next;
		}
	}
	while(ptr1!=NULL)
	{
		head3=Insert(head3, ptr1->coeff, ptr1->expo);
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)
	{
		head3=Insert(head3, ptr2->coeff, ptr2->expo);
		ptr2=ptr2->next;
	}
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nAddition of Two Polynomials is : ");
	Print(head3);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int main()
{
	struct node *head1=NULL;
	struct node *head2=NULL;
	
	printf("\n~~~~~~~~~~~~~~~~~~");
	printf("\nFirst Polynomial\n");
	printf("~~~~~~~~~~~~~~~~~~\n");
	head1=Create(head1);
	printf("\n~~~~~~~~~~~~~~~~~~");
	printf("\nSecond Polynomial\n");
	printf("~~~~~~~~~~~~~~~~~~\n");
	head2=Create(head2);
	
	Polynomial(head1,head2);
	return 0;
}
