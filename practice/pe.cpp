#include<bits/stdc++.h>
using namespace std;
int main()
{
  
      int n,m,x,y,i,flag=0,r,u;
      scanf("%d",&n); 
     int arr[n+9],parent[n+9];
      	
     
     vector<vector<int> >adj(n+1);
     vector<int>::iterator it;
     for(i=0;i<n-1;i++)
     {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     
      for(i=0;i<n;i++)
   {scanf("%d",&arr[i]);
   
   
   }
     
 bool visited[n];
queue<int>myqueue;
queue<int>q;
int s=1;
int level[200009];
level[s]=0;
parent[s]=0;
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
            parent[*it]=s;
            myqueue.push(*it);
        }
    }
    
    
}

q.push(1);
r=q.front();
u=2;
for(i=1;i<n;i++)
{
if(i-u==adj[r].size()-1)
{
	q.pop();

	r=q.front();
	u=i;
}

if(parent[arr[i]]!=r )
{
	flag=1;
	break;
}	



if(parent[arr[i]]==r && adj[arr[i]].size()>1)
q.push(arr[i]);


}
if(flag==1)
cout<<"No";
else
cout<<"Yes";


}
