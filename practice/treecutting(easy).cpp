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
int dpb[400009],dpr[400009],arr[400009];
int tb=0,tr=0,d=0;
vector< vector<int> >adj;
void finaldfs(int s,int par)
{
			if((tb==dpb[s] && dpr[s]==0 && tb!=0)|| (tr==dpr[s] && dpb[s]==0 && tr!=0))
			{
				d++;
			}
		//	cout<<dpb[s]<<" "<<dpr[s]<<"\n";
		for(auto  i:adj[s])
	{
		
		if(i!=par)
		{
	
			finaldfs(i,s);
		}
	}
}
int dfsb(int s,int par)
{
if(arr[s]==2)
{
	dpb[s]++;
}
	
	for(auto  i:adj[s])
	{
		
		if(i!=par)
		{
			
				dpb[s]+=dfsb(i,s);
		}
	}
	
	return dpb[s];
}
int dfsr(int s,int par)
{

if(arr[s]==1)
{
	dpr[s]++;
}	
	for(auto  i:adj[s])
	{
		if(i!=par)
		{
			
			dpr[s]+=dfsr(i,s);
			
		}
	}

	return dpr[s];
}
int main()
{
int n,i,x,y;
cin>>n;
for(i=1;i<=n;i++)
{
	cin>>arr[i];
}
adj.resize(n+1);
for(i=0;i<n-1;i++)
{
	cin>>x>>y;
	adj[x].pb(y);
	adj[y].pb(x);
}
memset(dpr,0,sizeof(dpr));
memset(dpb,0,sizeof(dpb));


dfsb(1,0);
dfsr(1,0);
if(arr[1]==1)
{
tb=dpb[1];
tr=1+dpr[1];
}
if(arr[1]==2)
{
tr=dpr[1];
tb=1+dpb[1];
}
else
{
	tr=dpr[1];
	tb=dpb[1];
}
finaldfs(1,0);
cout<<d;
}
