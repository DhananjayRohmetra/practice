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
int arr[1000][4],n,dp[1000][4];
int recur(int i,int s);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				cin>>arr[i][j];	
			}
		}	
		memset(dp,-1,sizeof(dp));
	recur(0,3);
	
	cout<<min(min(dp[0][0],dp[0][1]),dp[0][2])<<"\n";
	}
}
int recur(int i,int s)
{
	if(i>=n) return 0;
	
	if(dp[i][s]!=-1)
	return dp[i][s];
	if(i==0)
	{
		dp[i][0]=arr[i][0]+min(recur(i+1,1),recur(i+1,2));
		dp[i][1]=arr[i][1]+min(recur(i+1,0),recur(i+1,2));
		dp[i][2]=arr[i][2]+min(recur(i+1,0),recur(i+1,1));
		return min(min(dp[0][0],dp[0][1]),dp[0][2]);
	}
	else
	{
		if(s==0)
		{
			dp[i][0]=arr[i][0]+min(recur(i+1,1),recur(i+1,2));
			return dp[i][0];
		}
		if(s==1)
		{
			dp[i][1]=arr[i][1]+min(recur(i+1,0),recur(i+1,2));
			return dp[i][1];
		}
		if(s==2)
		{
			dp[i][2]=arr[i][2]+min(recur(i+1,0),recur(i+1,1));
			return dp[i][2];
		}
	}
}

