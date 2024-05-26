#include<stdio.h>
#include<stdlib.h>
#define max 50
struct queue
{
	int data[max];
	int r,f;
};
struct queue q;
void init()
{
	q.f=q.r=-1;
}
int isempty()
{
	return(q.f==q.r);
}
int isfull()
{
	return(q.r==max-1);
}
void addq(int num)
{
	q.data[++q.r]=num;
}
int delq()
{
	int val;
	val=q.data[++q.f];
	return val;
}
void bfs(int a[10][10],int n)
{
	int i,j;
	int visited[10]={0};
	printf("\n bfs");
	init();
	i=1;
	visited[i]=1;
	addq(i);
	while(!isempty())
	{
		i=delq();
		printf("%d\t",i);
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1 && visited[j]==0)
			{
				addq(j);
				visited[j]=1;
			}
		}
	}
}
int main()
{
	int a[10][10],i,j,n;
	printf("enter limit");
	scanf("%d",&n);
	printf("enter graph");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	bfs(a,n);
}
