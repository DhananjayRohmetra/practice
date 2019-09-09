#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll p=998244353;
ll power(ll x, unsigned ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
      
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
}
int main()
{
int t;
cin>>t;
while(t--)
{
	 int n,m,x,y,i,flag=0,s1=0,s2=0,r=1;
      scanf("%d %d",&n,&m); 
     vector<vector<int> >adj(n+1);
     vector<int>::iterator it;
     for(i=0;i<m;i++)
     {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     
 int  visited[n+1];
 int hello[n+5];
queue<int>myqueue;
for(i=1;i<=n;i++)
{
	hello[i]=0;
    visited[i]=0;
}

for(s=1;s<=n;s++)
{
if(visited[s]==0)
{
	s2=0;
hello[s]=1;
s2++;
myqueue.push(s);
visited[s]=1;
s1=0;
while(!myqueue.empty())
{
    s=myqueue.front();
  s1++;
    myqueue.pop();
    for(it=adj[s].begin();it<adj[s].end();it++)
    {
        if(visited[*it]==0)
        {
        	if(hello[s]!=hello[*it])
        	{
			
        	if(hello[s]==1)
        	{
        		hello[*it]=2;
			}
			else
			{
				hello[*it]=1;
				s2++;
			}
		}
		else
		{
			flag=1;
		}
            visited[*it]=1;
          
            myqueue.push(*it);
        }
        if(hello[s]==hello[*it])
        {
        	flag=1;
		}
		
    }
    
    
}
if(s1==1)
{
	r=3*r;
}
else
{

r=((r%p)*((power(2,s2,p)+power(2,s1-s2,p))%p))%p;}
}}
if(flag==1)
{
	cout<<"0\n";
}
else
{
cout<<r<<"\n";
}
}
}
