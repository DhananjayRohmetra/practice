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
	int n,x,s=0,i,index;
	int arr[2000001],visited[2000001];
	memset(arr, 0 ,sizeof(arr));
	memset(visited, 0 ,sizeof(visited));
	string str;
	cin>>n>>x;
	cin>>str;
	visited[x+1000100]=1;
	index=x+1000100;
	for(i=0;i<str.length();i++)
	{
		if(str[i]=='L')
		{
			index--;
			visited[index]=1;
			cout<<"hekko";
		}
		
		if(str[i]=='R')
		{
			index++;
			visited[index]=1;
		}
	}
	for(i=1000000;i<=100200;i++)
	{
		if(visited[i]==1)
		{
			s++;
		}
	}
	cout<<s<<"\n";
	
	}
	
}

