#include<bits/stdc++.h>
using namespace std;
void dfs1(int k);
vector< vector< int > >g(100001);
int visited[100009],low[100009],visit[100009],p[100009];
int tim,child;
int main()
{
	int n,m,i,a,b;
	cin>>n>>m;
 
 
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	
		visit[i]=0;
		low[i]=0;
		p[i]=0;}
p[1]=-1;	
    	
dfs1(1);
   
	
}
void dfs1(int k)
{
	int ap=0;
	child=0;
visited[k]=1;
visit[k]=tim;
low[k]=tim;
tim++;
  for(  auto it: g[k])
	{
	
		if(it==p[k])
		continue;
       if(visited[it]==0)
		{
			p[it]=k;
			child++;
		dfs1(it);
	
     
     	if(visit[k]<=low[it])
     	{
     		ap=1;
		 }
		 else
		 {
		 	low[k]=min(low[k],low[it]);
		 }
	   }
	 else
	 low[k]=min(low[k],visit[it]);
         
    }
    
    if((p[k]==-1 && child>=2) || (p[k]!=-1 && ap!=0) )
    {
    
    	ap=1;
 
	}
}

