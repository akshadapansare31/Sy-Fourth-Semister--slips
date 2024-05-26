#include<stdio.h>
void floydwarshall(int a[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
  { 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][k]+a[k][j]<a[i][j])
			{
				a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
  }
   for(i=1;i<=n;i++)
   {
   	for(j=1;j<=n;j++)
   	{
   	if(i!=j)
	   printf("\n distance of (%d,%d)=%d",i,j,a[i][j]);
    }
   }
}
int main()
{
	int a[10][10],i,j,n;
	printf("enter the limit");
	scanf("%d",&n);
	printf("enter the matrix");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	floydwarshall(a,n);
}
