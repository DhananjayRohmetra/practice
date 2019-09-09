#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector< vll >
#define write(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define read(v) for(int i=0;i<v.size();i++)cin>>v[i];
#define write1(v) for(int i=1;i<v.size();i++)cout<<v[i]<<" ";
#define read1(v) for(int i=1;i<v.size();i++)cin>>v[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
void build(ll node,ll start,ll end);
void update(ll node,ll start,ll end,ll idx,ll val);
ll hp2(ll x)
{
	ll g=0;
	while(x/2 != 0)
	{
		x/=2;
		g++;
	}
	return g;
}
ll tree[400009];
ll n,arr[100009];
int main()
{


ll m,i,n1,idx,val;
cin>>n1>>m;
n=pow(2,n1);

for(i=1;i<=n;i++){

cin>>arr[i];

}

build(1,1,n);


	
	
	
for(i=1;i<=m;i++)
{
	cin>>idx>>val;
	update(1,1,n,idx,val);
	
	cout<<tree[1]<<"\n";
//	for(ll j=1;j<=n;j++)
//	{
//		cout<<arr[i]<<" ";
//	}
	
}

	return 0;
}
void build(ll node,ll start,ll end)
{
	if(start>end)
	return;
	
	if(start==end)
	{
		tree[node]=arr[start];
	}
	else
	{
	
	ll mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	if(n%2==0)
	{
		if(hp2(2*node)%2==0)
		{
			tree[node]=tree[2*node]|tree[2*node+1];
		}
		else
		{
				tree[node]=tree[2*node]^tree[2*node+1];
		}
	}
	else
	{
		if(hp2(2*node)%2==0)
		{
			tree[node]=tree[2*node]^tree[2*node+1];
		}
		else
		{
				tree[node]=tree[2*node]|tree[2*node+1];
		}
	}
}
	
}
void update(ll node,ll start,ll end,ll idx,ll val)
{
	if(start>end)
	return;
	
	if(start==end)
	{
		arr[idx]=val;
		tree[node]=val;
	}
	else
	{
	
	ll mid=(start+end)/2;
	if(idx>=start && idx<=mid)
	{
	
	update(2*node,start,mid,idx,val);
	}
	else
	{
	
	update(2*node+1,mid+1,end,idx,val);}
	if(n%2==0)
	{
		if(hp2(2*node)%2==0)
		{
			tree[node]=tree[2*node]|tree[2*node+1];
		}
		else
		{
				tree[node]=tree[2*node]^tree[2*node+1];
		}
	}
	else
	{
		if(hp2(2*node)%2==0)
		{
			tree[node]=tree[2*node]^tree[2*node+1];
		}
		else
		{
				tree[node]=tree[2*node]|tree[2*node+1];
		}
	}
}
	
}
