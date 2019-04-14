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
	int a[] = {1,2,3,4,5,6,0};
	build_max_heap(a,7);
	for(int i=0;i<7;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	build_min_heap(a,7);
	for(int i=0;i<7;i++)
	{
		printf("%d ",a[i]);
	}
}