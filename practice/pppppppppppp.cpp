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
int p[100009][19],l[100009],mm[100009],prime[1000000],cnt=0,pprime[1000000];;
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
void sieve()
{
	memset(prime,0,sizeof(prime));
	for(ll i=2;i*i<=10000;i++)
	{
		if(prime[i]==0)
		{
		
		for(ll j=i*i;j<=10000;j+=i)
		{
		prime[j]=i;	
		}
		}
	}
	prime[4]=0;
	prime[3125]=0;
	prime[27]=0;
	for(ll i=2;i<=10000;i++)
	if(prime[i]==0)
	{
		pprime[cnt]=i;
		cnt++;
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

sieve();
int ans[10009],i,j;
memset(ans,0,sizeof(ans));
for(i=10000;i>=2;i--)
{
	for(j=i;j<=10000;j+=i)
	{
		if(prime[j]!=0 && ans[j]==0 && j%i==0 && j!=i && prime[i]==0)
		{
			ans[j]=i;
		}
	
	}
}
int t;
cin>>t;
while(t--)
{
	int x;
	cin>>x;
	
	if(x%2==0 && prime[x]!=0) cout<<"2\n";
	else if( prime[x]!=0 && x%2!=0)
	{
		if(x<27 && x>5)
		{
			
			if(!prime[x-2] || prime[x-4]==0) cout<<"2\n";
			else cout<<"3\n";
		}
		else if(x<3125 && x>27)
		{
			
				if(prime[x-2]==0 || !prime[x-4] || !prime[x-27]) cout<<"2\n";
				else cout<<"3\n";
		}
		else
		{
				if(!prime[x-2] || !prime[x-4] || !prime[x-27] || !prime[x-3125]) cout<<"2\n";
				else cout<<"3\n";	
		}
		
	}
	else
	{
		cout<<"1\n";
	}
}

	
}


