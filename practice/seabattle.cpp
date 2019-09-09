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
	ll w1,h1,w2,h2,ans=0;
	cin>>w1>>h1>>w2>>h2;
	if(w1==w2)
	{
		ans+=2*w1;
		ans+=2*(h1+h2);
		ans+=4;
	}
	else
	{
		if(w1>w2)
		{
			ans+=2*(h1)+w1+2;
			ans+=2*h2+w2+2+(w1-w2);
		}
		if(w2>w1)
		{
			ans+=2*(h2)+w2+2;
			ans+=2*h1+w1+2+(w2-w1);
		}
	}
	cout<<ans;
	return 0;
}

