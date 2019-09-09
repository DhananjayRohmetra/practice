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
	string str;
	cin>>str;
	int dp[1000009];
	memset(dp,0,sizeof(dp));
	int anss=0,ans=0,i,len=str.length();
	if(str[0]!=str[1] || str[1]!=str[2])
	{
		dp[0]=3;
	}
	if(str[1]!=str[2] || str[2]!=str[3])
	{
		dp[1]=3;
	}	
	if(str[2]!=str[3] || str[3]!=str[4])
	{
		dp[2]=3;
	}

	for(i=3;i<len-2;i++)
	{
		if(str[i]!=str[i+1] || str[i+1]!=str[i+2])
		{
			dp[i]=3+dp[i-3];
		}
		else
		{
			dp[i]=0;
		}
	}
	
	for(i=0;i<len;i++)
	{
	//	cout<<dp[i]<<"\n";
		anss=max(anss,dp[i]);
	}
	cout<<len-anss<<"\n";
}
}


