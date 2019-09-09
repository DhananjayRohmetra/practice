#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
      int n,m,x,y,i,d=0;
      scanf("%d %d",&n,&m); 
     vector<vector<int> >adj(n+1);
     vector<int>::iterator it;
     for(i=0;i<m;i++)
     {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     
 bool visited[n];
queue<int>myqueue;
int s=1;
int level[100000];
level[s]=0;
for(i=1;i<=n;i++)
{
    visited[i]=false;
}
myqueue.push(s);
visited[s]=true;
while(!myqueue.empty())
{
    s=myqueue.front();
    myqueue.pop();
    for(it=adj[s].begin();it<adj[s].end();it++)
    {
        if(visited[*it]==false)
        {
            visited[*it]=true;
            level[*it]=level[s]+1;
            myqueue.push(*it);
        }
    }
    
    
}
for(i=1;i<=n;i++)
{
	if(adj[i].size()%2!=0)
	{
		d++;
	}
}
cout<<d;
}
}
