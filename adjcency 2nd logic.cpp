#include<stdio.h>
int main()
{
    int a[10][10],i,j,n;
    printf("\n enter limit");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		printf("\n edge between V%d and V%d",i,j);
    		scanf("%d",&a[i][j]);
		}
	}
	printf("\n enter adjucency matrix =\n");
	for(i=1;i<=n;i++)
	printf("\t V%d",i);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("\n V%d",i);
		for(j=1;j<=n;j++)
		printf("\t%d",a[i][j]);
	}
}
