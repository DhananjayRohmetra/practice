#include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define m 1e9+7
vector<vector<int> >adj;
 set<int>set1;
ll n,c;
ll color[100003],prr[100003],result[100003],arr[100003];
 
 
int dfs(int s,int par)
{
	int c=0;
  for(auto i :adj[s])
  {
      if(i!=par)
      {
      c+=dfs(i,s);
      
      }
  }
  if(adj[s].size()==0 && prr[s]!=-1)
  {
  	set1.insert(s);
  }
  if(c==adj[s].size()-1 && prr[s]!=-1)
  {
  	set1.insert(s);
  }
  if(c==adj[s].size() && prr[s]!=-1)
  {
  	set1.insert(s);
  }
  return arr[i];
}
int main()
{
 
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n-1;i++)
    {
        cin>>prr[i]>>arr[i];
        
        if(x!=-1)
        {
        adj[prr[i]].push_back(i);
        adj[prr[i]].push_back(x);
    	}
    }

    dfs(1,-1);

}
