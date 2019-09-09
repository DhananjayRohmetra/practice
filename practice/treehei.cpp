#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define all(v) v.begin(), v.end()
vector< vector< int > >adj;
int nibbi[100009],in[100009],out[100009];
void dfs(int s,int par)
{
	for(int i=0;i<adj[s].size();i++)
	{
		if(adj[s][i]!=par)
		{
			dfs(adj[s][i],s);
			in[s]=max({in[s],in[adj[s][i]]});
		}
	}
	in[s]+=nibbi[s];
	
}
void dfs2(int s,int par)
{
	int mx1=-100001,mx2=-100001,i;
	for(i=0;i<adj[s].size();i++)
	{
		if(adj[s][i]!=par)
		{
		
		if(in[adj[s][i]]>mx1)
		{
			mx2=mx1;
			mx1=in[adj[s][i]];
			
		}
		else if(in[adj[s][i]]>mx2)
		{
			mx2=in[adj[s][i]];
		}
		}
	}
//	cout<<mx1<<" "<<mx2<<"\n";
	for(int i=0;i<adj[s].size();i++)
	{
		if(adj[s][i]!=par)
		{
			int use=mx1;
			if(in[adj[s][i]]==mx1)
			{
				use=mx2;
			}
			out[adj[s][i]]+=max({out[s],+nibbi[s]+use});
			dfs2(adj[s][i],s);
		}
	}
	
	
}
int main()
{
	int n,k,i,u,v;
	cin>>n>>k;
	adj.resize(n+1);
	for(i=0;i<n-1;i++)
	{
   	cin>>u>>v;
	adj[u].pb(v);
	adj[v].pb(u);
	}
	for(i=1;i<=n;i++) cin>>nibbi[i];
	dfs(1,-1);
	for(i=1;i<=n;i++) out[i]=nibbi[i];
	dfs2(1,-1);
	int ans=-10000000;
	for(i=1;i<=n;i++) 
	{
		ans=max({0,out[i],in[i],ans});
	}
	cout<<k+ans;
}



