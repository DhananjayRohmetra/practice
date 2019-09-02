#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod=998244353;
const ll MAXN=300009;
ll dp[MAXN+10];
void factorial()
{
    dp[0]=dp[1]=1;
    for(ll i=2;i<=MAXN;i++)
    {
        dp[i]=dp[i-1]*i;
        dp[i]=(dp[i]+mod)%mod;
    }
}
int main()
{
    factorial();
    ll n,x,y,glo;
    cin>>n;
    glo=dp[n];
    vector<pair<ll,ll>>vec,inc,decr;
    for(ll i=0;i<n;i++)
    {
        cin>>x>>y;
        vec.push_back({x,y});
        decr.push_back({y,x});
    }
    inc=vec;
    sort(inc.begin(),inc.end());
    ll freq1[MAXN+10];
    memset(freq1,0,sizeof(freq1));
    for(ll i=0;i<n;i++)
    {
        freq1[inc[i].first]++;
    }
    ll ans1=1;
    for(ll i=0;i<MAXN;i++)
    {
        ans1*=dp[freq1[i]];
        ans1=(ans1+mod)%mod;
    }
 
    sort(decr.begin(),decr.end());
    ll freq2[MAXN+10];
    memset(freq2,0,sizeof(freq2));
    for(ll i=0;i<n;i++)
    {
        freq2[decr[i].first]++;
    }
    ll ans2=1;
    for(ll i=0;i<MAXN;i++)
    {
        ans2*=dp[freq2[i]];
        ans2=(ans2+mod)%mod;
    }
    glo=(glo-((ans1+ans2)%mod)+mod)%mod;
    ll flag=0;
	for(ll i=0;i<n-1;i++)
	{
		if(inc[i].first > inc[i+1].first ||  inc[i].second > inc[i+1].second)
		{
			flag=1;
			break;
		}
	}
	if(flag == 0)
	{
		
		ll res=1,cn=0;
		for(ll i=0;i<n-1;i++)
		{
			if(inc[i].first == inc[i+1].first && inc[i].second == inc[i+1].second)
			{
				cn++;
			}
			else
			{
				res*=dp[cn+1];
				res=(res+mod)%mod;
                                cn=0;
			}
		}
        
        res*=dp[cn+1];
        res=(res+mod)%mod;
		glo+=res;
        glo=(glo+mod)%mod;
	}
   cout<<glo;
}