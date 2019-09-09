// author : dhananjay
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll crr[10009],m,drr[10009],dp[10009],k,max1=600000000,h;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll i,x,y,j,a,b,s,g=0,flag=0;
		cin>>a>>b;
		k=b-a;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			crr[i]=y;
            drr[i]=x;
		}
 
		for(i=0;i<=k;i++)
		dp[i]=max1;
		
		dp[0]=0;
		for(i=0;i<=k;i++)
		{
			for(j=0;j<m;j++)
			{
				if(i>=crr[j])
				{
					dp[i]=min(dp[i],dp[i-crr[j]]+drr[j]);
				}
			}
		}
		
		if(dp[k]>=600000000)
		{
		cout<<"This is impossible."<<endl;
		}
		if(dp[k]<600000000)
		{
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[k]<<"."<<endl;	
		}
	}
}

