//Smallest number in BST
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

void create();
void Smallest(struct node *root);


int main()
{
	while(1){
		int ch;
		printf("1 to create 2 to find biggest numbers: ");
		scanf("%d",&ch);
		if(ch==1)
			create();
		else if(ch==2)
		{
			Smallest(root);
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
void Smallest(struct node *root)
{
	struct node *trav;
	if(root==NULL)
		printf("there are 0 nodes in this tree");
	else
	{
		trav=root;
		while(trav->left!=NULL)
			trav=trav->left;
		
		printf("Smallest number is %d",trav->data);
	}	

}

