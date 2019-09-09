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
 
int main()
{

ll n,m,x,y,i;
cin>>n>>m;
 vector<vector< ll > >adj(n+1);
 vector<ll>::iterator it;
for(i=0;i<m;i++)
{
	cin>>x>>y;
	adj[x].push_back(y);
	adj[y].push_back(x);
}
 

bool visited[n+1];
priority_queue< ll > myqueue;
int s=1;
for(i=1;i<=n;i++)
{
    visited[i]=false;
}
myqueue.push(-1*s);
visited[s]=true;
while(!myqueue.empty())
{
    s=-1*myqueue.top();
    cout<<s<<" ";
    myqueue.pop();
    for(it=adj[s].begin();it<adj[s].end();it++)
    {
        if(visited[*it]==false)
        {
            visited[*it]=true;
         
            myqueue.push((-1)**it);
            
        }
    }
    
    
}

}

