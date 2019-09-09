#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	int p1[10002],p2[10002],i,ans=1;
	for(i=0;i<n;i++)
	{
		cin>>p1[i]>>p2[i];
	}

	ans+=min(p1[0],p2[0]);
	for(i=1;i<n;i++)
	{
		if(p1[i]>p2[i])
		{
			if(p2[i]>=p1[i-1])
			{
				if(p1[i-1]==p2[i-1])
				{
					ans+=max(0,min(p1[i],p2[i])-max(p2[i-1],p1[i-1]));
				}
				else
				ans+=max(0,min(p1[i],p2[i])-max(p2[i-1],p1[i-1])+1);
				
			}
		}
		if(p1[i]<p2[i])
		{
			if(p2[i]>=p1[i-1])
			{
					if(p1[i-1]==p2[i-1])
				{
					ans+=max(0,min(p1[i],p2[i])-max(p2[i-1],p1[i-1]));
				}
				else
				ans+=max(0,min(p1[i],p2[i])-max(p2[i-1],p1[i-1])+1);
			}
		}
		if(p1[i]==p2[i])
		{
				
				if(p1[i-1]==p2[i-1] && p1[i-1]==p1[i])
				{
					ans=ans;
				}
				else if(p1[i-1]==p2[i-1] && p1[i-1]!=p1[i] )
				{
					ans+=p1[i]-p1[i-1];
				}
				else
				{
//					if(p1[i-1]==0)
//					{
//							ans+=max(0,p1[i]-max(p1[i-1],p2[i-1]));
//					}
//					else
//					{
					ans+=max(0,p1[i]-max(p1[i-1],p2[i-1])+1);
				//}
				}
					}
	}
	cout<<ans;
}
