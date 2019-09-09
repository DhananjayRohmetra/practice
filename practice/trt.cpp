#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll recur(ll o,ll n,ll j);
ll dp[22][80][1000],i,j,m;
 ll o[1002],n[1002],wt[1009];
int main()
{
	ll t;
	cin>>t;
	while(t--)
    {
    	ll n1,o1,n2,o2;
       cin>>o2>>n2;
       cin>>m;
      
		for(i=0;i<m;i++)
    {
    	cin>>o[i]>>n[i]>>wt[i];
	}
	for(o1=1;o1<=21;o1++)
    {
    	for(n1=1;n1<=79;n1++)
    	{
		for(i=0;i<1000;i++)
    	{dp[o1][n1][i]=-1;}}}
       
        
       ll s=recur(o2,n2,m);
        
    cout<<s<<endl;
	
	}
}
    
ll recur(ll o2,ll n2,ll j)
{
	if(dp[o2][n2][j]!=-1)
    {
        return dp[o2][n2][j];
    }
    else if(o2==0 && n2==0)
    {
    	return 0;
	}
	else if(j==0)
	{
		return 99999999;
	}
	else
	{
			return dp[o2][n2][j]=min(wt[j-1]+recur(max(0,o2-o[j-1]),max(0,n2-n[j-1]),j-1),recur(o2,n2,j-1));
		
	}
}
 
 
