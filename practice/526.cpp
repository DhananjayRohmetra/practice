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
ll i,n,k,s=0;
cin>>n>>k;
ll arr[n+2];
for(i=0;i<n;i++)
{
	cin>>arr[i];
	s+=arr[i];
}
if(s<k)
{
	cout<<"-1";
}
else if(s==k)
{
	cout<<"0";
}
else
{
	ll ss=0;
	sort(arr,arr+n);
	for(i=1;i<n;i++)
	{
		ss+=arr[i]-arr[0];
	}
	if(ss>=k)
	{
		cout<<arr[0];
	}
	else
	{
		k=k-ss;
		if(k%n==0)
		{
			cout<<arr[0]-k/n;
		}
		else
		{
			cout<<arr[0]-k/n-1;
		}
	}
}
}
 
