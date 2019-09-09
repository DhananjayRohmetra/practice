#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector<vll>
#define write(v)                       \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define read(v)                        \
    for (int i = 0; i < v.size(); i++) \
        cin >> v[i];
#define write1(v)                      \
    for (int i = 1; i < v.size(); i++) \
        cout << v[i] << " ";
#define read1(v)                       \
    for (int i = 1; i < v.size(); i++) \
        cin >> v[i];
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(v) v.begin(), v.end()
int main()
{
ll i,j;
ll dp[10200][12],mod=1000000007;
memset(dp,0,sizeof(dp));
for(i=1;i<=10000;i++)
{
  		dp[i][0]=1;
}
  	
for(j=1;j<=10;j++)
  	{
  	for(i=1;i<=10000;i++)
	  {
      
		if(i<=j)
		{
			dp[i][j]=dp[i][j-1];
		}
		else if(i-j==1)
		{
			dp[i][j]+=1+dp[i][j-1];
		}
		else
		{
			for(int k=i;k>=i-j-1;k--)
			dp[i][j]=(dp[i][j]%mod+dp[k][j]%mod)%mod;
			
		}
	  }	
	}
	int t;
	cin>>t;
	while(t--)
	{
   	ll n,p;
   	cin>>n>>p;
	cout<<dp[n][p-1]<<"\n";
	}
	
	}




