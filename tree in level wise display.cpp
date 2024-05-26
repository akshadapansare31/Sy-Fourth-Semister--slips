#include<stdio.h>
#include<stdlib.h>
#define max 30
#define MEMORY (struct node *)malloc(sizeof(struct node))
typedef struct node
{
	int data;
	struct node *left,*right;
}node;

 struct que
{
	struct node *data1[max];
	int front,rear;
};
struct que q;
void initque()
{
	q.front=q.rear=-1;
}
int isempty()
{
	return(q.front==q.rear);
}
int isfull()
{
	return(q.rear==max-1);
}

void add(node *num)
{
	q.data1[++q.rear]=num;
}

node *delq()
{
	return q.data1[++q.front];
}

 node *create(node *root)
 {
 	node *temp,*newnode,*parent;
 	int i,n;
 	printf("enter limit::");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 	  newnode=MEMORY;
	  printf("enter element::");
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
	  	parent=temp;
	  	if(newnode->data>temp->data)
	  	  temp=temp->right;
	  	else
	  	  temp=temp->left;
	  }
	  if(newnode->data>parent->data)
	    parent->right=newnode;
	  else
	   parent->left=newnode;
	}
	return root;
 }
 
 void level_disp(node *root)
 {  
    int level=0;
 	node *temp,*m=NULL;
 	
 	initque();
 	add(root);
 	add(m);
    printf("\nlevel_%d=>",level);
 	while(!isempty())
 	{
      temp=delq();
	  if(temp==m)
	  {
	    level++;
		if(!isempty())
		{
		add(m);
		printf("\nlevel_%d=>",level); 
	    }
	  }	
	  else
	  {
	  	printf("%d\t",temp->data);
	  	if(temp->left)
	  	add(temp->left);
	  	if(temp->right)
	  	add(temp->right);
	  }	
    }
 }
 
int main()
{
	node *root=NULL;
	root=create(root);
	level_disp(root);
}
