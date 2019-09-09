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
int p[100009][19],l[100009],mm[100009];
vector< vector<int> >adj;
void dfs(int s,int par)
{
	for(auto  i:adj[s])
	{
		if(i!=par)
		{
			l[i]=1+l[s];
			dfs(i,s);
			p[i][0]=s;


		}
	}
}
int getlca(int pp,int qq)
{
	if(l[pp]<l[qq])
{
	swap(pp,qq);
}

int k,i;
for( k=1;(1<<k)<=l[pp];k++);
k--;

for(i=k;i>=0;i--)
{
	if(l[pp]-(1<<i)>=l[qq])
	{
		pp=p[pp][i];
	}
}

if(pp==qq) return pp;

for(i=k;i>=0;i--)
{
	if(p[pp][i]!=p[qq][i] && pp[p][i]!=-1)
	{
		pp=p[pp][i];
		qq=p[qq][i];
	}
}

return p[pp][0];
}
int main()
{
int t;
cin>>t;
while(t--)
{
	int i,n;
	cin>>n;
	int arr[n+1],brr[n+1],cnt=0;
	map<ll,ll>mpa,mpb;
	vector<pair<ll,ll>>vec;
	for(i=0;i<n;i++)
	{
		cin>>arr[i]>>brr[i];
		vec.pb({arr[i],0});
		cnt++;
		vec.pb({brr[i],0});
		cnt++;
	}
	sort(vec.begin(),vec.end());
	for(i=0;i<2*n;i++)
	{
			mpa[vec[i].first]=i;
	}	
	for(i=0;i<n;i++)
	{
	vec[mpa[arr[i]]].second++;
	vec[mpa[brr[i]]].second--;
	}
	int maxx=vec[0].second;
	int ans=vec[0].first;
	for(i=1;i<2*n;i++)
	{
		vec[i].second+=vec[i-1].second;
		
		if(vec[i].second>maxx)
		{
			maxx=vec[i].second;
			ans=vec[i].first;
		}
	}
	cout<<ans<<"\n";
	
}
}


