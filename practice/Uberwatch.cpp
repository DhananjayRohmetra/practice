#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("input.txt", "r", stdin);
    ll n, m;
    cin >> n >> m;
    ll arr[n+2];
    ll dp[n+2];
    for(int i=0;i<n;i++)
    dp[i]=0;

    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(int i=1;i<n;i++)
    {
        if(i>=m)
        {
            dp[i]=max(dp[i-m]+arr[i],dp[i-1]);
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}