#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
map<pair<int,int>,set<long long >>slope_map;
int main()
{
ll a,b,c,n,i,x[1010],y[1010],j,res=0,x1,x2,y1,y2,total=0;
cin>>n;
for(i=1;i<=n;i++)
{
	cin>>x[i]>>y[i]; 
}
for(i=1;i<=n-1;i++)
{
	for(j=i+1;j<=n;j++)
	{
	x1=x[i];
	y1=y[i];
	x2=x[j];
	y2=y[j];
		b=x1-x2;
		a=y1-y2;
		c=a*x1-b*y1;
		a=a/(__gcd(a,b));
		b=b/(__gcd(a,b));
	
		pair<int ,int >slope(a,b);
		if(!slope_map[slope].count(c))
		{
			++total;
			slope_map[slope].insert(c);
			res+=total-slope_map[slope].size();
		}
	}
	
}
cout<<res;
}
