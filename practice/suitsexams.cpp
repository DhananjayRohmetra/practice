#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector< vll >
#define write(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define read(v) for(int i=0;i<v.size();i++)cin>>v[i];
#define write1(v) for(int i=1;i<v.size();i++)cout<<v[i]<<" ";
#define read1(v) for(int i=1;i<v.size();i++)cin>>v[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
ll arr[1000001],n;
ll func(ll k)
{
	ll s=0;
	for(ll i=0;i<n;i++)
	{
		s+=(arr[i]/k);
	}
	return s;
}
int main()
{
	ll k,i;
	cin>>n>>k;

	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll start=1;
	ll end=1e18;
	ll mid;
	ll ans=-1;
	while(start<=end)
	{
		cout<<start<<" "<<mid<<"\n";
		mid=start+(end-start)/2;
		if(func(mid)>=k)
		{
			end=mid-1;
			ans=max(ans,mid);
		}
		else
		{
			start=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

