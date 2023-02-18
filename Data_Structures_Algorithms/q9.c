//9. Implement Linear Queue ADT using linked list implementation.

#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int que[100];
	int size;
	int front,rear;
}q;

int underflow()
{
	if(q.front == -1 && q.rear == -1)
	{
		return 1;
	}
	return 0;
}
int overflow()
{
	if(q.rear == q.size-1)
	{
		printf("\nQueue Overflow!\n");
	}
	return 0;
}

int enqueue(int data)
{
	if(!overflow())
	{
		if(q.front==-1 && q.rear==-1)
		{
			q.front++;
		}
		q.rear++;
		q.que[q.rear]=data;
	}
	else
	{
		printf("\nQueue Overflow!\n");
	}
}

int dequeue()
{
	int val;
	if(!underflow())
	{
		val=q.que[q.front];
		printf("%d",val);
		
		if(q.front==q.rear)
		{
			q.front=q.rear=-1;
		}
		else
		{
			q.front++;
		}
	}
	else
	{
		printf("\nQueue is Empty!\n");
		return val;
	}
}

int Display()
{
	int i;
	if(underflow())
	{
		printf("\nQueue is Empty\n");
	}
	else
	{
		for(i=q.front;i<=(q.rear-1);i++)
		{
			printf("%d ",q.que[i]);
		}
	}
}

int main()
{
	while(1)
	{
		int choice,n,a,i;
		printf("\n~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n CHOICES YOU HAVE!");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n 1. Enqueue");
		printf("\n 2. Dequeue");
		printf("\n 3. Display");
		printf("\n 4. Exit!");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("\nEnter the Size of the Queue : ");
			       scanf("%d",&n);
			       
			       printf("\nEnter Queue ELements : ");       
			       for(i=0;i<n;i++)
			       {
			       		scanf("%d",&q.que[i]);
			       		enqueue(q.que[i]);
			       }
			       break;
			       
			case 3:printf("\n~~~~~~~~~~~~~~~~~~~~~~~~");
			       printf("\nQueue Elements are : ");
			       Display();
			       printf("\n~~~~~~~~~~~~~~~~~~~~~~~~");
			       break;
			      
			case 2:printf("\n~~~~~~~~~~~~~~~~~~~~~~~~");
			       printf("\nDequeued Element is : ");
			       dequeue();
			       printf("\n~~~~~~~~~~~~~~~~~~~~~~~~");
			       break;
			       
			default:printf("\nExit Successfully!\n");
			       exit(1);
		}
	}
}
