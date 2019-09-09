#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll x, ll y);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,i,s1,s2;
		ll arr[29][3];
	cin>>n;	
	arr[1][0]=1;
	arr[1][1]=2;
	arr[2][0]=1;
	arr[2][1]=4;
	for(i=3;i<=25;i++)
	{
		s1=arr[i][0]=(arr[i-2][0]*arr[i-1][1]+arr[i-1][0]*arr[i-2][1]);
		s2=arr[i][1]=2*(arr[i-1][1]*arr[i-2][1]);
		arr[i][0]=(s1)/(__gcd(s1,s2));
		arr[i][1]=(s2)/(__gcd(s1,s2));
	
	}
cout<<arr[5][0]<<" "<<arr[5][1];
	
	}
}





