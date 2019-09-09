#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[10000000];
 void buildtree(ll arr[],ll node,ll low,ll high);
int main()
{
	ll n,t,i,p=0;
	cin>>n>>t;
	ll arr[n+9];
	
	for(i=1;i<=n;i++)
	cin>>arr[i];
	
		for(i=1;i<=5*n;i++)
tree[i]=(1000000000000000);
	
buildtree(arr,1,1,n);
	for(i=1;i<=5*n;i++)
	{
	
	if(tree[i]<t)
	{
		p++;
	}
}
cout<<p;
}
 void buildtree(ll arr[],ll node,ll low,ll high)
{
	if(low==high)
	{
		tree[node]=arr[low];
	}
	else
	{
    ll 	mid=low+(high-low)/2;
	buildtree(arr,2*node,low,mid);
	buildtree(arr,2*node+1,mid+1,high);
	tree[node]=tree[2*node]+tree[2*node+1];
    }
}
