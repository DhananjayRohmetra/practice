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
	int t;
	cin>>t;
	while(t--)
	{
   	int n,i,k,x,y,hh,ans,anss,sum=0,humans=0,altans=0,newans=0,shit=0;
   	cin>>n;
   	int arr[n+1];
   	int visited[n+2],visited2[n+2];
	memset(visited,0,sizeof(visited));
	memset(visited2,0,sizeof(visited2));
   	vector<pair<int ,int> >brr,decr,incr;
   	for(i=0;i<n;i++) 
	   	{
	   		cin>>y;
	   		sum+=y;
	   		arr[i]=y;
	   		brr.pb(mp(y,i));
		}
   	cin>>k;
   	cin>>x;
   	int sz=0;
   	for(i=0;i<n;i++)
   	{
   		decr.pb(mp(brr[i].first-(brr[i].first^x),i));
   		shit+=(brr[i].first^x);
   		if((brr[i].first^x)>brr[i].first)
		{
			sz++;
			visited2[i]=1;
			humans+=(brr[i].first^x);
			altans+=(brr[i].first^x);
			
		}	
		if((brr[i].first^x)<=brr[i].first)
		{
			humans+=brr[i].first;
		}
	}
	sort(decr.begin(),decr.end());
	sort(incr.begin(),incr.end());
	if(k%2==1)
	{
	anss=humans;
	}
	else
	{
	if(sz%2==0)
	{
	anss=humans;
	}
	if(sz%2==1)
	{
		
		for(i=0;i<sz-1;i++)
		{
			visited[decr[i].second]=1;
			newans+=(arr[decr[i].second]^x);
		}
		
		for(i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				newans+=arr[i];
			}
		}
		if(incr.size()>0)
		{
			visited2[decr[sz].second]=1;
			altans+=(arr[decr[sz].second]^x);
		}
		for(i=0;i<n;i++)
		{
			
			if(visited2[i]==0)
			{
				altans+=arr[i];
			}
		}
		if(incr.size()>0)
		{
		anss=max(altans,newans);	
		}
		else
		{
			anss=newans;
		}
		
	}
	}
	if(k!=n){
	cout<<max(anss,sum)<<"\n";}
	else
	{
		cout<<max(shit,sum)<<"\n";
	}
	}
}



