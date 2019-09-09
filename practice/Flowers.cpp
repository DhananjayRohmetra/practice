#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
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
ll dp[100009],prefix[100009];
int main()
{
ll n,k,i,l,r;
cin>>n>>k;

for(i=1;i<=100000;i++)
{
	if(i<k)
	{
		dp[i]=1;
	}
	else if(i==k)
	{
		dp[i]=2;
	}
	else
	{
		dp[i]=dp[i-1]+i/k;
		dp[i]%=m;
	}
}
prefix[0]=0;
 prefix[1]=dp[1];
for(i=2;i<=100000;i++)
{
	prefix[i]=(prefix[i-1]+dp[i]);
	prefix[i]%=m;

}
for(i=0;i<n;i++)
{
	cin>>l>>r;
cout<<(prefix[r]-prefix[l-1]+m)%m<<endl;
}

	return 0;
}

