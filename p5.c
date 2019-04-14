#include<stdio.h>
void swap(int*  a,int* b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void max_heapify(int *a,int i,int n)
{
	int largest,left=2*i+1,right=2*i+2;
	if(left<n && a[left]>a[i]) largest = left;
	else largest =i;
	if(right<n && a[right]>a[largest]) largest=right;
	if(largest!=i)
	{
		swap(&a[i],&a[largest]);
		max_heapify(a,largest,n);
	}
}
void build_max_heap(int *a,int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		max_heapify(a,i,n);
	}
}
int main()
{
	int n;int a[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	build_max_heap(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}