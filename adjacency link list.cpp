#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *list[10];
void create(int a[10][10],int n)
{
	struct node *temp,*newnode;
	int i,j;
	for(i=1;i<=n;i++)
	{
		list[i]=NULL;
		for(j=1;j<=n;j++)
		{
		if(a[i][j]==1)
		{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=j;
		newnode->next=NULL;
		if(list[i]==NULL)
		{
			list[i]=temp=newnode;
	    }
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
     	}
        }
	}
}
void disp(int n)
{
	struct node *temp;
	int i;
	for(i=1;i<=n;i++)
	{
		printf("\n list%d->",i);
		for(temp=list[i];temp!=NULL;temp=temp->next)
		{
			printf("%d->",temp->data);
		}
		printf("NULL");
	}
}
int main()
{
	int a[10][10],i,j,n;
	printf("ente limit");
	scanf("%d",&n);
	printf("enter graph in the matrix format");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	create(a,n);
	disp(n);
}
