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
#define all(v) v.begin(),v.end()
int main()
{

int n,i,right=0,left=0,index=1e9,s=0,r=0;
cin>>n;
int arr[n+1];
for(i=0;i<n;i++)
{
	cin>>arr[i];
}
for(i=0;i<n;i++)
{
	if(arr[i]==0)
	{
		left++;
	}
	else
	{
		right++;
	}
}
for(i=0;i<n;i++)
{
	if(arr[i]==0)
	{
		r++;
		if(r==left)
		{
			index=min(index,i);
			break;
		}
	}
	if(arr[i]==1)
	{
		s++;
		if(s==right)
		{
			index=min(index,i);
			break;
		}
	}
}
cout<<index+1;
	return 0;
}

