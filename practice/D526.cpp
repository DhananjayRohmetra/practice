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
vector<vector<pair<ll,ll> > >adj;
ll dp[300009][3],w[300009];
void dfs(ll s,ll par)
{
	ll ss=0;
	ll mx1=-1,mx2=-1;
	for(ll i=0;i<adj[s].size();i++)
	{
		if(adj[s][i].first!=par)
		{
			dfs(adj[s][i].first,s);
			
		
		if(mx1<dp[adj[s][i].first][0]-adj[s][i].second)
		{
			mx2=mx1;
			mx1=dp[adj[s][i].first][0]-adj[s][i].second;
		}
		else if(mx1>=dp[adj[s][i].first][0]-adj[s][i].second && mx2<dp[adj[s][i].first][0]-adj[s][i].second)
		{
			mx2=dp[adj[s][i].first][0]-adj[s][i].second;
		}
		}
		
	}
//	cout<<mx1<<" "<<mx2<<"\n";
		if(mx2!=-1 && mx1!=-1)
		{
			dp[s][0]=max(w[s],mx1+w[s]);
			dp[s][1]=max(w[s],mx1+mx2+w[s]);
		}
		if(mx2==-1 && mx1!=-1)
		{
			dp[s][0]=max(w[s],mx1+w[s]);
			dp[s][1]=w[s];
		}
		if(mx2==-1 && mx1==-1)
		{
			
			dp[s][0]=max(dp[s][0],w[s]);
			dp[s][1]=max(dp[s][1],w[s]);
		}
	
}
int main()
{
	ll n,i,u,v,c,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	adj.resize(n+1);
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v>>c;
		adj[u].pb(mp(v,c));
		adj[v].pb(mp(u,c));
	}
	dfs(1,-1);
	for(i=1;i<=n;i++)
	{
	//	cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
		ans=max({ans,dp[i][0],dp[i][1]});
	}
	cout<<ans;
}



