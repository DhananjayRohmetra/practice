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

int t;
cin>>t;
while(t--)
{
	string s;
	int n,index1,index2,ans=1e9+7;
	cin>>n;
	cin>>s;

	for(int i=0;i<n;i++)
	{
		if(s[i]=='>')
		{
			index1=i;
			break;
		}	
	}
	
	ans=min(index1,n-index1);
	
		for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='<')
		{
			index2=i;
			break;
		}	
	}
	ans=min(ans,min(index2+1,n-index2-1));
	if(s[n-1]=='<')
	{
		ans=0;
	}
	if(s[0]=='>')
	{
		ans=0;
	}
	
	cout<<ans<<"\n";
	
}

}

