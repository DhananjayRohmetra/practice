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
int s,n,m;
vector<vector<int > >arr;
vector<vector<int > >dp;
int recur(int col,int row)
{

	if(row>=n) 
	{
		return 0;
	}

	if(dp[row][col]!=-1)
	 return dp[row][col];

	s=0;
	for(int i=1;i<=m;i++)
	{
		if(i!=col)
		{


			dp[row][col]=max(dp[row][col],arr[row+1][i]+recur(i,row+1));
		}
	}

	return dp[row][col];
}
int main()
{
freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--)
	{
	int ans=0,i,j;
	cin>>n>>m;
	dp.resize(n+2);
for (ll i = 0; i < n+2; ++i)
    dp[i].resize(m+2);

	arr.resize(n+1);
for (ll i = 0; i < n+1; ++i)
    arr[i].resize(m+1);
for(i=0;i<=n+1;i++)
{
	for(ll j=0;j<=m+1;j++)
	{
		dp[i][j]=-1;
	}
}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>arr[i][j];
		}
	}
for(i=1;i<=m;i++)
		ans=max(ans,recur(i,0));
cout<<ans<<"\n";
		for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			//cout<<dp[i][j]<<" ";
		}
//cout<<"\n";
	}

	}
}




