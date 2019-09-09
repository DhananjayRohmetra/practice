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
	int d=0,i,n,b;
cin>>b>>n;
int arr[n+3];
for(i=0;i<n;i++)
{
	cin>>arr[i];
}
if(b%2==0)
{
	if(arr[n-1]%2==0)
	{
		cout<<"even";
	}
	else
	{
		cout<<"odd";
	}
}
else
{
for(i=0;i<n;i++)
{
if(arr[i]%2!=0)
{
	d++;
	}	
}
if(d%2==0)
{
	cout<<"even";
	}	
	else
	{
		cout<<"odd";
	}
	
	
	
	
}
	return 0;
}

