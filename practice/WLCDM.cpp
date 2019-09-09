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
	int n,k,rank=1,r=0,i,neut;
	cin>>n>>k;
	int a[n+2],d[n+2];
	vector<int>vec[n+2];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	neut=a[0];
	for(i=0;i<n;i++)
	{
		cin>>d[i];
	}
	for(i=1;i<n;i++)
	{
		if(a[i]-d[i]<neut && a[i]>neut)
		{
			r++;
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i]-d[i]>neut )
		{
			rank++;
		}
	}
	if(r>=k)
	{
		rank=rank+max(r-k,0);
	}
	cout<<rank;
	return 0;
}

