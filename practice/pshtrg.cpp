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
#define MAXN 100000

vector< ll >tree[4*MAXN];
ll n;
vector<ll> f(vector<ll> a ,vector<ll> b)
{
	vector<ll>c;
	c.resize(a.size()+b.size());
	merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	reverse(c.begin(),c.end());
	c.resize(50);
	reverse(c.begin(),c.end());
	return c;
}
void update(ll node, ll start, ll end, ll index,ll val)
{
	if(start>end)
	return;
	if(start==end)
	{
		
		tree[node]={val};
		return;
	
	}
	ll mid=(start+end)/2;
	if(index<=mid && start<=mid)
	{
		update(2*node,start,mid,index,val);
	}
	else
	{
		update(2*node+1,mid+1,end,index,val);
	}
	tree[node]=f(tree[2*node],tree[2*node+1]);
}



vector<ll> get(ll node,ll start,ll end,ll l,ll r)
{
	
	if(start>end || end<l  || start>r)
	return vector<ll>(0);
	
	if(start>=l && end<=r)
	{
		return tree[node];
	}
	else
	{
		ll mid=(start+end)/2;
		return f(get(2*node,start,mid,l,r),get(2*node+1,mid+1,end,l,r));
	}
}
ll get(ll a, ll b)
{
	ll ans=0;
	vector<ll> v=get(1,1,n,a,b);
	for(ll i=2;i<v.size();i++)
	{
		if(v[i]<v[i-1]+v[i-2])
		{
			ans=max(ans,v[i]+v[i-1]+v[i-2]);
		}
	}
	return ans;
}
int main()
{
	ll q,a,b,c,i,x;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		update(1,1,n,i,x);
	}
	while(q--)
	{
		cin>>a>>b>>c;
		if(a==1)
		{
			update(1,1,n,b,c);
		}
		else
		{
		cout<<get(b,c)<<"\n";
		}
	}

}




