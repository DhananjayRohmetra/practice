#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
      int n,m,x,y,i,z;
      scanf("%d ",&n); 
     vector<vector<pair<int,int>> >adj(n+1);
     for(i=0;i<n-1;i++)
     {
        scanf("%d %d %d",&x,&y,&z);
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
     }
     
 bool visited[n];
queue<int>myqueue;
int s=1;
int xorr[100000],level[100000];
xorr[s]=0;
level[s]=0;
for(i=1;i<=n;i++)
{
    visited[i]=false;
}
myqueue.push(s);
visited[s]=true;
int cnt=0;
while(!myqueue.empty())
{
    s=myqueue.front();
    myqueue.pop();
    for(i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i].first]==false)
        {
            visited[adj[s][i].first]=true;
            level[adj[s][i].first]=level[s]+1;
            xorr[adj[s][i].first]=(adj[s][i].second)^xorr[s];
            myqueue.push(adj[s][i].first);
        }
    }
    if(adj[s].size()==1 && level[s]!=0)
    {
    	if(xorr[s]%2!=0)
    	{
    		cnt++;
		}
	}
    
}
printf("%d\n",cnt);
}
}
