#include<stdio.h>
void indegree(int a[10][10],int n)
{
	int i,j,in;
	for(i=1;i<=n;i++)
	{
		in=0;
		for(j=1;j<=n;j++)
		{
			in=in+a[j][i];
		}
		printf("\n indegree v%d=%d",i,in);
		
	}
}
void outdegree(int a[10][10],int n)
{
	int i,j,out;
	for(i=1;i<=n;i++)
	{
		out=0;
		for(j=1;j<=n;j++)
		{
			out=out+a[i][j];
		}
		printf("\n outdegree v%d=%d",i,out);
		
	}
}
void totaldegree(int a[10][10],int n)
{
	int i,j,in;
	for(i=1;i<=n;i++)
	{
		in=0;
		for(j=1;j<=n;j++)
		{
			in=in+a[j][i]+a[i][j];
		}
		printf("\n totaldegree v%d=%d",i,in);
		
	}
}
int main()
{
	int a[10][10],i,j,n;
	printf("enter limit");
	scanf("%d",&n);
	printf("enter the graph in the matrix format");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	indegree(a,n);
	outdegree(a,n);
	totaldegree(a,n);
}

