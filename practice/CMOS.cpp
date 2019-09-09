#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll i,b=0,a=0,flag=0;
	char str[1000009];
	cin>>str;
	ll arr[1000009],n,ans=0;
	n=strlen(str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='a')
		{
			arr[i]=0;
		}
		if(str[i]=='b')
		{
			arr[i]=1;
		}
		
	}
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]==1)
		{
			b++;
			flag=1;
		}
		if(arr[i]==0 && flag==1 || arr[i+1]==0)
		{
			ans+=b;
			b=2*b;
			flag=0;
		}
	}
	cout<<ans;
	
}
