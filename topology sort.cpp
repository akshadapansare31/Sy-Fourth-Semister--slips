#include<stdio.h>
#include<stdlib.h>
#define max 30
int a[10][10];
int i,j,k,n;
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
void top()
{
	init();
	int v[10]={0};
	int ind[10]={0};
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ind[i]=ind[i]+a[i][j];
		}
		while(1)
		{
			for(i=1;i<=n;i++)
			{
				if(ind[i]==0 && v[i]==0)
				push(i);
				v[i]=1;
				printf("V%d\t",i);
			}
			k=pop();
			for(j=1;j<=n;j++)
			{
				if(a[k][j]==1)
				ind[j]=ind[j]-1;
			}
			if(isempty())
			{
				break;
			}
		}
	}
	
}
int main()
{
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
	top();	
}
