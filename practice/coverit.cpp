#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define all(v) v.begin(), v.end()
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
   	int n,x,y,i,m,theircount;
      scanf("%d %d",&n,&m); 
      int level[n+1];
     vector<vector<int> >adj(n+1);
     vector<int>::iterator it;
     adj.clear();
     for(i=0;i<m;i++)
     {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     memset(level,0,sizeof(level));
 bool visited[n+1];
stack<int>myqueue;
int s=1;

level[s]=1;
int anseven=0,ansodd=1;
for(i=1;i<=n;i++)
{
    visited[i]=false;
}
myqueue.push(s);
visited[s]=true;
while(!myqueue.empty())
{
    s=myqueue.top();
    myqueue.pop();
    for(it=adj[s].begin();it<adj[s].end();it++)
    {
        if(visited[*it]==false)
        {
        	level[*it]=level[s]+1;
        	if(level[*it]%2==0)
        	{
        		anseven++;
			}
			else
			{
				ansodd++;
			}
            visited[*it]=true;
            myqueue.push(*it);
        }
    }
}
int e;
if(anseven<=n/2)
{
	e=0;
}
else if(ansodd<=n/2)
{
	e=1;
}
if(e==1){
	cout<<ansodd<<"\n";
}
else
{
	cout<<anseven<<"\n";
}
s=1;
for(i=1;i<=n;i++)
{
    visited[i]=false;
}
if(e==1)
{
theircount=1;
cout<<s<<" ";
}
else
{
	theircount=0;
}
myqueue.push(s);
visited[s]=true;
while(!myqueue.empty())
{
    s=myqueue.top();
    myqueue.pop();
    for(it=adj[s].begin();it<adj[s].end();it++)
    {
        if(visited[*it]==false)
        {
        	
        	if(level[*it]%2==e)
        	{	
        		if(theircount<n/2){
				theircount++;
        		cout<<*it<<" ";
        		}
			}
            visited[*it]=true;
            myqueue.push(*it);
        }
    }
}
cout<<"\n";
	}
}
