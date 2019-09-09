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
#define all(v) v.begin(),v.end()

struct data {
	ll rightsum;
	ll leftsum;
	ll totalsum;
	ll bestsum;
};

ll n;
ll arr[50001],p=0;
struct data tree[800005];


data combine(data l ,data r)
{
	data res;
	res.totalsum=l.totalsum+r.totalsum;
	res.leftsum=max(l.leftsum,l.totalsum+r.leftsum);
	res.rightsum=max(r.rightsum,r.totalsum+l.rightsum);
	res.bestsum=max(l.rightsum+r.leftsum,max(l.bestsum,r.bestsum));
	return res;
}

data fleaf(ll val)
{
	data leaf;
	leaf.totalsum=val;
	leaf.leftsum=max(p,val);
	leaf.rightsum=max(p,val);
	leaf.bestsum=max(p,val);
	return leaf;
}

void build(ll v,ll start,ll end)
{
	if(start==end)
	{
		tree[v]=fleaf(arr[start]);
	}
	else
	{
		ll mid=(start+end)/2;
		build(2*v,start,mid);
		build(2*v+1,mid+1,end);
		tree[v]=combine(tree[2*v],tree[2*v+1]);
	}
	
}

data query(ll v,ll start,ll end,ll l,ll r)
{
	
	if(start>end || r<start || end<l) 
	return fleaf(-1e14);
	
	if(start>=l && end<=r)
	return tree[v];
	
	ll mid=(start+end)/2;
	return combine(query(2*v,start,mid,l,r),query(2*v+1,mid+1,end,l,r));
}

int main()
{
fast;
ll i,m,l,r;
data res;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	build(1,1,n);
	
	cin>>m;
	while(m--)
	{
	cin>>l>>r;
	
	res=query(1,1,n,l,r);
	cout<<res.bestsum<<"\n";	
	}
}


