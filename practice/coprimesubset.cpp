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

int i,dp[109][32770],arr[109],n,prime[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int solve(int index,int mask)
{
	if(mask==1<<n-1 || index==n) return 0;
	if(dp[index][mask]!=-1) return dp[index][mask];
	int q=solve(index+1,mask);
	if(arr[index]==1) return dp[index][mask]=q+1;
	int temp=mask;
	for(i=0;i<15;i++)
		if(arr[index]%prime[i]==0)
		{
			if(mask&(1<<i)) return dp[index][temp]=q;
			mask=mask|(1<<i);
		}
	
	return dp[index][temps]=max(1+solve(index+1,mask),q);

}
int main()
{
int t;
cin>>t;
while(t--)
{
cin>>n;
for(i=0;i<n;i++)
cin>>arr[i];
memset(dp,-1,sizeof(dp));
cout<<solve(0,0);	
}
}


