#include<bits/stdc++.h>
using namespace std;
#define MAX5 100010
#define pb push_back
#define mp make_pair
void merge(int arr[],int st,int mid,int end)
{
	int A[100001];
	int i=st,j=mid+1,k=0;
	while(i<=mid && j<=end)
	{
		if(arr[i]>arr[j])
			A[k++]=arr[j++];
		else
			A[k++]=arr[i++];
	}
	if(i<=mid)
	{
		while(i<=mid)
			A[k++]=arr[i++];
	}
	if(j<=end)
	{
		while(j<=end)
		{
			A[k++]=arr[j++];
		}
	}
	int temp=0;
	for(int l=st;l<=end;l++)
	{
		arr[l]=A[temp++];
	}
}
void merge_sort(int arr[],int st,int end)
{
	if(st<end)
	{
		int mid=(st+end)/2;
		merge_sort(arr,st,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,st,mid,end);
	}
}
int main()
{
	int arr[100001];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
return 0;
}
