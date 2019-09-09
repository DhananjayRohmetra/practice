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
bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
  
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	ll n,index1,index2,i,flag1=0,flag2=0,maxi=0,ans=0,ii,jj=0;
	cin>>n;
	ll arr[n+1];
	vector<pair<ll ,ll> >vec(n);
	for(i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>maxi)
		{
			maxi=arr[i];
			ii=i;
		}
		if(maxi==arr[i])
		{
			jj++;
		}
	}
//	for(i=0;i<n;i++)
//	{
//		vec[i].first=1000000009;
//	}
	for(i=0;i<n;i++)
	{
		vec[i].first=__gcd(arr[i],arr[0]);
		vec[i].second=arr[i];	
	}	
	sort(vec.begin(),vec.end(),sortinrev);
	ll prefix[n+1];
	 prefix[0]=vec[0].second;
	for(i=1;i<n;i++)
	{
		prefix[i]=__gcd(prefix[i-1],vec[i].second);
	}
	ll uu=vec[n-1].second;
	for(i=n-1;i>=1;i--)
	{
		uu=__gcd(uu,vec[i].second);
		ans=max(ans,prefix[i-1]+uu);
	}
	//for(i=0;i<n;i++) cout<<vec[i].second<<"\n";
	sort(arr,arr+n);
	for(i=1;i<n;i++)
	{
		if(__gcd(arr[i],arr[0])==1)
		{
			index1=i;
			flag1=1;
			break;
		}	
	}
	if(flag1==1){
	for(i=1;i<n;i++)
	{
		if(i!=index1 && __gcd(arr[index1],arr[i])==1 && __gcd(arr[0],arr[i])==1)
		{
			index2=i;
			flag2=1;
			break;
		}
	}
	}
	ll xx=arr[0];
		for(i=0;i<n-1;i++)
		{
			if(arr[i]!=maxi)
			{
			xx=__gcd(xx,arr[i]);
			}
		}
		ans=max(xx+maxi,ans);
	if(flag1==1 && flag2==0)
	{
		ll g=arr[index1];
		ll g2=arr[0];
		for(i=0;i<n;i++)
		{
			if(__gcd(arr[i],arr[index1])!=1)
			{
			g=__gcd(g,arr[i]);	
			}
			else
			{
				g2=__gcd(g2,arr[i]);
			}
		}
		ans=max(ans,g2+g);
		
		
		
		g=arr[index1];
		g2=arr[0];
		for(i=0;i<n;i++)
		{
			
			if(__gcd(arr[i],arr[0])!=1)
			{
				g2=__gcd(g2,arr[i]);
			}
			else
			{
			g=__gcd(g,arr[i]);	
			}
		}
		ans=max(ans,g2+g);
	
	}
	ll o=arr[0];
	ll cnt=0,y;
	for(i=0;i<n;i++)
	{
		if(arr[i]%o==0)
		{
			cnt++;
		}
		else
		{
			 y=arr[i];
		}
	}
	ll cnt2=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]%y==0)
		{
			cnt2++;
		}
		
	}
	if(cnt+cnt2==n)
	{
		ans=max(ans,y+arr[0]);
	}
	if(jj!=n)
	{
	cout<<ans<<"\n";
	}
	else
	{
		cout<<2*maxi<<"\n";
	}
	}
}



