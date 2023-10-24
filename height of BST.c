//height of BST
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;
void create();
int height(struct node *root);
void inorder(struct node *root);


int main()
{
	while(1){
		int ch;
		printf("\n1 to create 2 to find height 3 for inorder: ");
		scanf("%d",&ch);
		if(ch==1)
			create();
		else if(ch==2)
		{
			int h=height(root);
			printf("Height of BST: %d",h);	
		}
		
		
		else if(ch==3)
		{
			printf("Inorder traversal\n");
			inorder(root);
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
				else if(temp->data==trav->data)
				{
					printf("Unvalid node\n");
					break;
				}		
			}	
		}
	}		
}


void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);	
	}	
}

int height(struct node *root)
{
	if(root==NULL)
		return 0;
	else{
		int left_height= height(root->left);
		int right_height= height(root->right);
		if(left_height>right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}
