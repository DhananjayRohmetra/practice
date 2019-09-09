#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define m 1000000007
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
ll arr[1000009];

int main()
{
map<ll,ll>prr,nrr;
ll n,s=0,i,c,max1=-1,max2=-1,max3=-1,h;
cin>>n;
for(i=0;i<n;i++)
{
	cin>>arr[i];
}

sort(arr,arr+n);
h=arr[n-3];
for(i=0;i<n;i++)
{
	if(arr[i]>=0)
	{
		max1=max(max1,arr[i]);
	}
}

for(i=0;i<n;i++)
{
	if(arr[i]>=0 && arr[i]<max1)
	{
		max2=max(max2,arr[i]);
	}
}
for(i=0;i<n;i++)
{
	if(arr[i]>=0 && arr[i]<max2)
	{
		max3=max(max3,arr[i]);
	}
}


for(i=0;i<n;i++)
{
	if(arr[i]>=0)
	{
		prr[arr[i]]=arr[i];
	}
	else
	{
		c=-1*arr[i];
		nrr[c]=c;
	}
}
int d=0,r=0;
for(i=n-1;i>=0;i--)
{
	if(arr[i]>0 && prr[arr[i]]!=nrr[arr[i]])
	{
		
		d++;
		if(d==3)
		{
			r=i;
			break;
		}
	}
}
for(i=0;i<r;i++)
{

	if(arr[i]>=0 && arr[i]<arr[r] )
	{
		c=-1*arr[i];
		if(prr[arr[i]]!=nrr[c] )
		{
			s=(s%m+arr[i]%m)%m;
		}
	}
}

cout<<s;
}

