#include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define m 1e9+7
vector<vector<ll> >adj;
ll n,c,ans=0,ans1=0;
ll color[100003],dp[100003];
ll dfs(ll s,ll par)
{
    
      for(auto i :adj[s])
      {
          if(i!=par)
          {
              c=dfs(i,s);         
              if(c>=dp[1][s])
              {
                  dp[2][s]=dp[1][s];
                  dp[1][s]=c;
              }
              if(dp[2][s]<c && dp[1][s]>c)
              {
                  dp[2][s]=c;
              }
          }
      }
      if(color[s]%2==0)
      {
          dp[1][s]++;
          return dp[1][s];
      }
      else
      {
          return dp[1][s]=0;
      }
}

void dfs1(ll s,ll par)
{
    
  for(auto i :adj[s])
  {
      if(i!=par)
      {
           c=dfs1(i,s);         
              if(c>=dp[1][s])
              {
                  dp[2][s]=dp[1][s];
                  dp[1][s]=c;
              }
              if(dp[2][s]<c && dp[1][s]>c)
              {
                  dp[2][s]=c;
              }
      }
  }
  if(color[s]%2!=0)
  {
          dp[1][s]++;
          return dp[1][s];
  }
  else
  {
      dp[1][s]=0;
  }

}

int main()
{

    ll x,y,i;
    cin>>n;
    adj.resize(n+1);
    for( i=1;i<=n;i++)
    {
        cin>>color[i];
    }
    
    for( i=1;i<=n-1;i++)
    {
        cin>>x>>y;;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    cout<<ans<<" ";

    for(i=0;i<100003;i++)
    {
        dp[i]=0;
    }
     dfs1(1,-1);
  
    cout<<ans1;
}
