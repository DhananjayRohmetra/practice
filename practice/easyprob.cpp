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
ll a,b,c,d;
int main()
{
	fast;
	ll n,i,h;
string s;
cin>>n>>s;
for(i=0;i<n;i++)
{
	cin>>h;
	if(s[i]=='h'){
		a+=h;
	}
	
	if(s[i]=='a'){
		b=min(a,b+h);
	}
	
	if(s[i]=='r'){
	c=min(c+h,b);
	}
	
	if(s[i]=='d'){
	d=min(c,d+h);
		}
}
cout<<d;

	return 0;
}

