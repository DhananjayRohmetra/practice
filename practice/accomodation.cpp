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
ll m,n,s,d=0;
ll mod=1e9+7; 
vector<vector<ll >>dp;
ll arr[1000010];
ll recur(ll x,ll i,ll m,ll n)
{
    
	if(x>0 && i==m ) return 0; 
	if(x==0)
	{
		return 1;
	}
	if(x<0)
	{
		return 0;
	}

	if(dp[i][x]!=-1)
	{
		return dp[i][x];
	}
	
	ll s=0;
	for(ll j=i;j<m;j++)
	{
	    if(x>=arr[j]){
		s=(s+recur(x-arr[j],j,m,n))%mod;}
		else
		{
		    break;
		}
	}
	
	dp[i][x]=s;
	return dp[i][x];
}
int main()
{
    fast;
ll i;
scanf("%lld %lld",&m,&n);
dp.resize(m);
for (ll i = 0; i < m; ++i)
    dp[i].resize(n);
for(i=0;i<m;i++)
{
	scanf("%lld",&arr[i]);
}
sort(arr,arr+m);
for(i=0;i<m;i++)
{
	for(ll j=0;j<n;j++)
	{
		dp[i][j]=-1;
	}
}
ll ans=0;
for(i=0;i<m;i++)
{
ans=(ans%mod+recur(n-arr[i],i,m,n)%mod)%mod;
}
printf("%lld",ans);
}


