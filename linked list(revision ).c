#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *head1=NULL, *tail=NULL;
struct node *head2=NULL, *tail2=NULL;
struct node *head3=NULL, *tail3=NULL;

void create();
void view();
void create2();
void view2();
void view3();
void insert();
void deletion();
void reverse();
void sort();
void merge();


int main()
{
	int ch;
	while(1)
	{
		printf("\n1 to create, 2 to view, 3 to insert, 4 to delete, 5 to reverse, 6 to sort,7 to create list 2, 8 to view 2nd list, 9 to merge, 10 to view merged list : ");
		scanf("%d",&ch);
		if(ch==1)
			create();
		else if(ch==2)
			view();
		else if(ch==3)
			insert();
		else if(ch==4)
			deletion();
		else if(ch==5)
			reverse();
		else if(ch==6)
			sort();
		else if(ch==7)
			create2();
		else if(ch==8)
			view2();
		else if(ch==9)
			merge();
		else if(ch==10)
			view3();
	}
}

void create()
{
	int n, i;
	struct node *temp;
	printf("No of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&temp->data);
		temp->next=NULL;
		
		if(head1==NULL)
		{
			head1=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
		
	}
}

void view()
{
	struct node *trav;
	trav=head1;
	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}
void create2()
{
	int n, i;
	struct node *temp;
	printf("No of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&temp->data);
		temp->next=NULL;
		
		if(head2==NULL)
		{
			head2=temp;
			tail2=temp;
		}
		else
		{
			tail2->next=temp;
			tail2=temp;
		}
		
	}
}
void view2()
{
	struct node *trav;
	trav=head2;
	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}
void insert()
{
	int control;
	printf("1 for inserting after node and 2 to insert before node: ");
	scanf("%d",&control);
	
	struct node *temp, *trav;
	int item;
	trav=head1;
	
	temp=(struct node*)malloc(sizeof(struct node));
	printf("node to be inserted: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(control==1)
	{
		printf("Enter node after which you want to insert data: ");
		scanf("%d",&item);
		while(trav->data!=item)
			trav=trav->next;
			
		if(trav==tail)
		{
			trav->next=temp;
			tail=temp;
		}
		else
		{
			temp->next=trav->next;
			trav->next=temp;
		}
		
	}
	else if(control==2)
	{
		printf("Enter node before which you want to insert data: ");
		scanf("%d",&item);
		if(item==head1->data)
		{
			temp->next=head1;
			head1=temp;
		}
		else
		{
			while(trav->next->data!=item)
				trav=trav->next;
			
			temp->next=trav->next;
			trav->next=temp;
		}
	}
	
}
void deletion()
{
	int control;
	printf("1 for deleting first instance of node or 2 to delete all instances of a node: ");
	scanf("%d",&control);
	
	struct node *trav, *temp;
	trav=head1;
	int item;
	printf("enter the item to be deleted: ");
	scanf("%d",&item);
	if(control==1)
	{
		if(head1->data==item)
		{
			temp=head1;
			head1=head1->next;
			free(temp);	
		}
		else
		{
			while(trav->next->data!=item)
				trav=trav->next;
				
			temp=trav->next;
			trav->next=trav->next->next;
			free(temp);
		}
		if(trav->next==tail)
		{
			tail=trav;
		}
	}
	else if(control==2)
	{
		while(trav->next!=NULL)
		{
			if(trav->next->data==item)
			{
				temp=trav->next;
				trav->next=trav->next->next;
				free(temp);
				
				if(trav->next==tail)
					tail=trav;
			}
			else
				trav=trav->next;
		}
		if(head1->data==item)
		{
			temp=head1;
			head1=head1->next;
			free(temp);
		}
	}
}
void reverse()
{
	struct node *prev,*current,*trav;
	prev=NULL, trav=NULL, current=head1;
	while(current!=NULL)
	{
		trav=current->next;
		current->next=prev;
		prev=current;
		current=trav;
	}
	tail=head1;
	head1=prev;

}
void sort()
{
	struct node *trav1,*trav2;
	int temp;
	trav1=head1;
	while(trav1!=NULL)
	{
		trav2=head1;
		while(trav2->next!=NULL)
		{
			if((trav2->data)>(trav2->next->data))
			{
				temp=trav2->data;
				trav2->data=trav2->next->data;
				trav2->next->data=temp;
			}
			else
				trav2=trav2->next;
		}
		trav1=trav1->next;
	}
}
void merge()
{
	struct node *temp, *trav1, *trav2;
	trav1=head1 ,trav2=head2;

	while(trav1!=NULL && trav2!=NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		
		if(trav1->data<trav2->data)
		{
			temp->data=trav1->data;
			trav1=trav1->next;
		}
		else if(trav2->data<trav1->data)
		{
			temp->data=trav2->data;
			trav2=trav2->next;
		}
		else{
			temp->data=trav1->data;
			trav1=trav1->next;
			trav2=trav2->next;
		}
		
		if(head3==NULL)
		{
			head3=temp;
			tail3=temp;
		}
		else
		{
			tail3->next=temp;
			tail3=temp;	
		}
	}
		while(trav1!=NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=trav1->data;
			tail3->next=temp;
			tail3=temp;
			trav1=trav1->next;
		}
		while(trav2!=NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));	
			temp->data=trav2->data;
			tail3->next=temp;
			tail3=temp;
			trav2=trav2->next;
		}
		
	tail3->next=NULL;
}


void view3()
{
	struct node *trav;
	trav=head3;

	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}

