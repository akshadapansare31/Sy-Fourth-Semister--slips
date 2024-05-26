#include<stdio.h>
int i,j,n,s,v,min,count=0;
int visited[10],c[10][10],dist[10];
void dijkstras()
{
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		dist[i]=c[s][i];
	}
	visited[s]=1;
	dist[s]=0;
	while(count<=n)
	{
		min=999;
		for(i=1;i<=n;i++)
		if(dist[i]<min&&visited[i]==0)
		{
			min=dist[i];
			v=i;
		}
		visited[v]=1;
		count++;
		for(i=1;i<=n;i++)
		if(dist[i]>dist[v]+c[v][i])
		dist[i]=dist[v]+c[v][i];
	}
}
int main()
{
	printf("\n enter the number of vertices=");
	scanf("%d",&n);
	printf("\n enter the cost matrix=");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
			if(c[i][j]==0)
			c[i][j]=999;
		}
	}
	printf("\n enter the source vertex=");
	scanf("%d",&s);
	dijkstras();
	printf("\n shortest path form %d id \n",s);
	for(i=1;i<=n;i++)
	if(s!=i)
	printf("%d->%d=%d\t",s,i,dist[i]);
}
