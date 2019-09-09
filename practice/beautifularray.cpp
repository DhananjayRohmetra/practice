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
ll n,x,right,i,maxsum,sum,left;
cin>>n>>x;
ll arr[n+2];
memset(arr,0,sizeof(arr));
for(i=0;i<n;i++) cin>>arr[i];
if(x>0)
{
	maxsum=0;
	sum=0;
	left=right=n;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum<0)
		{
			sum=0;
		}
		else
		{
			if(sum>maxsum)
			{
				maxsum=sum;
				right=i;
				
			}
		}
	}	
	//cout<<right;
	
	
	maxsum=0;
	sum=0;
	for(i=n-1;i>=0;i--)
	{
		sum+=arr[i];
		if(sum<0)
		{
			sum=0;
		}
		else
		{
			if(sum>maxsum)
			{
				maxsum=sum;
				left=i;	
			}
		}
	}
	//cout<<left;
	for(i=left;i<=right;i++)
	{
		arr[i]=arr[i]*x;
	}
	
	maxsum=0;
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum<0)
		{
			sum=0;
		}
		else
		{
			if(sum>maxsum)
			{
				maxsum=sum;
			}
		}
	}	
	cout<<maxsum;
	
}
else
{

	maxsum=0;
	sum=0;
	left=right=n;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum>0)
		{
			sum=0;
		}
		else
		{
			if(sum<maxsum)
			{
				maxsum=sum;
				right=i;
			
				
			}
		}
	}	
//	cout<<right<<"\n";
	
	
	maxsum=0;
	sum=0;
	for(i=n-1;i>=0;i--)
	{
		sum+=arr[i];
		if(sum>0)
		{
			sum=0;
		}
		else
		{
			if(sum<maxsum)
			{
				maxsum=sum;
				left=i;	
			}
		}
	}
	//cout<<left<<" "<<right<<"\n";
	for(i=left;i<=right;i++)
	{
		arr[i]=arr[i]*x;
	}
	
	maxsum=0;
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum<0)
		{
			sum=0;
		}
		else
		{
			if(sum>maxsum)
			{
				maxsum=sum;
			}
		}
	}	
	cout<<maxsum;
	

}




}


