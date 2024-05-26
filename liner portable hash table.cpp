#include<stdio.h>
int ht[10]={-1};
void init()
{
	int i;
	for(i=0;i<10;i++)
	{
		ht[i]=-1;
	}
}
int hash(int num,int i)
{
	return (num%10+i)%10;
}
void insert(int num)
{
	int i,index;
	for(i=0;i<10;i++)
	{
		index=hash(num,i);
		if(ht[index]==-1)
		{
			ht[index]=num;
			break;
		}
	}
}
void disp()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\t",ht[i]);
	}
}
int search(int num)
{
	int i,index;
	for(i=0;i<10;i++)
	{
		index=hash(num,i);
		if(ht[index]==num)
		{
			return index;
		}
	}
	return -1;
}
void del(int num)
{
	int index=search(num);
	if(ht[index]==-1)
	printf("not found");
	else
	{
		ht[index]=-1;
		printf("\n del succ...");
	}
}
int main()
{
	int ch,num,index;
	init();
	do
	{
		printf("\n 1-insert \n 2-disp \n 3-search \n 4-del");
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter number:");
			       scanf("%d",&num);
			       insert(num);
			       break;
			case 2:disp();
				   break;
			case 3:printf("enter number:");
				   scanf("%d",&num);
				   index=search(num);
				   if(index==-1)
				   printf("number not found");
				   else
				   printf("\n number found position=%d",index);
				   break;
			case 4:printf("enter number");
				   scanf("%d",&num);
				   del(num);
				   break;
		
		}
	}while(ch<5);
}
