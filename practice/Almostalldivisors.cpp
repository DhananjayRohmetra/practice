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
ll p[100009][19],l[100009],mm[100009],prime[1000000],cnt=0,pprime[1000000];
vector< vector<ll> >adj;
void dfs(ll s,ll par)
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
ll getlca(ll pp,ll qq)
{
	if(l[pp]<l[qq])
{
	swap(pp,qq);
}

ll k,i;
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
void sieve()
{
	memset(prime,0,sizeof(prime));
	for(ll i=2;i*i<=1000000;i++)
	{
		if(prime[i]==0)
		{

		for(ll j=i*i;j<=1000000;j+=i)
		{
		prime[j]=i;
		}
		}
	}

	for(ll i=2;i<=1000000;i++)
	if(prime[i]==0)
	{
		pprime[cnt]=i;
		cnt++;
	}
}
int main()
{
ll t;
cin>>t;
sieve();
while(t--)
{

ll n,i;
cin>>n;
ll arr[n+1],brr[n+1];
for(i=1;i<=n;i++){
cin>>arr[i];

	brr[i]=arr[i];
}

sort(arr+1,arr+n+1);
ll ans=0;
ll xx=arr[n];
ll yy=arr[1];
for(i=1;i*i<=arr[n];i++)
{
	if(arr[n]%i==0)
	{
		if(arr[n]/i==i)
		{
			ans+=1;
		}
		else
		{
			ans+=2;
		}
	}
}

ans-=1;
ll x;
for(i=0;i<cnt;i++)
{
	if(arr[1]%pprime[i]==0)
	{
		x=pprime[i];
		break;
	}
}

while(arr[n]%x==0)
{
	arr[n]/=x;
}
//cout<<arr[n];

ll anss=0;

for(i=1;i*i<=arr[n];i++)
{
	if(arr[n]%i==0)
	{
		if(arr[n]/i==i)
		{
			anss+=1;
		}
		else
		{
			anss+=2;
		}
	}
}

if(ans+anss-1==n)
{

	for(i=1;i<=n;i++)
	{

		if((yy*xx)%brr[i]!=0 || prime[yy]!=0)
		{
		break;
		}
	}
	if(i==n+1)
	cout<<yy*xx<<"\n";
	else
	{
		cout<<"-1\n";
	}
}
else
{
	cout<<"-1\n";
}
}
}
