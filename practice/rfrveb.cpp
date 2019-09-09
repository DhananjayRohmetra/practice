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
ll n,m,k,i,shift=0,op=0,shift2=0;
cin>>n>>m>>k;
ll arr[m+1],pg[m+1];
for(i=0;i<m;i++)
cin>>arr[i];
 
for(i=0;i<m;i++)
{
	if(arr[i]%k==0)
	{
		pg[i]=arr[i]/k;
	}
	else
	{
		pg[i]=arr[i]/k+1;
	}
}
ll rem,vis[m+2];
memset(vis,0,sizeof(vis));
for(i=0;i<m;i++)
{
	if(vis[i]==0)
	{
	if(i==0)
	{
		 rem=pg[i];
		 shift++;
		 op++;
	}
	else
	{
		if((arr[i]-shift2)%k==0)
		{
			pg[i]=(arr[i]-shift2)/k;
		}
		else
		{
			pg[i]=(arr[i]-shift2)/k+1;
		}
		if(pg[i]==rem)
		{
			vis[i]=1;
			shift++;
			
		}
		else
		{
		op++;
		shift2=shift;
		if((arr[i]-shift2)%k==0)
		{
			pg[i]=(arr[i]-shift2)/k;
		}
		else
		{
			pg[i]=(arr[i]-shift2)/k+1;
		}
		rem=pg[i];
		shift++;
		vis[i]=1;
		}
	}
	
	}
}
cout<<op;
}
 
