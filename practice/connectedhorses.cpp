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
ll n,m,q;

ll mod=1000000007,cnt=0;
ll matrix[1004][1004];
ll visited[1004][1004],dp[1004][1004];
ll dfs(ll x,ll y)
{
    
	if(x>n || x<1 || y>m || y<1)
	{
		return 0;
	}
	if(matrix[x][y]==0)
	{
		return 0;
	}
	if(visited[x][y]==1)
	{
		return 0;
	}
	else
	{
	visited[x][y]=1;
	cnt++;
	dfs(x+2,y+1);
	dfs(x+2,y-1);
	dfs(x+1,y+2);
	dfs(x+1,y-2);
	dfs(x-2,y+1);
	dfs(x-2,y-1);
	dfs(x-1,y+2);
	dfs(x-1,y-2);
	return cnt;
	}
	
}
int main()
{
	ll another[1000009];
	
	for(int i=0;i<=1000000;i++)
	{
		another[i]=1;
	}
	for(int i=2;i<=1000000;i++)
	{
		another[i]=((i%mod)*(another[i-1]%mod) + mod)%mod;
		// ((i%mod)*(another[i-1]%mod))%mod
	}
		//cout<<another[5];
	int t;
	cin>>t;
	while(t--)
	{
		ll ans=1;
   		ll i,j,x,y;
   		cin>>n>>m>>q;
   		
		memset(matrix,0,sizeof(matrix));
			
		memset(visited,0,sizeof(visited));
		for(i=0;i<q;i++)
		{
			cin>>x>>y;
			matrix[x][y]=1;
			dp[x][y]=1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(matrix[i][j]==1 && visited[i][j]==0)
				{
				    cnt=0;
					ll y=dfs(i,j);
					//cout<<y<<"\n";
					if(y!=0)
				{
			    ans=((ans%mod)*(another[y]%mod)+mod)%mod;
				    
				}	
			}
				}
		}
	cout<<ans<<"\n";
		
	}
}



