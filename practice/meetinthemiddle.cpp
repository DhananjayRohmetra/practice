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

// 9175048
	ll arr[50];
ll x[9175048],y[9175048];
void calculate(ll arr[],ll x[],ll n,ll c,ll mod)
{
	ll s,cnt=0;
	for(ll i=0;i<(1<<n);i++)
	{
		s=0;
		for(ll j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				s=(s%mod+arr[j+c]%mod)%mod;
			}
		}
	//	cout<<s<<" ";
	cnt++;
		x[i]=s%mod;
	}
}
int main()
{

	ll n,i,j,ans=-1,s;
	cin>>n>>s;
	
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		arr[i]%=s;
	}
	calculate(arr,x,n/2,0,s);
	calculate(arr,y,n-n/2,n/2,s);
	ll f=1<<(n-n/2);
		sort(y,y+f);
		for(i=0;i<(1<<(n/2));i++)
		{
		if(x[i]<s)
		{
			ll p = lower_bound(y, y+f, s-x[i]) - y;
		
			 	ans=max(ans,x[i]+y[p-1]);
			 
		}
		}
		cout<<ans;
/*		6  42
		45 34 4  12 5 2*/
}



