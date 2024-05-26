#include<stdio.h>
#include<stdlib.h>
int a,b,u,v,i,j,n,e=1;
int visited[10]={0},mincost=0,min,c[10][10];
int main()
{
	printf("enter the number of vertices");
	scanf("%d",&n);
	printf("enter adjcency matrix");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
			if(c[i][j]==0)
			c[i][j]=999;
		}
	}
	visited[1]=1;
	printf("\n");
	for(e=1;e<=n;e++)
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
			if(c[i][j]<min&&visited[i]==0)
			{
				min=c[i][j];
				a=u=i;
				b=v=j;
			}
			if(visited[u]==0||visited[v]==0)
			{
				printf("\n edge :(%d->%d)cost:%d",min,e++,a,b);
				mincost=mincost+min;
				visited[b]=1;
			}
			c[a][b]=c[b][a]=999;
	}
	printf("\n minimum distance=%d",mincost);
}
