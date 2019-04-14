#include<stdio.h>
int main()
{
	int n,p;char s[100];int bin[100];
	scanf("%d %d\t",&n,&p);
	gets(s);
	bin[0]=1;bin[n+1]=1;
	for(int i=1;i<=n;i++)
	{
		bin[i]=0;
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<p;i++)
	{
		int store1,store2,length=0,t1=0;
		for(int j=1;j<n+2;j++)
		{
			if(bin[j]!=0)
			{
				if(j-t1>length)
				{
					length = j-t1;
					store1 = t1;
					store2 = j;
					t1=j;
				}
			}
		}
		if((store1+store2+1)%2!=0) bin[(store1+store2)/2]=i+1;
		else
		{
			if(s[i]=='L') bin[(store1+store2)/2]=i+1;
			else bin[((store1+store2)/2)+1] = i+1;
		}
	}
	for(int i=0;i<q;i++)
	{
		int x;
		scanf("%d",&x);	
		if(bin[x]==0) printf("-1\n");
		else printf("%d\n",bin[x]);
	}
}