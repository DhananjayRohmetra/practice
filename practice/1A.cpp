#include<bits/stdc++.h>
using namespace std;
void dfs(int s);
void dfs1(int s,int p,int curr);
vector< vector< int > >g(600001);
map<pair<int ,int > ,int>mo,up,down;
int dwn=0,ue=0,ans[300000],visited[300000],x;
int main()
{
	int n,i,a,sum=0,b,s,j;
	cin>>n;
	

	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		mo[make_pair(a,b)]=1;
	g[b].push_back(a);
	
	}
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	dfs1(1,1,0);
ans[1]=ue;
int min=INT_MAX;
	for(i=1;i<=n;i++)
	{
		if(ans[i]<min)
		{
			min=ans[i];
		}
	}

	cout<<min<<"\n";
	for(i=1;i<=n;i++)
	{
	if(ans[i]==min)
	{
		cout<<i<<" ";
	}
	}
}
void dfs(int s)
{
	visited[s]=1;
	for(int i=0;i<g[s].size();i++)
	{
       if(visited[g[s][i]]==0)
		{
			x=g[s][i];
			
			if(mo[make_pair(s,x)])
			{
				down[make_pair(s,x)]=1;
				dwn++;
			}
			else
			{
				up[make_pair(s,x)]=1;
				ue++;
			}
			
			dfs(g[s][i]);
		}
	}
}
void dfs1(int s,int p,int curr)
{
		visited[s]=1;
	for(int i=0;i<g[s].size();i++)
	{
       if(visited[g[s][i]]==0)
		{
			x=g[s][i];
		
	
			ans[x]=ue-2*(curr+up[make_pair(s,x)])+p;
			dfs1(g[s][i],p+1,curr+up[make_pair(s,x)]);
		}
	}
	
}
