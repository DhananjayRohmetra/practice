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
	int a,b,c;
	cin>>a>>b>>c;
	if((b*b-4*a*c)<0)
	{
		cout<<"0\n";
	}
	else if((b*b-4*a*c)==0)
	{
		cout<<"1\n";
	}
	else if((b*b-4*a*c)>0)
	{
		cout<<"2\n";
	}

	}
	
}


