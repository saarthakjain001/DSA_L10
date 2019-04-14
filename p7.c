#include<stdio.h>
int main()
{
	int n,sum=0;int a[100];int count[100][2];
	scanf("%d",&n);
	count[0][0]=0;
	count[0][1]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
		 	count[i+1][0]=count[i][0]+1;
		 	count[i+1][1]=count[i][1];
		}
		else
		{
			count[i+1][0]=count[i][0];
		 	count[i+1][1]=count[i][1]+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(count[j][0]-count[i][0] == count[j][1] - count[i][1]) sum++;
		}
	}
	printf("%d",sum);
}