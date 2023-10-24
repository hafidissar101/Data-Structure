//circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL, *tail=NULL;
void create();
void view();
void insert();
void deletion();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1 to create, 2 to view, 3 to insert, 4 to delete: ");
		scanf("%d",&ch);
		if(ch==1)
			create();
		else if(ch==2)
			view();
		else if(ch==3)
			insert();
		else if(ch==4)
			deletion();
		
	}
}

void create()
{
	int i,n;
	struct node *temp;
	printf("Number of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&temp->data);
		temp->next=NULL;
		
		if(head==NULL)
		{
			head=temp;
			tail=temp;	
		}	
		else
		{
			tail->next=temp;
			tail=temp;
		}
	} 
	tail->next=head;
}
void view()
{
	struct node *trav;
	trav =head;
	while(trav!=tail)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
	printf("%d",tail->data);
}
void insert()
{
	int control, item;
	printf("1 to insert before node, 2 to insert after node: ");
	scanf("%d",&control);
	struct node *temp, *trav;
	trav=head;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node to insert: ");
	scanf("%d",&temp->data);
	if(control==1)
	{
		printf("Enter node before which you want to insert: ");
		scanf("%d",&item);
		if(head->data==item)
		{
			temp->next=head;
			head=temp;
		}
		
		while(trav->next->data!=item)
			trav=trav->next;
			
		temp->next=trav->next;
		trav->next=temp;
	}
	else if(control==2)
	{
		
		printf("Enter node after which you want to insert: ");
		scanf("%d",&item);
		while(trav->data!=item)
			trav=trav->next;
		
		if(trav==tail)
		{
			temp->next=head;
			tail->next=temp;
			tail=temp;		
		}
		else{
			temp->next=trav->next;
			trav->next=temp;
		}
		
		
	}
}
void deletion()
{
	struct node *temp, *trav;
	trav=head;
	int control, item;
	printf("1 for deleting first instance of node or 2 to delete all instances of a node: ");
	scanf("%d",&control);
	printf("enter the item to be deleted: ");
	scanf("%d",&item);
	if(control==1)
	{
		if(head->data==item)
		{
			temp=head;
			head=head->next;
			free(temp);
		}
		else
		{
			while(trav->next->data!=item)
				trav=trav->next;
			
				temp=trav->next;
				trav->next=trav->next->next;
				free(temp);
				
			if(trav->next==head)//tail getting deleted
			{
				tail=trav;	
			}
				
		}
	}
	else if(control==2)
	{
		while(trav->next!=head)
		{
			if(trav->next->data==item)
			{
				temp=trav->next;
				trav->next=trav->next->next;
				free(temp);
				
				if(trav->next==head)
					tail=trav;
			}
			else
				trav=trav->next;
		}
		if(head->data==item)
		{
			temp=head;
			head=head->next;
			free(temp);
		}
	}
}



