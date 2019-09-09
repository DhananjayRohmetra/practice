#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
#define ll long long
ll dp[2001],ans[2001][2001];
vector< vector< ll > >vec(2001);
int main()
{
	ll i,j,k,n,k1,s=0;
	
	cin>>n>>k1;
	for(i=1;i<=2000;i++)
	{
		for(j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				if(i/j==j)
				{
					dp[i]+=1;
					vec[i].push_back(j);
				}
				else
				{
					vec[i].push_back(j);
					vec[i].push_back(i/j);				
				dp[i]+=2;
		     	}
			}
		}
	}
	for(i=1;i<=2000;i++)
	{
		ans[2][i]=dp[i];
	}
	for(k=3;k<=2000;k++)
	{	
for(i=1;i<=2000;i++)
{
	for(j=0;j<vec[i].size();j++)
	{
	//ans[k][i]+=ans[k-1][vec[i][j]];
//	ans[k][i]=ans[k][i]+ans[k-1][vec[i][j]];
	(ans[k][i] += ans[k - 1][vec[i][j]]) %= m;

	}
}

}
for(i=1;i<=n;i++)
{
//s=(s+ans[k1][i]);
(s += ans[k1][i]) %= m;
//s=s%m;
}
if(k1!=1)
{

cout<<s;}
else
{
	cout<<n;
}
}

