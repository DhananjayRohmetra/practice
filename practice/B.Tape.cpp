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

ll n,m,k,i,s=0,ans=0,st;
cin>>n>>m>>k;
vector< pair<ll,ll> >vec;
int arr[n+2],brr[n+2],crr[n+2],pref[n+2];
for(i=0;i<n;i++)
{
	cin>>arr[i];
	crr[i]=-1;
}
if(n>1)
{


for(i=0;i<n-1;i++)
{
	vec.push_back({arr[i+1]-arr[i],i});
}
sort(vec.begin(),vec.end());

for(i=n-2;i>=0;i--)
{
	crr[vec[i].second]=1;
	s++;
	if(s==k-1)
	{
		break;
	}
}

	st=0;
	ll flag=-1;
	for(i=0;i<n;i++)
	{
		if(crr[i]==1)
		{
			if(st==0 && flag==-1)
			{
				flag=1;
			}
			if(flag==1){
			
			ans+=(arr[i]-arr[0])+1;
			flag=0;
			st=i;
			}
			else
			{
			ans+=(arr[i]-arr[st+1])+1;	
				st=i;
				
			}
		}
	}

	
	ans+=arr[n-1]-arr[st+1]+1;

	if(k!=1){
	
	cout<<ans;}
	else if(k==1)
	{
cout<<arr[n-1]-arr[0]+1;	
	}
	
}
	else if(n==1)
	cout<<"1";
}
