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

int main()
{
	string s;
	cin>>s;
	ll ss=1,x,i,mod=1e9+7;
	ll len=s.length();
	ll arr[100];
	memset(arr,0,sizeof(arr));
	for(i=0;i<len;i++)
	{
		arr[s[i]-'0']++;
	}
	cout<<arr[1]<<arr[2]<<arr[3]<<"\n";
	ll n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		ss=((ss%mod)*(arr[x]%mod))%mod;
	}
	cout<<ss;
	return 0;
}


