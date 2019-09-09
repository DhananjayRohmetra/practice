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
int x,y,z,a,b,c,s;
cin>>x>>y>>z;
cin>>a>>b>>c;
if(x>a)
{
	cout<<"No";
	return 0;
}
	a=a-x;
	if(a+b>=y)
	{
		s=a+b;
		s=s-y;
	}
	else
	{
		cout<<"No";
		return 0;
	}
	if(s+c>=z)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}

