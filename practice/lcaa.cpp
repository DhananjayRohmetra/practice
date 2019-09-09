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
#define all(v) v.begin(),v.end()
int p[100009][19],l[100009],mm[100009];
vector< vector<int> >adj;
void dfs(int s,int par)
{
	for(auto  i:adj[s])
	{
		if(i!=par)
		{
			l[i]=1+l[s];
			dfs(i,s);
			p[i][0]=s;


		}
	}
}
int findancestor(int pp,int lvl)
{
int k,i;
for( k=1;(1<<k)<=l[pp];k++);
k--;

for(i=k;i>=0;i--)
{
	if((1<<i)<=lvl)
	{
	    lvl-=(1<<i);
		pp=p[pp][i];
	}
}
    return pp;
}
int getlca(int pp,int qq)
{
	if(l[pp]<l[qq])
{
	swap(pp,qq);
}

int k,i;
for( k=1;(1<<k)<=l[pp];k++);
k--;

for(i=k;i>=0;i--)
{
	if(l[pp]-(1<<i)>=l[qq])
	{
		pp=p[pp][i];
	}
}

if(pp==qq) return pp;

for(i=k;i>=0;i--)
{
	if(p[pp][i]!=p[qq][i] && pp[p][i]!=-1)
	{
		pp=p[pp][i];
		qq=p[qq][i];
	}
}

return p[pp][0];
}

int main()
{

int n,x,i,j,f;
cin>>n;
adj.resize(n+1);

for(i=0;i<n-1;i++)
{
	cin>>x;
	adj[x].pb(i+1);
	adj[i+1].pb(x);
}
memset(p,-1,sizeof(p));

dfs(0,-1);
for(j=1;(1<<j)<n;j++)
{
	for(i=0;i<n;i++)
	{
		if(p[i][j-1]!=-1)
		{
			p[i][j]=p[p[i][j-1]][j-1];
		}
	}
}
int m;
cin>>m;
for(i=0;i<m;i++)
{
	cin>>mm[i];
}
f=getlca(mm[0],mm[1]);
for(i=2;i<m;i++)
{
	f=getlca(f,mm[i]);
}
int rr=findancestor(8,3);
cout<<rr;
}




