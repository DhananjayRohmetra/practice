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
ll tree[500009],lazy[500009],n,arr[100009],j=1;

void update(ll node,ll start,ll end,ll l,ll r,ll add)
{
	if(lazy[node]!=0)
	{

		tree[node]=(end-start+1)*lazy[node]-tree[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r ||  end<l) return;
	if(start>=l && end<=r)
	{
	
		tree[node]=(end-start+1)*add-tree[node];
		if(start!=end)
		{
			lazy[2*node]=(lazy[2*node]+add)%2;
			lazy[2*node+1]=(lazy[2*node+1]+add)%2;
		}
		return;	
	}
		ll mid=(start+end)/2;
		update(2*node,start,mid,l,r,add);
		update(2*node+1,mid+1,end,l,r,add);
		tree[node]=tree[2*node]+tree[2*node+1];
		return;
	
}

ll query(ll node,ll start,ll end,ll l,ll r)
{
	
	if(lazy[node]!=0)
	{
		
		tree[node]=(end-start+1)*lazy[node]-tree[node];
		if(start!=end)
		{
			
			lazy[2*node]=(lazy[2*node]+1)%2;

			lazy[2*node+1]=(lazy[2*node+1]+1)%2;
		}
		lazy[node]=0;
	}
	if(start>end || start>r ||  end<l)
	 return 0;
	 
	if(start>=l && end<=r)
	{
		return tree[node];
	}
	ll mid=(start+end)/2;
	return 	query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);	
}
int main()
{

	ll i,c,x,y,z,r;
	cin>>n>>c;
	memset(lazy,0,sizeof(lazy));
	memset(arr,0,sizeof(arr));
	memset(tree,0,sizeof(tree));

	while(c--)
	{
		cin>>x;
		if(x==0)
		{
			cin>>y>>z;
			update(1,1,n,y+1,z+1,1);	
		}
		if(x==1)
		{
			cin>>y>>z;
			cout<<query(1,1,n,y+1,z+1)<<"\n";	

		}		
	}
//cout<<lazy[4]<<" "<<lazy[5];
	
}





