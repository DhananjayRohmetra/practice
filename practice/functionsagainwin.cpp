#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long int arr[n+1],dp[n+1],i,s=0,s1=-1,dp1[n+1];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n-1;i++)
	{
		if(i%2==0)
		{
			dp[i]=abs(arr[i]-arr[i+1]);
		}
		else
		{
			dp[i]=abs(arr[i]-arr[i+1])*(-1);
		}
	}
	//maxi,um subbarray sum
	for(i=0;i<n-1;i++)
	{
	if(s+dp[i]<0)
	{
		s=0;
	}
	else
	{
		s+=dp[i];
		s1=max(s1,s);
	}
	}
//	cout<<s1;
for(i=1;i<n-1;i++)
{
	dp1[i]=-1*(dp[i]);

}

long long int s2=0,s3=-1;
	for(i=1;i<n-1;i++)
	{
	if(s2+dp1[i]<0)
	{
		s2=0;
	}
	else
	{
		s2+=dp1[i];
		s3=max(s3,s2);
	}
	}
	
	cout<<max(s1,s3);
}
