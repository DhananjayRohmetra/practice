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

int main()
{
	int i,n,c,l,r,j,it;
	cin>>n;
	int arr[n+1];
	
	for(i=0;i<n;i++)
	cin>>arr[i];
	int dp[5000][5000][2];
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				dp[i][j][0]=1e12;
				dp[i][j][1]=1e12;
			}
		}
	}
	for(r=0;r<n;r++)
	{
		for(l=0;l<=r;l++)
		{
			for(it=0;it<2;it++)
			{
				if(it==0) c=arr[l];
				else c=arr[r];
				if(l)
				dp[l-1][r][0]=min(dp[l-1][r][0],dp[l][r][it]+int(c!=arr[l-1]));
				if(r+1>=n)
				dp[l][r+1][1]=min(dp[l][r+1][1],dp[l][r][it]+int(c!=arr[r+1]));
			}
		}
	}
cout<<min(dp[0][n-1][0],dp[0][n-1][1]);
	return 0;
}


