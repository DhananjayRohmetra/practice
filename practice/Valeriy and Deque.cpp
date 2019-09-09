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
	ll i,n,q,x;
	cin>>n>>q;
	ll arr[n+1],maxx[n+1],another[n+1];
	deque<ll> mydeque;
	for(i=0;i<n;i++)
	{
   		cin>>arr[i];
   		 mydeque.push_back(arr[i]);
   		if(i>0)
   		{
   		maxx[i]=max(maxx[i-1],arr[i]);
   		}
   		if(i==0)
   		{
   		maxx[i]=arr[i];	
		}
	}
	for(i=1;i<n;i++)
	{
		another[i-1]=arr[i];
	}
	for(i=0;i<n-1;i++)
	{
	ll first=mydeque.front();
	mydeque.pop_front();
	ll second=mydeque.front();
	mydeque.pop_front();
	if(first>second)
	{
		mydeque.push_back(second);
		mydeque.push_front(first);
	}
	else
	{
		mydeque.push_back(first);
		mydeque.push_front(second);
	}
	
	}
	mydeque.pop_front();
	ll cnt=0;
	ll see[n+1];
	while(!mydeque.empty())
	{
		see[cnt]=mydeque.front();
		mydeque.pop_front();
		cnt++;
	}
	while(q--)
	{
		cin>>x;
		if(x<n)
		{
			cout<<maxx[x-1]<<" "<<arr[x];
		}
		else
		{
		cout<<maxx[n-1]<<" ";
		if(maxx[0]==maxx[n-1])
		{
		cout<<another[(x-1)%(n-1)];	
		}
		else
		{
			if(x==n)
			{
				cout<<see[0];
			}
			else
			{
			cout<<see[(x-n)%(n-1)];
			}
		}	
		}
		cout<<"\n";
	}
}



