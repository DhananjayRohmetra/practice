#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,ans=0;
		cin>>n;
		long long arr[n+1];
		long long i;
		for(i=0;i<n;i++)
		cin>>arr[i];
		
		sort(arr,arr+n);
		ans=0;
		for(i=2;i<n;i++)
		{
			if(arr[i]!=arr[i-1]+__gcd(arr[i-1],arr[i-2]))
			{
				ans=-1;
			}
		}
		if(ans==-1)
		{
			cout<<"-1";
		}
		else
		{
		for(i=0;i<n;i++)
		cout<<arr[i]<<" ";	
		}
		cout<<"\n";
	}
}

