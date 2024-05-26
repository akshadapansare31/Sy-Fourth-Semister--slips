#include<stdio.h>
#include<stdlib.h>
#define max 20
struct node
{
    int data;
    struct node *left,*right;
}node;
struct que
{
  struct node *data1[max];
  int rear,front;
};
struct que q;
void init()
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
void add(struct node *num)
{
   q.data1[++q.rear]=num;
}

struct node *delq()
{
  return(q.data1[++q.front]);
}

struct node *create(struct node *root)
{
    struct node *newnode,*temp,*parent;
    int i,n,num;
    printf("enter how many nodes to create");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter values::");
        scanf("%d",&num);
        newnode->data=num;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
            root=temp=newnode;
            continue;
        }
        temp=root;
        while(temp!=NULL)
        {
            parent=temp;
            if(num<temp->data)
             temp=temp->left;
            else 
             temp=temp->right;
        }
         if(num<parent->data)
          parent->left=newnode;
         else
          parent->right=newnode;
    }
    return root;
}

//display node at each level
 //count node at each level
 //total level's in tree
  void level_order(struct node *root)
  {
    struct node *temp;
    int level=0,node=0;
    static int c=0;
   init();
    add(root);
    add(NULL);
    printf("\nlevel=%d:\t",level);
    while(!isempty())
    {
        temp=delq();
        if(temp==NULL)
        {
            printf("\ntotal node in%d level:%d",level,node);
            node=0;
            level++;
            if(!isempty())
            {
                add(NULL);
                printf("\n level=%d:\t",level);
            }
            c++;
            
        }
        else
        {
            printf("\tvalue=%d",temp->data);
            node++;
            if(temp->left!=NULL)
             add(temp->left);
            if(temp->right!=NULL)
             add(temp->right);
        }
    }
    printf("\ntotal levl count=%d\t",c);
    }
       

int main()
{
    int ch;
    struct node *root=NULL;
    root=create(root);
    level_order(root);
}
