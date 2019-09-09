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
int cnt=0,flag=0;
vector<vector<int > >adj;
vector<int>topsort;
int indegree[100009],outdegree[100009];
queue<int>q;

int main()
{
//freopen ("input.txt","r",stdin);
    int n,m,i,x,z,j;
    char y;
    cin>>n>>m;
    adj.resize(n+1);
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        if(y=='>')
        {
            adj[z].pb(x);   
        }
        if(y=='<')
		{
            adj[x].pb(z);
        }
    }
    memset(outdegree,0,sizeof(outdegree));
    memset(indegree,0,sizeof(indegree));
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
        
        	if(adj[i][j]!=0)
        	{
        		indegree[adj[i][j]]++;
        		outdegree[i]++;
			}
		}
		
    }
    int in=0;
    for(i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			in++;
		}
	}
    for(i=1;i<=n;i++)
    {
    	if(indegree[i]==0)
    	{
    		q.push(i);
		}
	}
	
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		topsort.pb(s);
		cnt++;
		for(i=0;i<adj[s].size();i++)
		{ 
			if(--indegree[adj[s][i]]==0)
			{
				q.push(adj[s][i]);
			}
		}
	}
	if(cnt!=n)
	{
		flag=1;
	}
	int cnt0=0,out=0;
	for(i=1;i<=n;i++)
	{
		if(adj[i].size()==0)
		{
			cnt0++;
		}
		if(outdegree[i]==0){
			out++;
		}
	}
	if(cnt0!=1 || out!=1 || in!=1)
	{
		flag=1;
	}
	if(flag==1)
	{
		cout<<"Impossible";
	}
	else
	{
	for(i=0;i<topsort.size();i++)
	{
		cout<<topsort[i]<<" ";
	}
	}

}

