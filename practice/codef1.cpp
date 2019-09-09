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
int n,i,x1,x2,s=0;
cin>>n;
string str;
int arr1[29],arr2[29];
memset(arr1,0,sizeof(arr1));
memset(arr2,0,sizeof(arr2));
for(i=0;i<n;i++)
{
	cin>>str;
	x1=arr1[str[0]-'a'];
	x2=arr2[str[0]-'a'];
	if(x1>=x2)
	{
		//cout<<"arr2\n";
		arr2[str[0]-'a']++;
	}
	if(x1<x2)
	{
	//	cout<<"arr1\n";
		arr1[str[0]-'a']++;
	}
	
}

for(i=0;i<26;i++)
{
	if(arr1[i]>=2)
	{
		s+=(arr1[i]*(arr1[i]-1))/2;
	}
	if(arr2[i]>=2)
	{
		s+=(arr2[i]*(arr2[i]-1))/2;
	}
}
cout<<s;
	return 0;
}


