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
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,s=0;
	cin>>n;
	int freq[2097152],arr[100009],prefixx[2097152],fvisited[2097152],lvisited[2097152];
	memset(fvisited,-1,sizeof(fvisited));
	memset(lvisited,-1,sizeof(lvisited));
	memset(freq,0,sizeof(freq));
	memset(prefixx,0,sizeof(prefixx));
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	prefixx[0]=arr[0];
	fvisited[0]=0;
	for(i=0;i<n;i++)
	{
		if(i)
		{
			prefixx[i]=prefixx[i-1]^arr[i];
		}
		if(fvisited[prefixx[i]]==-1)
		{
			fvisited[prefixx[i]]=i;
		}
		
	}
	
	for(i=n-1;i>=0;i--)
	{
		if(lvisited[prefixx[i]]==-1)
		{
			lvisited[prefixx[i]]=i;
		}
		
	}
	
	for(i=0;i<=2097152;i++)
	{
		if(lvisited[prefixx[i]]!=fvisited[prefixx[i]])
		{
			s+=(lvisited[prefixx[i]]-fvisited[prefixx[i]]);
		}	
	}
	cout<<s<<"\n";
	}
}


