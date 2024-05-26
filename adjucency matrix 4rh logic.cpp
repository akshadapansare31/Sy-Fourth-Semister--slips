#include<stdio.h>
#include<stdlib.h>

int main()
{
        int a[10][10],i,j,n;
        printf("\nEnter No of vertices :: ");
        scanf("%d",&n);

        //printf("\nEnter Adjacency Matrix ::\n");

        for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                        {
                                printf(" \n Enter the edge between V%d and V%d  :: ",i,j);
                                scanf("%d",&a[i][j]);
                        }

        printf("\nEnter Adjacency ::\n");
       
        for(i=1;i<=n;i++)
                printf("\t v%d",i);

        printf("\n");
        for(i=1;i<=n;i++)
        {
                printf("\n v%d",i);
                for(j=1;j<=n;j++)
                        printf("\t%d",a[i][j]);
        }
}
