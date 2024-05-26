#include<stdio.h>
#include<stdlib.h>
#define max 30
struct stack
{
	int data[max];
	int top;
};
struct stack s;
void init()
{
	s.top=-1;
}
int isempty()
{
	return(s.top=-1);
}
int isfull()
{
	return(s.top==max-1);
}
void push(int v)
{
	s.data[++s.top]=v;
}
int pop()
{
	return(s.data[s.top--]);
}
void dfs(int a[10][10],int n ,int i)
{
	int j;
	static int visited[10]={0};
	visited[i]=1;
	printf("V%d\t",i);
	for(j=1;j<=n;j++)
	{
		if(a[i][j]==1 && visited[j]==0)
		{
			dfs(a,n,j);
		}
	}
}
int main()
{
	int i,j,n,a[10][10];
	printf("enter number of vertex");
	scanf("%d",&n);
	printf("enter adjucency matrix");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	}
	dfs(a,n,1);	
}
