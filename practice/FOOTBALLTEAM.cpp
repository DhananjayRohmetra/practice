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
 vector<ll>vec;
 ll n;
ll func(ll mid)
{
	ll less=lower_bound(vec.begin(),vec.end(),mid)-vec.begin();
	ll more=upper_bound(vec.begin(),vec.end(),mid)-vec.begin();
	if(less>n-more) return -1;
	else if(less==n-more) return 0;
	else 
	return 1;
}
int main()
{
	ll i,x,y,z,flag=0;
	cin>>n;
	
	for(i=0;i<n;i++){
	cin>>x>>y>>z;
	vec.pb(x);
	}
	ll low=-1000000000,mid;
	ll high=1000000000;
	sort(vec.begin(),vec.end());
	while(high-low>=3)
	{
		 mid=(low+high)/2;
		
	 	if(func(mid)==1)
		{
			
			low=mid;
			
		}
		else
		{
			high=mid;
		}
	}
	
	if(func(low)==0) 
	{
	cout<<"YES\n"<<low;
	return 0;}
	if(func(low+1)==0) 
	{
	cout<<"YES\n"<<low+1;
	return 0;}
	if(func(high)==0) 
	{
	cout<<"YES\n"<<high;
	return 0;}
	
	cout<<"NO";
	}
	



