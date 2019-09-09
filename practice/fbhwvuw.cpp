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
//freopen("input.txt", "r", stdin);
	vector<pair<int,int> >vec;
   	ll n,cnt=0,k,i,index,flag1=0,flag2=0,j;
   	
	   cin>>n>>k;
	   ll mx(0),mn(1000000007);
   	ll arr[n+2],brr[n+2];
   	set<ll>set1;
   	for(i=0;i<n;i++)
   	{
	   cin>>arr[i];
	   set1.insert(arr[i]);
	}
	if(set1.size()<=k)
	{
		cout<<"0";
	}
	else
	{
		for(i=n-1;i>=1;i--)
		{
			if(arr[i]!=arr[i-1])
			{
				cnt++;
				vec.pb(mp(arr[i]-arr[i-1],i-1));
			}
		}
		sort(vec.begin(),vec.end());
		for(i=0;i<vec.size();i++)
		{
			cout<<vec[i].first<<" "<<vec[i].second<<"\n";
		}
		int cnt=0,ans=0;
		for(i=0;i<vec.size();i++)
		{
//			if(i==vec[cnt].second && vec[cnt].second!=vec[cnt].second)
//			{
//			cnt++;
//			ans+=(mx-mn);
//			 mx=0;
//			 mn=1000000007;	
//			 if(cnt==k-1)
//			 {
//			 	break;
//			}		
//			}
//			else
//			{
//			mx=max(mx,arr[i]);
//			mn=min(mn,arr[i]);
//			}
		brr[cnt]=vec[cnt].second;
		}
		sort
		

		//cout<<ans;
	}
	}
 
 
