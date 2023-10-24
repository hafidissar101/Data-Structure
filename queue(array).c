//queue using array
#include<stdio.h>
int queue[5];
int front=-1;
int rear=-1;

void enque(int item)
{
	if(rear==4)
		printf("Queue is full\n");
	else if(rear==-1 && front==-1)
	{
		front++;
		queue[++rear]=item;
	}
	else
	{
		queue[++rear]=item;
	}
	
			
}

int deque()
{
	if(front>rear || front==-1 )
		return -1;
	else{
		return queue[front++];
	}
}

void view()
{
	if(front==-1 || front>rear)
		printf("Queue empty\n");
	else{
		int i;
		printf("Queue: ");
		for(i=front; i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
		printf("\n");
	}
	
}

int main()
{
	while(1)
	{
		int ch;
		printf("1 to enque 2 to deque 3 to view: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			int item;
			printf("Enter item to enque: ");
			scanf("%d",&item);
			enque(item);
		}
		else if(ch==2)
		{
			int item;
			item=deque();
			if(item==-1)
				printf("queue empty\n");
			else
				printf("Dequed item is: %d\n",item);
		}
		else if(ch==3)
		{
			view();
		}
		
		else
		{
			break;
		}
	}
}


