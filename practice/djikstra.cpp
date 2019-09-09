#include<bits/stdc++.h>
using namespace std;
#define ll long
#define iPair pair<ll,ll>
int main()
{ 
	ll n,m,i,x,y,u,v,z,w;
	cin>>n>>m;
	vector<vector<iPair > >vec(n+1);
	ll dst[n+9];
	for(i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		vec[x].push_back(make_pair(y,z));
		vec[y].push_back(make_pair(x,z));
	}
	for(i=1;i<=n;i++)
	{
		dst[i]=999;
	}
	dst[1]=0;
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
	pq.push(make_pair(1,0));
	while(!pq.empty())
	{
		u=pq.top().first;
		pq.pop();
		for(i=0;i<vec[u].size();i++)
		{
			v=vec[u][i].first;
			w=vec[u][i].second;
			if(dst[v]>dst[u]+w){
			dst[v]=dst[u]+w;
			pq.push(make_pair(v,dst[v]));}
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<dst[i]<<" ";
	}
 
}
