#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll result=0;
void mergesort(ll arr[],ll temp[],ll l,ll r);
void merge(ll arr[],ll temp[],ll l,ll mid,ll r);

int main()
{
	ll n,i;
	cin>>n;
	ll arr[n+2],temp[n+2];
		for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,temp,0,n-1);
	cout<<result;
}

void mergesort(ll arr[],ll temp[],ll l,ll r)
{
    if(r>l){
	ll mid=l+(r-l)/2;
	
	mergesort(arr,temp,l,mid);
	mergesort(arr,temp,mid+1,r);
        merge(arr,temp,l,mid,r);}
}
void merge(ll arr[],ll temp[],ll l,ll mid,ll r)
{
	ll i,j,k;
	k=l;
	i=l;
	j=mid;
	while(i<=mid && j<=r)
	{
		if(arr[i]<=arr[j])
		{
temp[k++]=arr[i++];
			
		}
			if(arr[i]>arr[j])
		{
		temp[k++]=arr[j++];
			result+=(mid-i);
		}
		k++;
	}
while(i<=mid-1)
{
temp[k++]=arr[i++];
}

while(j<=r)
{
	temp[k++]=arr[j++];
}
for(i=l;i<=r;i++)
{
	arr[i]=temp[i];
}
}
