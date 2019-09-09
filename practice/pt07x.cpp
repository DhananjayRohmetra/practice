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
void dfs(ll s,ll par);
ll dp[100000][3];

 vector<vector<ll> >adj(100001);
int main()
{


      ll n,x,y,i;
      scanf("%d",&n);

     vector<ll>::iterator it;
     for(i=0;i<n-1;i++)
     {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     for(i=0;i<n;i++)
     {
     	dp[i][0]=0;
     	dp[i][1]=0;
	 }
	dfs(1,0);
	cout<<min(dp[1][0],dp[1][1]);
}

void dfs(ll s,ll par)
{
	ll s1=0;
	ll s2=0,i;
  for(auto i :adj[s])
  {
      if(i!=par)
      {
      dfs(i,s);

	  s1+=dp[i][1];
	  s2+=dp[i][0];
      }
  }
  dp[s][0]=s1;
  dp[s][1]=1+min(s1,s2);
}
