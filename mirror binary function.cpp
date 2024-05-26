#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
node *create(node *root)
{
	int i,n;
	node *temp,*p,*newnode;
	printf("enter limit");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		newnode=(node*)malloc(sizeof(node));
		printf("enter value");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			p=temp;
			if(newnode->data<temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(newnode->data<p->data)
			p->left=newnode;
		else
			p->right=newnode;
	}
	return root;
}
node *mirror(node *root)
{
	node *temp=root,*temp1;
	if(temp!=NULL)
	{
		if(temp->left!=NULL)
		mirror(temp->left);
		if(temp->right!=NULL)
		mirror(temp->right);
		
		temp1=temp->left;
		temp->left=temp->right;
		temp->right=temp1;
	}
	return root;
}
int main()
{
	int ch,num;
	node *root=NULL;
	do
	{
		printf("/n 1-create /n 2-mirror");
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1:root=create(root);
			       break;
			case 2:mirror(root);
				   break;
		}
	}while(ch<2);
}
	
