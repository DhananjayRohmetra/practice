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

void update(ll node,ll start,ll end,ll idx,ll val);
ll query(ll node ,ll start ,ll end, ll l,ll r);


ll tree[500000];
int main()
{


ll i,n;
cin>>n;
ll ans=-100009;
ll brr[n+9],arr[n+9];
for(i=1;i<=n;i++){
cin>>brr[i];
arr[i]=0;
}
	
for(i=1;i<=n;i++)
{
	arr[brr[i]]=1+query(1,1,n,1,brr[i]-1);
	ans=max(ans,arr[brr[i]]);
	update(1,1,n,brr[i],arr[brr[i]]);
}
cout<<ans;

}
void update(ll node,ll start,ll end,ll idx,ll val)
{
	if(start>end)
	return;
	
	if(start==end)
	{
		//arr[idx]=val;
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
	update(2*node+1,mid+1,end,idx,val);
	}
	tree[node]=max(tree[2*node],tree[2*node+1]);
	}
}
ll query(ll node ,ll start ,ll end, ll l,ll r)
{
	if(r < start || end < l)
    {
        return 0;
    }
    if(l <= start && end <= r)
    {
        return tree[node];
    }
    
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return max(p1 , p2);	
}

