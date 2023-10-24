//prime numbers numbers in BST
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

void create();
void traversal(struct node *root);
void prime(int);

int main()
{
	while(1){
		int ch;
		printf("1 to create 2 to find prime numbers: ");
		scanf("%d",&ch);
		if(ch==1)
			create();
		else if(ch==2)
		{
			printf("Prime numbers\n");
			traversal(root);
			printf("\n");
		}
		else
			break;
			
	}
}

void create()
{
	int n,i;
	struct node *temp, *trav;
	printf("No of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter node: ");
		scanf("%d",&temp->data);
		temp->left=NULL; temp->right=NULL;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			trav=root;
			while(1)
			{
				if(temp->data>trav->data)
				{
					if(trav->right==NULL)
					{
						trav->right=temp;
						break;
					}
					else
						trav=trav->right;
				}
				else if(temp->data<trav->data)
				{
					if(trav->left==NULL)
					{
						trav->left=temp;
						break;
					}
					else
						trav=trav->left;
				}
				else if(trav->data==temp->data)
				{
					printf("Unvalid node\n");
					break;
				}		
			}	
		}
	}		
}
void traversal(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		int x=root->data;
		prime(x);
		traversal(root->left);
		traversal(root->right);	
	}	
}

void prime(int x){
	int i,flag=0;
	if(x==1)
		return;
	else
	{
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("%d\t",x);
	}
}
