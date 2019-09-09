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
	int n,s,arr[600],i,j,k,ans;
	cin>>n>>s;
	
	for(i=1;i<=n;i++)
	arr[i]=i;
	
	for(i=1;i<=n-1;i++)
	{
		for(j=i;j<=n-1;j++)
		{
			ans=1;
			for(k=2;k<=i;k++)
			{
				ans-=k;
			}
			for(k=i+1;k<=j;k++)
			{
				ans+=k;
			}
			for(k=j+1;k<=n;k++)
			{
				if(k==j+1)
				{
					ans-=arr[k];
				}
				else
				{
					ans+=arr[k];
				}
			}
		if(ans==s)
		{
			ans=1;
			cout<<ans;
			for(k=2;k<=i;k++)
			{
				cout<<"-"<<k;
				ans-=k;
			}
			for(k=i+1;k<=j;k++)
			{
				cout<<"+"<<k;
				ans+=k;
			}
			for(k=j+1;k<=n;k++)
			{
				if(k==j+1)
				{
					cout<<"-"<<k;
					ans-=arr[k];
				}
				else
				{
					cout<<"+"<<k;
					ans+=arr[k];
				}
			}
			return 0;	
		}
		
		
		}
	}
	
	
	
	for(i=1;i<=n-1;i++)
	{
		for(j=n-i+1;j>=2;j--)
		{
			ans=1;
			for(k=n;k>=n-i+2;k--)
			{
				ans-=k;
			}
			for(k=n-i+1;k>=j+1;k--)
			{
				ans+=k;
			}
			for(k=j;k>=2;k--)
			{
				if(k==j)
				{
					ans-=arr[k];
				}
				else
				{
					ans+=arr[k];
				}
			}
		if(ans==s)
		{
			string str;
			ans=1;
			
			for(k=n;k>=n-i+2;k--)
			{
				str=str+to_string(k)+'-';
				ans-=k;
			}
			for(k=n-i+1;k>=j+1;k--)
			{
				str=str+to_string(k)+'+';
				ans+=k;
			}
			for(k=j;k>=2;k--)
			{
				if(k==j)
				{
					str=str+to_string(k)+'-';
					ans-=arr[k];
				}
				else
				{
					str=str+to_string(k)+'+';
					ans+=arr[k];
				}
			}
str=str+to_string(1);
			reverse(str.begin(),str.end());

			cout<<str;	
return 0;
		}
		}
	}
if(s==(n*(n+1))/2)
{
cout<<"1";
for(i=2;i<=n;i++)
{
cout<<"+"<<i;}
return 0;
}
	cout<<"Impossible";
}



