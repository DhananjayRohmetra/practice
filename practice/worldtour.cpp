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
	ll n,i,x,y,ans=0;
	cin>>n;
	ll xrr[n+1],yrr[n+1];
	map<ll,ll>mpx,mpy,visited;
	map<pair<ll,ll>,ll>mp,visitedmp,visitedmp2;
	for(i=0;i<n;i++)
	{
   		cin>>x>>y;
   		if(visitedmp[{x,y}]==0)
		{
		visitedmp[{x,y}]=1;
		mpx[x]++;
		mpy[y]++;
		xrr[i]=x;
		yrr[i]=y;
		}
	}

	for(i=0;i<n;i++)
	{
		if(visitedmp2[mp(xrr[i],yrr[i])]==0)
		{
		visitedmp2[{xrr[i],yrr[i]}]=1;
		if(visited[xrr[i]]==0)
		{
		visited[xrr[i]]=1;
		ans+=(mpx[xrr[i]]*(mpx[xrr[i]]-1))/2;
		}
		if(visited[yrr[i]]==0)
		{
		visited[yrr[i]]=1;
		ans+=(mpx[yrr[i]]*(mpx[yrr[i]]-1))/2;
		}
		}
	}
	/*for(i=0;i<n;i++)
	{
		if(visitedmp[{xrr[i],yrr[i]}0]==0)
		{
			visitedmp[{xrr[i],yrr[i]}]=1;
			ans-=(mp[{xrr[i],yrr[i]}]*(mp[{xrr[i],yrr[i]}]-1))/2;
		}
	}*/
	cout<<ans;
}



