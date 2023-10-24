//circular queue
#include<stdio.h>
int queue[5];
int front=-1;
int rear=-1;

void enque(int item)
{
	
	if(rear==-1 && front==-1)
	{
		front++;
		queue[++rear]=item;
	}
	
	else if((rear+1)%5==front)
		printf("Queue is full\n");
	
	else
	{
		rear=(rear+1)%5;
		queue[rear]=item;
	}
			
}

int deque()
{
	if(front==-1 )
		printf("Queue empty\n");
	else if(front==rear){
		printf("Dequed element is: %d ", queue[front]);
		front=-1,rear=-1;
	}
	else{
		printf("Dequed element is: %d\n",queue[front] );
		front=(front+1)%5;
	}
}

void view()
{
	if(front==-1)
		printf("Queue empty\n");
	else{
		int i=front;
		printf("Queue: ");
		while(i!=rear)
		{
			printf("%d\t",queue[i]);
			i=(i+1)%5;
		}
		printf("%d",queue[i]);
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
			deque();
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



