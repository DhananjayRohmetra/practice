#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ll n,i,res=0,x,y;
cin>>n;
map<ll,ll>mp;
for(i=0;i<n;i++)
{
	cin>>x>>y;
	mp[x]=y;
	if(mp[y]!=x)
	{
		res=res+1+max(y,x);
	}
	else
	{
		res=res+1+min(y,x);
	}
}
cout<<res;

}

