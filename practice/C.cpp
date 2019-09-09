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

int main()
{
	ll n,i;
	ll sum=0;
cin>>n;
ll arr[n+2];
for(i=0;i<n;i++)
{
	cin>>arr[i];
}
sort(arr,arr+n);
for(i=0;i<n/2;i++)
{
	sum+=(arr[i]+arr[n-i-1])*(arr[i]+arr[n-i-1]);
}
cout<<sum;


	return 0;
}

