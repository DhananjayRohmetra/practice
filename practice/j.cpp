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

int main()
{
	
	int n,i,j;
	cin>>n;
	int arr[n+2],dp[10][500009],xrr[10],cnt;
	xrr[1]=4,xrr[2]=8,xrr[3]=15,xrr[4]=16,xrr[5]=23,xrr[6]=42; 
	memset(dp,1000000,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(i=1;i<=6;i++)
	{
		 cnt=1;
		for(j=1;j<=n;j++)
		{
			if((arr[j]==xrr[i] && j>dp[i-1][cnt] )|| (i==1 && arr[j]==xrr[i]) )
			{
				dp[i][cnt]=j;
				cnt++;
			}
		}

	}
int cnt2=0,ans=500009;
	for(i=1;i<=6;i++)
	{
		cnt2=0;
		for(j=1;j<=cnt;j++)
		{
			if(dp[i][j]<=500000)
			{
			cnt2++;	
			}

		}
		ans=min(cnt2,ans);
	
	}
cout<<n-ans*6;
}



