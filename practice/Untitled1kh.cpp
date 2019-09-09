#include <bits/stdc++.h> 
using namespace std;  
#define ll long long
void recur(ll r,ll c,ll x1,ll y1);
ll n,m,x,y,f=0,arr[2009][2009];
int main()
{
	ll i,j,r,c;
cin>>n>>m;
cin>>r>>c;
cin>>x>>y;
for(i=1;i<=n;i++)
{
	for(j=1;j<=m;j++)
	{
		cin>>x;
		if(x=='*')
		{
			arr[i][j]=0;
		}
		else
		{
			arr[i][j]=1;
		}
	}
}
recur(r,c,0,0);
cout<<f;
}
void recur(ll r,ll c,ll x1,ll y1)
{
	if(r>n || c>m || x1==x || y1==y || arr[r][c]==0)
	{
		return;
	}
	else
	{
		f++;
	recur(r,c+1,x1,y1);
	recur(r,c-1,x1,y1);
	recur(r-1,c,x1+1,y1);
	recur(r+1,c,x1,y1+1);
    }
}

