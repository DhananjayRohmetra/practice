#include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define m 1e9+7
vector<vector<ll> >adj;
ll n,c,ans=0,ans1=0;
ll color[100003],dp[100003];
void dfs1(ll s,ll par,ll max1,ll max2);
void dfs(ll s,ll par,ll max1,ll max2)
{
   
  for(auto i :adj[s])
  {
      if(i!=par)
      {
      dfs(i,s,max1,max2);         
    if(dp[i]>=max1)
      {
          max2=max1;
          max1=dp[i];
      }
      if(max2<dp[i] && max1>dp[i])
      {
          max2=dp[i];
      }

      }
  }
       if(adj[s].size()>=3 || (s==1 && adj[1].size()>=2)){
  dp[s]+=max1+max2;}
    if(adj[s].size()==2 || (s==1 && adj[1].size()==1))
    {
      dp[s]+=max1;  
    }
  if(color[s]%2==0)
  {
  
      dp[s]++;
          ans=max(ans,dp[s]);
  }
  else
  {
      dp[s]=0;
  }

}

void dfs1(ll s,ll par,ll max1,ll max2)
{
    
  for(auto i :adj[s])
  {
      if(i!=par)
      {
      dfs1(i,s,max1,max2);         
      if(dp[i]>=max1)
      {
          max2=max1;
          max1=dp[i];
      }
      if(max2<dp[i] && max1>dp[i])
      {
          max2=dp[i];
      }

      
      }
  }
    if(adj[s].size()>=3 || (s==1 && adj[1].size()>=2)){
      
  dp[s]+=max1+max2;}
    if(adj[s].size()==2 || (s==1 && adj[1].size()==1))
    {
      dp[s]+=max1;  
    }
    
  if(color[s]%2!=0)
  {
      dp[s]++;
      ans1=max(ans1,dp[s]);
  }
  else
  {
      dp[s]=0;
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
    dfs(1,-1,-1,-1);
    cout<<ans<<" ";

    for(i=0;i<100003;i++)
    {
        dp[i]=0;
    }
     dfs1(1,-1,-1,-1);
  
    cout<<ans1;
}
