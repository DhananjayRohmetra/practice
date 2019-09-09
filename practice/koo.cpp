#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
    int l[n+9],r[n+9],ans[n+9],bade,freq[n+9],ans1[n+9],freq1[n+9];
	for(i=0;i<n;i++)
	{
		cin>>l[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>r[i];
	}
	for(i=1;i<=n;i++)
	{
		freq[i]=0;
		freq1[i]=0;
	}
	ans[n-1]=1;
	bade=l[n-1];
	int max1=1;
for(i=n-2;i>=0;i--)
{
	if(bade==0)
	{
		ans[i]=1;
		
	}
		else if(l[i+1]>l[i])
		{
			ans[i]=max1+1;
			max1=max(max1,ans[i]);
			bade--;
		}
		else if(l[i+1]==l[i])
		{
			ans[i]=1;
		}
}
ans1[n-1]=0;
int yes=0;
for(i=n-2;i>=0;i--)
{
if(r[i-1]<r[i])
{
	ans1[i]=l[i-1]-l[i]
}
}
		for(i=0;i<n;i++)
	{
		cout<<ans1[i]<<" ";}
}

