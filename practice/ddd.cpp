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
	
   		int n;
   		cin>>n;
   		int brr[n+1],arr[n+1],cnt=0,ans=-1,i,diff1,cnt2=0,cnt3=0,cnti=0;
   		for(i=0;i<n;i++) 
		   {
		   	cin>>brr[i];
		   	arr[i]=brr[i];
			}
		sort(arr,arr+n);
		diff1=arr[1]-arr[0];
		for(i=0;i<n-1;i++)
		{
			if(arr[i+1]-arr[i]==diff1)
			{
				cnt++;
			}
			if(cnt==n-2 && i==n-2 && arr[n-1]-arr[n-2]!=diff1)
			{
				ans=n;
			}
			else if(arr[i+1]-arr[i]!=diff1 && arr[i+1]-arr[i]<diff1)
			{
				if(arr[i+2]-arr[i]==diff1)
				{
					ans=i+2;
					cnti++;
				if(cnti>=2)
				 ans=-1;
				}
				else if(arr[i+2]-arr[i]<diff1)
				{
					ans=-1;
					break;
				}
			
			}
		}
	
		if(cnt==n-1)
		{
			ans=1;
		}
		
		if(cnt<=n-3)
		{
			diff1=arr[2]-arr[0];
			cnt3=0;
			for(i=2;i<n-1;i++)
			{
			if(arr[i+1]-arr[i]==diff1)
			{
			cnt3++;	
			}	
			}
			if(cnt3==n-3) 
			ans=2;	
			
			
			diff1=arr[2]-arr[1];
			cnt3=0;
			for(i=1;i<n-1;i++)
			{
			if(arr[i+1]-arr[i]==diff1)
			{
			cnt3++;	
			}	
			}
			
			if(cnt3==n-2)
			 ans=1;	
			
		}
		int ajns=-1;
		for(i=0;i<n;i++)
		{
			if(brr[i]==arr[ans-1])
			{
				 ajns=i+1;
			}
		}
		
		cout<<ajns<<"\n";
	
}
/*
9
1 2 3 4 5 5 5 6 7
*/
