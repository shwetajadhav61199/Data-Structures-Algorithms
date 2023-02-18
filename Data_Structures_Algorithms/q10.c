//Circular Queue

#include<stdio.h>
#include<stdlib.h>
struct circularQueue
{
	int size;
	int front,rear;
	int q[100];
}cq;

int Underflow()
{
	if(cq.front==-1 && cq.rear==-1)
		return 1;
	return 0;
}

int Overflow()
{
	if((cq.rear+1)%cq.size==cq.front)
		return 1;
	return 0;
}

void Enqueue(int a)
{
	if(cq.front==-1 && cq.rear==-1)
	{
		cq.front++;
	}
	cq.rear=(cq.rear+1)%cq.size;
	cq.q[cq.rear]=a;	
}

int Dequeue()
{
	int x=-1;
	if(!Underflow())
	{
		x=cq.q[cq.front];
		
		if(cq.front==cq.rear)
		{
			cq.front=cq.rear=-1;
		}
		else
		{
			printf("%d",cq.q[cq.front]);
			cq.front=(cq.front+1)%cq.size;
		}
	}
	else
	{
		printf("\nQueue is Empty!\n");
		return x;
	}
}

void Display()
{
	int i;
	if(!Underflow())
	{
		for(i=cq.front;i!=cq.rear;i=(i+1)%cq.size)
			printf("%d ",cq.q[i]);
			
		printf("%d",cq.q[i]);
	}
	else
	{
		printf("\nQueue Underflow!\n");
	}
}

int Peek()
{

}

int main()
{
	int i,n,choice;
	cq.front=-1;
	cq.rear=-1;
	while(1)
	{
		printf("\n~~~~~~~~~~~~~~~~~~~~~~");
		printf("\nChoices You Have!");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~");
		
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~");
		
		switch(choice)
		{
			case 1: printf("\nEnter Circular Queue Size : ");
				scanf("%d",&cq.size);
				
				printf("\nEnter Circular Queue Elements : ");
				for(i=0;i<cq.size;i++)
				{
					scanf("%d",&cq.q[i]);
					Enqueue(cq.q[i]);
				}
				break;
			
			case 2: printf("\n~~~~~~~~~~~~~~~~~~~~~~");
				printf("\nDequeued Element is : ");
				Dequeue();
				printf("\n~~~~~~~~~~~~~~~~~~~~~~");
				break;
				
			case 3: printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				printf("\nCircular Queue Elements are : ");
				Display();
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				break;
				
			default:printf("\nExit Successfully!\n");
				return 0;
		}
	}
}
