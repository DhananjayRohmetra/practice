#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int n; cin>>n;
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(i<=1)
        {
            dp[1][i]=1;
        }
        dp[i][0]=1;
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(j>=i)
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            
        }
        
    }
    cout<<dp[n-1][n];
    
}