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
vector<vector<int> >adj;
int visited[100009],low[100009],disc[100009],parent[100009],size[100009],p;
int ttime,sz,answer=0;
void dfs(int s)
{
	visited[s]=1;
	size[s]=1;
	sz++;
	disc[s]=low[s]=ttime++;
	for(int i=0;i<adj[s].size();i++)
	{
		if(visited[adj[s][i]]==0)
		{
			parent[adj[s][i]]=s;
			dfs(adj[s][i]);
			size[s]+=size[adj[s][i]];
			low[s]=min(low[s],low[adj[s][i]]);
			if(low[adj[s][i]]>disc[s])
			{
				if(abs(sz-2*size[adj[s][i]])<p)
				{
					answer++;
				}
				//cout<<s<<" "<<adj[s][i];
			}
		}
		else if(adj[s][i]!=parent[s])
		{
			low[s]=min(low[s],disc[adj[s][i]]);
		}
	}
	
	
}
int main()
{
	int n,m,u,v;
	cin>>n>>m>>p;
	adj.resize(n+1);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			sz=0;
			ttime=0;
			dfs(i);
		}
	}
	cout<<answer;
}



