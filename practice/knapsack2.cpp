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

int main()
{
	ll n,w,i,j;
	cin>>n>>w;
	
	ll wt[n+1],val[n+1],ans=-1;
	ll dp[102][100009];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=100000;j++)
		{
			if(j!=0)
			dp[i][j]=1000000001;
			else
			dp[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		cin>>wt[i];
		cin>>val[i];
	}

	for(i=0;i<100000;i++)
	{
		if(i==val[0])
			dp[0][i]=wt[0];
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<=100000;j++)
		{
			if(val[i]<=j)
			{ 
						
						dp[i][j]=min(dp[i-1][j],wt[i]+dp[i-1][j-val[i]]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	for(i=0;i<=100000;i++)
	{
		if(dp[n-1][i]<=w)
		{
			ans=max(ans,i);
		}
		//cout<<i<<" "<<dp[n-1][i]<<"\n";
	}
	cout<<ans;
	return 0;
}

