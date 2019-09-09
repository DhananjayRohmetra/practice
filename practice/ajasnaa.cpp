#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[5][100005],p=1,n;
ll ar[100009];
ll recur(ll i,ll prev)
{

    if(i==n) return 1;

    if(dp[i][prev]==-1) return dp[i][prev];
    if(dp[i][prev]==1) return dp[i][prev];

        if(ar[i]>ar[i+1])
        {
            if(ar[i]==1) return -1;
           for(ll j=prev-1;j>=1;j--)
           {
            dp[i][prev]=max(p,recur(i+1,j));
           }
        }

        if(ar[i]<ar[i+1])
        {
            if(ar[i]==5) return -1;

           for(ll j=prev+1;j<=5;j++)
           {
            dp[i][prev]=max(p,recur(i+1,j));
           }

        }

        if(ar[i]==ar[i+1])
        {
            for(ll j=1;j<=5;j++)
            {
                if(j!=prev)
                {
                    dp[i][prev]=max(p,recur(i+1,j));
                }
            }
        }

}

int main()
{

    scanf("%lld",&n);

    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&ar[i]);
    }
    for(ll k=1;k<=5;k++)recur(1,k);

    for(ll i=1;i<=5;i++)
    {
        for(ll j=1;j<=n;j++)
        {
        cout<<dp[i][j];
        }
        cout<<"\n";
    }
}
