#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll l,r,dp[100009];
ll recur(ll i,ll freq[]);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,i;
	    cin>>n>>l>>r;
	    memset(dp,-1,sizeof dp);
        ll arr[n+2],freq[100002];
    for(i=0;i<=100000;i++)
     {
     freq[i]=0;
     }
	 for(i=1;i<=n;i++)
     {
     cin>>arr[i];
     freq[arr[i]]++;
     }
     
		cout<<recur(1,freq)<<endl;
	
		for(i=1;i<=100000;i++)
		cout<<dp[i]<<"\n";
	}
}

ll recur(ll i,ll freq[])
{
	if(i==100000 )
	{
		return i*freq[i];
	}
	if(i>100000)
	return 0;
	if(dp[i]!=-1)
	return dp[i];
	if(freq[i]==0)
	{
		dp[i]=recur(i+1,freq);
		return dp[i];
	}
	else if(freq[i]!=0)
	{
		dp[i]=max(recur(i+1,freq),i*freq[i]+recur(i+min(l,r)+1,freq));
		return dp[i];
	}
}
