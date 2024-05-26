#include<stdio.h>
int main()
{
	int a[10][10];
	int n,i,j;
	printf("enter the vertices");
	scanf("%d",&n);
	printf("enter the adjucency matrix");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			{
				printf("\n enter the edge bet v%d and v%d",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
			
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
