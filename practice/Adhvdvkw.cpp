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
	int n,i,j,ans;
	cin>>n;
	int arr[n+1];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int freq[12][100009];
	memset(freq,0,sizeof(freq));
	for(i=0;i<n;i++)
	{
		freq[arr[i]][i]++;
	}
	for(j=1;j<=10;j++)
	{
		for(i=1;i<n;i++)
		{
			freq[j][i]+=freq[j][i-1];
		}
	}
	for(i=n-1;i>=0;i--)
	{
			int prev1,prev2=0;
		int flag=0,flag1=0,flag2=0;
		int ppp1=0,ppp2=0;
		for(j=1;j<=10;j++)
		{
			if(freq[j][i]!=0)
			{
				prev1=freq[j][i];
				break;
			}
		}
	
	
		for(j=1;j<=10;j++)
		{
			if(freq[j][i]!=0)
			{
				if(freq[j][i]!=prev1 && flag==0)
				{
					prev2=freq[j][i];
					flag=1;
				}
				if(freq[j][i]==prev1)
				{
					ppp1++;
				}
				if(freq[j][i]==prev2)
				{
					ppp2++;
				}
				if(freq[j][i]!=prev1 && freq[j][i]!=prev2)
				{
					flag1=1;
					break;
				}
			}
		}
	
		if(prev2==0 && flag1==0 && prev1==1)
		{
			
			flag2=1;
			ans=i+1;
			break;
		}
		if(flag1==0)
		{
		
			if( ppp1==1 && (prev1==1 || prev1-prev2==1))
			{
				flag2=1;
				ans=i+1;
				break;
			}
			if(ppp2==1 && (prev2==1 || prev2-prev1==1))
			{
				flag2=1;
				
				ans=i+1;
				break;
			}
			
		}
	}
	cout<<ans;
	
	
	
}


