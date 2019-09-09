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
multiset< ll>s;
multiset<ll> :: iterator it;
int n,x;
cin>>n;
int arr[n+1];
for(int i=0;i<n;i++)
{
	cin>>arr[i];
	s.insert(arr[i]);
	it = s.find(arr[i]);
	it++;
	if(it!=s.end())
	{
		s.erase(it);
	}
}

cout<<s.size();

}

