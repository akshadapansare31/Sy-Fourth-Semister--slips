#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}node;
struct node *create(struct node *root)
{
	struct node *newnode,*temp,*p;
	int i,n;
	printf("enter limit");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter value:");
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
			if(newnode->data<=temp->data)
		    temp=temp->left;
			else
		    temp=temp->right;	
		}
		if(newnode->data<=p->data)
		p->left=newnode;
		else
		p->right=newnode;
	}
	return root;
}
struct node *insert(struct node *root)
{
	struct node *newnode,*temp,*p;
	int i,n;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter value to be inserted");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
	    root=newnode;
	}
	temp=root;
	while(temp!=NULL)
	{
		p=temp;
		if(newnode->data<=temp->data)
		temp=temp->left;
		else
		temp=temp->right;
	}
	if(newnode->data<=p->data)
	p->left=newnode;
	else
	p->right=newnode;
	return root;
}
void inorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
void preorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
struct node *copy(struct node *root)
{
	struct node *newnode,*temp=root;
	if(temp!=NULL)
	{
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=temp->data;
	newnode->left=copy(temp->left);
	newnode->right=copy(temp->right);
	return(newnode);
    }
else
return NULL;
}
int cntleaf(struct node *root)
{
	static int c=0;
	struct node *temp=root;
	if(temp!=NULL)
	{
		if(temp->left==NULL&&temp->right==NULL)
		c++;
		cntleaf(temp->left);
		cntleaf(temp->right);
	}
	return c;
}
int cntcode(struct node *root)
{
	static int c=0;
	struct node *temp=root;
	if(temp!=NULL)
	{
		c++;
		cntcode(temp->left);
		cntcode(temp->right);
	}
	return c;
}
void search(struct node *root,int num)
{
	struct node *temp=root;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->data==num)
		flag=1;
		if(num<temp->data)
		temp=temp->left;
		else
		temp=temp->right;
	}
	if(flag==1)
	printf("\n number is found ");
	else
	printf("\n number is not found");
}
int main()
{
	int ch ,num;
struct node *root=NULL,*root1=NULL;
do
{
	printf("\n 1-create \n 2-insert \n 3-inorder \n 4-preorder \n 5-postorder \n 6-copy \n 7-cntleaf \n 8-cntcode \n 9-search");
	printf("enter choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:root=create(root);
			  break;
		case 2:root=insert(root);
			   break;
		case 3:inorder(root);
			   break;
		case 4:preorder(root);
			   break;
		case 5:postorder(root);
		       break;
		case 6:root1=copy(root1);
			   printf("\n tree copy");
			   break;
		case 7:printf("\n leaf node");
				printf("%d\t",cntleaf(root));
		       break;
		case 8:printf("\n total node");
		        printf("%d\t",cntcode(root));
			   break;
		case 9:printf("enter number to search");
			   scanf("%d",&num);
			   search(root,num);
			   break;
	}
}while(ch<10);
}
