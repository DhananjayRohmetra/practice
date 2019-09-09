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
vector< pair< int , int > >vec;
int main()
{
int j,n,m,i,maxx=-1000009,minn=1000009,l,r,f=0,flag=0,k;
cin>>n>>m;
ll arr[n+2];
for(i=1;i<=n;i++)
{

cin>>arr[i];
if(arr[i]>maxx)
{
	maxx=arr[i];
}
if(arr[i]<minn)
{
	minn=arr[i];
}
}

for(j=0;j<m;j++)
{
	cin>>l>>r;
vec.push_back(make_pair(l,r));	
}
for(i=1;i<=n;i++)
{
maxx=arr[i];
for(j=0;j<m;j++)
{
	l=vec[j].first;
	r=vec[j].second;
	for(k=1;k<=n;k++)
	{
		if(l>i)
		{
			
			if(r<i || i<l)
			{
				f++;
				flag=1;
			}
		}
	}
//		if(arr[i]==min)
//		{
//			if(l>i)
//			{
//				
//			}
//		}
	
	if(flag==1)
	{
		for(i=l;i<=r;i++)
		{
			arr[i]--;
		}
		flag=0;
	}
	
	for(i=0;i<n;i++)
	{
	if(arr[i]>maxx)
{
	maxx=arr[i];
}
if(arr[i]<minn)
{
	minn=arr[i];
}
	}
}
}
cout<<minn<<" "<<maxx;

}

