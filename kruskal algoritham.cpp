#include<stdio.h>
#include<stdlib.h>
#define max 30
int find(int);
int check(int,int);
int a,b,i,j,n,u,v,e=1;
int visited[10]={0},mincost=0,min,c[10][10],p[9];
int main()
{
	printf("\n");
	printf("enter the limit");
	scanf("%d",&n);
	printf("enter the adjucency matrix");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
			if(c[i][j]==0)
			c[i][j]=999;
		}
	}
	printf("mst \n");
	while(e<n)
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
		if(c[i][j]<min)
		{
			min=c[i][j];
			a=u=i;
			b=v=j;
		}
		u=find(u);
		v=find(v);
		if(check(u,v))
		{
			printf("%d edge(%d,%d)=%d\n",e++,a,b,min);
			mincost=mincost+min;
		}
		c[a][b]=c[b][a]=999;
	}
	printf("minimum cost=%d",mincost);
}
int find(int i)
{
	while(p[i])
	i=p[i];
	return i;
}
int check(int i,int j)
{
	if(i!=j)
	{
		p[v]=u;
		return i;
	}
	return 0;
}
