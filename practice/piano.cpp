#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s;
	cin>>t;
	int rem,i,a[n+2]={0},b[n+2]={0};
	for(i=0;i<n;i++)
	a[i+1]=s[i]-'a';
	
	for(i=0;i<n;i++)
	b[i+1]=t[i]-'a';
	
	for(i=n;i>=0;i--)
	{
		a[i]+=b[i];
		if(i)
		{
			a[i-1]+=a[i]/26;
			a[i]%=26;
		}
	}
	
	for(i=0;i<=n;i++)
	{
		rem=a[i]%2;
		a[i]/=2;
		if(i+1<=n)
		{
			a[i+1]+=26*rem;
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<char(a[i]+97);
	}
}


