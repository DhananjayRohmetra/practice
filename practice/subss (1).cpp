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
vector<vector<int> >vec;
vector<vector<int> >curr;
vector<vector<pair<int,int> > >adj;
vector<int>h;
int main()
{
	int divi[1000009],i,j,max_level=-1,min_curr,ans=-2;
	for(i=0;i<=1000009;i++)
	{
		divi[i]=1;
	}
	for(int i=2;i<=1000000;i++)
	{
		for(j=i;j<=1000000;j+=i)
		{
			divi[j]++;
		}
	}
	int x,n,q,u,v;
	cin>>n>>q;
	int arr[n+1];
	vec.resize(n+1);
	adj.resize(n+1);
	curr.resize(n+1);
	h.resize(n+1);
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		vec[u].pb(v);
		vec[v].pb(u);
	}
	
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	queue<int>qu;
	int level[1000009],visited[1000009];
	for(i=0;i<=1000000;i++)
	{
		level[i]=0;
		visited[i]=0;
	}
	qu.push(1);
	level[1]=0;
	visited[1]=1;
	adj[0].pb({divi[arr[1]],1});
	while(!qu.empty())
	{
		int fro=qu.front();
		qu.pop();
		for(i=0;i<vec[fro].size();i++)
		{
			if(visited[vec[fro][i]]==0)
			{
				visited[vec[fro][i]]=1;
				level[vec[fro][i]]=level[fro]+1;
				max_level=max(max_level,level[vec[fro][i]]);
				adj[level[vec[fro][i]]].pb(mp(divi[arr[vec[fro][i]]],vec[fro][i]));
				qu.push(vec[fro][i]);
			}
		}
	}
	
	for(i=0;i<max_level;i++)
	{
		sort(adj[i].begin(),adj[i].end());
	}
	for(i=0;i<max_level;i++)
	{
		min_curr=1000009;
		for(j=0;j<adj[i].size();j++)
		{
			
			min_curr=min(adj[i][j].second,min_curr);
			curr[i].pb(min_curr);
		}
	}
	h[0]=adj[1][0].first;
	for(i=1;i<max_level;i++)
	{
		h[i]=min(adj[i][0].first,h[i-1]);
	}
	while(q--)
	{
		ans=-2;
		cin>>x;
		int min_row=upper_bound(h.begin(), h.end(), divi[x], greater<int>())-h.begin();
		if(min_row!=max_level)
		{
			int min_col=lower_bound(adj[min_row].begin(), adj[min_row].end(), mp(divi[x],0))-adj[min_row].begin();
			if(min_col!=0){
			min_col--;
			ans=curr[min_row][min_col];}
		}
		if(ans!=-2)
		{
			cout<<ans<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}
	}
	
}



