#include<stdio.h>
int main()
{
	int n;int a[100];int t=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n/2;i++)
	{
		if(a[i] < a[2*i +1] && a[i] < a[2*i+2]) continue;
		else 
		{
			t=1;
			break;
		}
	}
	if(t==0) printf("true");
	else printf("false");
}