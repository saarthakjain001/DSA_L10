#include<stdio.h>
void swap(int*  a,int* b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void decrease(int *a,int k,int n)
{
	for(int i=0;i<k;i++)
	{
		for(int j=n-1;j>0;j--)
		{
			if(a[j]>a[j-1])
			{
				swap(&a[j],&a[j-1]);
			}
		}
	}
}
void min_heapify(int *a,int i,int n)
{
	int smallest,left=2*i+1,right=2*i+2;
	if(left<n && a[left]<a[i]) smallest = left;
	else smallest =i;
	if(right<n && a[right]<a[smallest]) smallest=right;
	if(smallest!=i)
	{
		swap(&a[i],&a[smallest]);
		min_heapify(a,smallest,n);
	}
}
void build_min_heap(int *a,int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		min_heapify(a,i,n);
	}
}
int main()
{
	int n,k,a[100],b[100],arr[100];
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	decrease(a,k,n);
	decrease(b,k,n);
	for(int i=0;i<k;i++)
	{
		arr[i] = a[0] + b[i];
	}
	build_min_heap(arr,k);
	for(int i=1;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(a[i] + b[j] > arr[0])
			{
				arr[0] = a[i] + b[j];
				min_heapify(arr,0,n);
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		printf("%d ",arr[i]);
	}
}	