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
ll n;
vector< pair< ll,ll > >vec;
vector< ll >tree[500000];
ll brr[100001];
ll arrr[100001];
void build(ll node,ll start,ll end)
{
	if(start>end)
	{
		return;
	}
	if(start==end)
	{
		tree[node].pb(brr[start]);
		return;
	}
	
	
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		merge(all(tree[2*node]),all(tree[2*node+1]),back_inserter(tree[node]));
	return;
}
ll query(ll node,ll start,ll end,ll l,ll r,ll k)
{
	if(start==end)
	{
		return tree[node][0];
	}
	
	ll mid=(start+end)/2;
	ll m=upper_bound(all(tree[2*node]),r)-lower_bound(all(tree[2*node]),l);
	if(m>=k)
	{
		return query(2*node,start,mid,l,r,k);
	}
	else
	{
		return query(2*node+1,mid+1,end,l,r,k-m);	
	}
	
}
int main()
{
	ll t,i,x,l,r,k;
	cin>>n>>t;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		arrr[i]=x;
		vec.push_back({x,i});
	}
	sort(vec.begin(),vec.end());
	for(i=0;i<n;i++)
	{
		brr[i+1]=vec[i].second;
	}
	build(1,1,n);
	while(t--)
	{
		cin>>l>>r>>k;
		cout<<arrr[query(1,1,n,l,r,k)]<<"\n";
	}

}

